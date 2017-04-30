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
QJsonValue SwaggerFiller::swagger ( ) const {
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
QJsonValue SwaggerFiller::Info ( ) const {
    return QJsonValue ( );
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
QJsonValue SwaggerFiller::get ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::setGet ( QJsonValue Get ) {
    if ( !Get.isObject ( ) ) {
        _setLastErrorMessage ( "Can't set Get field, input parameter is not a QJsonObject" );
        return;
    }
    Data::GetOperationField *getOperation = new Data::GetOperationField ( );
    connect ( getOperation, &Data::GetOperationField::setParametersDetected,
              this, &SwaggerFiller::_addOperationParameters );
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
        // parameter in body
    }
    if ( _currentOperation->isParameterAlreadyExist ( parameterField ) ) {
        qWarning ( ) << "Can't add parameter" << parameter.value ( "name" ).toString ( )
                     << "to current operation. This operation already has this parameter";
        return;
    }
    _currentOperation->addParameter ( parameterField );
}


} // Core
} // Swagger
