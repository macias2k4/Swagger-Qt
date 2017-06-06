#include "SwaggerFiller.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerFiller::SwaggerFiller ( Data::Swagger &swagger, QObject *parent )
    : QObject   ( parent ),
      _swagger  ( &swagger ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerFiller::~SwaggerFiller ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::fill ( const QString &annotationName, const QJsonValue &annotationContent ) {
    // fill _swagger object fields by received annotationContent
    QString fieldName = _extractFieldNameFromAnnotationName ( annotationName );
    if ( fieldName.isEmpty ( ) ) {
        _setLastErrorMessage ( QString ( "Incorrect annotationName '%1'" ).arg ( annotationName ) );
        return;
    }
    if ( !this->setProperty ( fieldName.toLatin1 ( ).data ( ), annotationContent ) ) {
        _setLastErrorMessage ( QString ( "Can't set value of field '%1'" ).arg ( fieldName  ) );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString SwaggerFiller::_extractFieldNameFromAnnotationName ( const QString &annotationName ) {
    QString annotationPrefix = QString ( "%1." ).arg ( Base::SwaggerFieldBase::AnnotationKeyword );
    if ( !annotationName.startsWith ( annotationPrefix ) ) {
        return QString ( );
    }
    return QString ( annotationName ).remove ( 0, annotationPrefix.length ( ) );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_setLastErrorMessage ( const QString &message ) {
    _lastErrorMessage = message;
    qWarning ( ) << _ModuleName << message;
}


// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonValue SwaggerFiller::emptyJsonObject ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::setSwagger ( QJsonValue swagger ) {
    if ( !swagger.isObject ( ) ) {
        _setLastErrorMessage ( "Can't set Swagger root object input parameter is not a QJsonObject" );
        return;
    }
    if ( _swagger->isFieldAlreadySet ( ) ) {
        _setLastErrorMessage ( "Can't set Swagger root field, it's already set" );
        return;
    }
    _fillSwaggerField ( *_swagger, swagger.toObject ( ) );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_fillSwaggerField ( Base::SwaggerFieldBase &swaggerField,
                                        const QJsonObject &annotationContent ) {
    QStringList keys = annotationContent.keys ( );
    QString fieldName = QString ( );
    for ( QString key : keys ) {
        // extract to sub method !
        fieldName = _extractFieldNameFromAnnotationName ( key );
        QJsonValue value = annotationContent.value ( key );
        if ( fieldName.isEmpty ( ) ) {
            if ( value.isArray ( ) ) {
                QVariantList list = value.toArray ( ).toVariantList ( );
                swaggerField.setProperty ( key.toLatin1 ( ).data ( ), list );
            } else {
                swaggerField.setProperty ( key.toLatin1 ( ).data ( ), value );
            }
        } else {
            if ( swaggerField.property ( fieldName.toLatin1 ( ).data ( ) ).canConvert
                    < Swagger::Base::SwaggerFieldBase * > ( ) ) {
                if ( value.isObject ( ) ) {
                    _fillSwaggerField ( *swaggerField.property ( fieldName.toLatin1 ( ).data ( ) ).value
                                        < Swagger::Base::SwaggerFieldBase * > ( ), value.toObject ( ) );
                } else if ( value.isArray ( ) ) {
                    //                _fillSwaggerField ( property, value.toArray ( ) );
                }
            } else {
                swaggerField.setProperty ( fieldName.toLatin1 ( ).data ( ), value );
            }
        }
    }
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::setInfo ( QJsonValue Info ) {
    if ( !Info.isObject ( ) ) {
        _setLastErrorMessage ( "Can't set Info field, input parameter is not a QJsonObject" );
        return;
    }
    if ( _swagger->info ( )->isFieldAlreadySet ( ) ) {
        _setLastErrorMessage ( "Can't set Info field, it's already set" );
        return;
    }
    _fillSwaggerField ( *_swagger->info ( ), Info.toObject ( ) );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// operations
void SwaggerFiller::setGet ( QJsonValue Get ) {
    if ( !Get.isObject ( ) ) {
        _setLastErrorMessage ( "Can't set Get field, input parameter is not a QJsonObject" );
        return;
    }
    Data::GetOperationField *getOperation = new Data::GetOperationField ( );
    connect ( getOperation, &Data::GetOperationField::setParametersDetected,
              this, &SwaggerFiller::_addOperationParameters );
    connect ( getOperation, &Data::GetOperationField::setResponsesDetected,
              this, &SwaggerFiller::_addOperationResponses );
    _fillSwaggerField ( *getOperation, Get.toObject ( ) );
    if ( _swagger->isOperationAlreadyExist ( getOperation ) ) {
        _setLastErrorMessage ( "Can't add Get operation, it's already exist" );
        delete getOperation;
        return;
    }
    _swagger->addOperation ( getOperation );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addOperationParameters ( QJsonValue parameters ) {
    _currentOperation = reinterpret_cast < Base::OperationFieldBase * > ( sender ( ) );
    if ( !_currentOperation ) {
        qWarning ( ) << "Can't add parameters to operation. Sender is not operation object";
        return;
    }
    if ( !parameters.isArray ( ) ) {
        qWarning ( ) << "Can't add parameters to operation. Parameters input is not an array";
        return;
    }
    for ( QJsonValue parameterValue : parameters.toArray ( ) ) {
        _addOperationParameter ( parameterValue );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addOperationParameter ( const QJsonValue &parameterValue ) {
    if ( !parameterValue.isObject ( ) ) {
        qWarning ( ) << "Can't add parameter to current operation. Parameter input is not an object";
        return;
    }
    QJsonObject parameter = parameterValue.toObject ( );
    QString in = parameter.value ( "in" ).toString ( );
    Base::ParameterFieldBase *parameterField = nullptr;
    if ( in != "body" ) {
        parameterField = new Data::ParameterDefaultField ( );
        _fillSwaggerField ( *parameterField, parameter );
    } else {
        Data::ParameterInBodyField *bodyParameter = new Data::ParameterInBodyField ( );
        parameterField = bodyParameter;
        connect ( bodyParameter, &Data::ParameterInBodyField::setSchemaDetected,
                  this, &SwaggerFiller::_fillSchemaFromJson );
        _fillSwaggerField ( *parameterField, parameter );
    }
    if ( _currentOperation->isParameterAlreadyExist ( parameterField ) ) {
        qWarning ( ) << "Can't add parameter" << parameter.value ( "name" ).toString ( )
                     << "to current operation. This operation already has this parameter";
        return;
    }
    _currentOperation->addParameter ( parameterField );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_fillSchemaFromJson ( Data::SchemaField *schema, QJsonValue schemaValue ) {
    if ( !schema ) {
        qWarning ( ) << "Can't set schema value. Schema object is null";
        return;
    }
    if ( !schemaValue.isObject ( ) ) {
        qWarning ( ) << "Can't set schema value. Json input is not an object";
        return;
    }
    QJsonObject schemaObject = schemaValue.toObject ( );
    connect ( schema, &Data::SchemaField::setPropertiesDetected,
              this, &SwaggerFiller::_addSchemaProperties );
    _fillSwaggerField ( *schema, schemaObject );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addSchemaProperties ( QJsonValue properties ) {
    _currentSchema = reinterpret_cast < Data::SchemaField * > ( sender ( ) );
    if ( !_currentSchema ) {
        qWarning ( ) << "Can't add properties to Schema. Sender is not Schema object";
        return;
    }
    if ( !properties.isObject ( ) ) {
        qWarning ( ) << "Can't add properties to Schema. Properties input is not an object";
        return;
    }
    for ( QString key : properties.toObject ( ).keys ( ) ) {
        _currentSchemaPropertyName = key;
        _addSchemaProperty ( properties.toObject( ).value ( key ) );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addSchemaProperty ( QJsonValue propertyValue ) {
    if ( !propertyValue.isObject ( ) ) {
        qWarning ( ) << "Can't add property to current Schema. Property input is not an object";
        return;
    }
    QJsonObject property = propertyValue.toObject ( );
    Data::PropertyField *propertyField = new Data::PropertyField ( );
    connect ( propertyField, &Data::PropertyField::setItemsDetected,
              this, &SwaggerFiller::_fillItemsFromJson );
    propertyField->setName ( _currentSchemaPropertyName );
    if ( _currentSchema->isPropertyAlreadyExist ( propertyField ) ) {
        qWarning ( ) << "Can't add property" << _currentSchemaPropertyName
                     << "to current Schema. This Schema already has this property";
        return;
    }
    _fillSwaggerField ( *propertyField, property );
    _currentSchema->addProperty ( propertyField );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addOperationResponses ( QJsonValue responses ) {
    _currentOperation = reinterpret_cast < Base::OperationFieldBase * > ( sender ( ) );
    if ( !_currentOperation ) {
        qWarning ( ) << "Can't add responses to operation. Sender is not operation object";
        return;
    }
    if ( !responses.isObject ( ) ) {
        qWarning ( ) << "Can't add responses to operation. Responses input is not an object";
        return;
    }
    QJsonObject responsesObject = responses.toObject ( );
    for ( QString responseKey : responsesObject.keys ( ) ) {
        _addOperationResponse ( responseKey, responsesObject.value ( responseKey ) );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addOperationResponse ( const QString &responseKey,
        const QJsonValue &responseValue ) {
    if ( !responseValue.isObject ( ) ) {
        qWarning ( ) << "Can't add response to current operation. Response input is not an object";
        return;
    }
    QJsonObject response = responseValue.toObject ( );
    Data::ResponseField *responseField = new Data::ResponseField ( );
    responseField->setResponseKey ( responseKey );
    if ( _currentOperation->isResponseAlreadyExist ( responseField ) ) {
        qWarning ( ) << "Can't add response" << responseKey
                     << "to current operation. This operation already has this response";
        return;
    }
    connect ( responseField, &Data::ResponseField::setSchemaDetected,
              this, &SwaggerFiller::_fillSchemaFromJson );
    _fillSwaggerField ( *responseField, response );
    _currentOperation->addResponse ( responseField );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::setPost ( QJsonValue Post ) {
    if ( !Post.isObject ( ) ) {
        _setLastErrorMessage ( "Can't set Post field, input parameter is not a QJsonObject" );
        return;
    }
    Data::PostOperationField *postOperation = new Data::PostOperationField ( );
    connect ( postOperation, &Data::PostOperationField::setParametersDetected,
              this, &SwaggerFiller::_addOperationParameters );
    connect ( postOperation, &Data::PostOperationField::setResponsesDetected,
              this, &SwaggerFiller::_addOperationResponses );
    _fillSwaggerField ( *postOperation, Post.toObject ( ) );
    if ( _swagger->isOperationAlreadyExist ( postOperation ) ) {
        _setLastErrorMessage ( "Can't add Post operation, it's already exist" );
        delete postOperation;
        return;
    }
    _swagger->addOperation ( postOperation );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// definitions
void SwaggerFiller::setDefinition ( QJsonValue Definition ) {
    if ( !Definition.isObject ( ) ) {
        _setLastErrorMessage ( "Can't add new Definition field, input parameter is not a QJsonObject" );
        return;
    }
    Data::DefinitionField *definition = new Data::DefinitionField ( );
    connect ( definition, &Data::DefinitionField::setPropertiesDetected,
              this, &SwaggerFiller::_addDefinitionProperties );
    _fillSwaggerField ( *definition, Definition.toObject ( ) );
    if ( _swagger->isDefinitionAlreadyExist ( definition ) ) {
        _setLastErrorMessage ( "Can't add Definition, it's already exist" );
        delete definition;
        return;
    }
    _swagger->addDefinition ( definition );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addDefinitionProperties ( QJsonValue properties ) {
    _currentDefinition = reinterpret_cast < Data::DefinitionField * > ( sender ( ) );
    if ( !_currentDefinition ) {
        qWarning ( ) << "Can't add properties to definitions. Sender is not definition object";
        return;
    }
    if ( !properties.isObject ( ) ) {
        qWarning ( ) << "Can't add properties to definitions. Properties input is not an object";
        return;
    }
    for ( QString key : properties.toObject ( ).keys ( ) ) {
        _currentDefinitionPropertyName = key;
        _addDefinitionProperty ( properties.toObject().value ( key ) );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_addDefinitionProperty ( QJsonValue propertyValue ) {
    if ( !propertyValue.isObject ( ) ) {
        qWarning ( ) << "Can't add property to current definition. Property input is not an object";
        return;
    }
    QJsonObject property = propertyValue.toObject ( );
    Data::PropertyField *propertyField = new Data::PropertyField ( );
    connect ( propertyField, &Data::PropertyField::setItemsDetected,
              this, &SwaggerFiller::_fillItemsFromJson );
    propertyField->setName ( _currentDefinitionPropertyName );
    if ( _currentDefinition->isPropertyAlreadyExist ( propertyField ) ) {
        qWarning ( ) << "Can't add property" << _currentDefinitionPropertyName
                     << "to current definition. This definition already has this property";
        return;
    }
    _fillSwaggerField ( *propertyField, property );
    _currentDefinition->addProperty ( propertyField );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_fillItemsFromJson ( Data::ItemsField *items, QJsonValue itemsValue ) {
    if ( !items ) {
        qWarning ( ) << "Can't set items parameters value. Items object is null";
        return;
    }
    if ( !itemsValue.isObject ( ) ) {
        qWarning ( ) << "Can't set items parameters value. Json input is not an object";
        return;
    }
    QJsonObject itemsObject = itemsValue.toObject ( );
    _fillSwaggerField ( *items, itemsObject );
}

} // Core
} // Swagger
