#include "SwaggerJsonSerializer.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerJsonSerializer::SwaggerJsonSerializer ( Data::Swagger &swagger, QObject *parent )
    : QObject  ( parent ),
      _swagger ( &swagger ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerJsonSerializer::~SwaggerJsonSerializer ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::serialize ( ) {
    _clearJsonObject ( _swaggerJson );
    _createSwaggerRootJsonObject ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_clearJsonObject ( QJsonObject &object ) {
    QString key;
    for ( int idx = object.keys ( ).size ( ) - 1 ; idx >= 0; idx-- ) {
        key = object.keys ( ).at ( idx );
        object.remove ( key );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_createSwaggerRootJsonObject ( ) {
    _swaggerJson.insert ( "swagger", _swagger->swagger ( ) );
    _addInfoToSwaggerJson ( );
    _swaggerJson.insert ( "host", _swagger->host ( ) );
    _swaggerJson.insert ( "basePath", _swagger->basePath ( ) );
    _addSchemesToSwaggerJson ( );
    _addPathsToSwaggerJson ( );
    _addDefinitionsToSwaggerJson ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addInfoToSwaggerJson ( ) {
    _swaggerJson.insert ( "info", QJsonObject {
        { "title", _swagger->info ( )->title ( ) },
        { "description", _swagger->info ( )->description ( ) },
        { "version", _swagger->info ( )->version ( ) }
    } );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addSchemesToSwaggerJson ( ) {
    QJsonArray schemes;
    for ( QString scheme : _swagger->schemes ( ) ) {
        schemes.append ( scheme );
    }
    _swaggerJson.insert ( "schemes", schemes );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// paths
void SwaggerJsonSerializer::_addPathsToSwaggerJson ( ) {
    _clearJsonObject ( _pathsJson );
    for ( Base::OperationFieldBase *operation : _swagger->operations ( ) ) {
        _currentOperation = operation;
        _addOperationToPathsJson ( );
    }
    _swaggerJson.insert ( "paths", _pathsJson );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addOperationToPathsJson ( ) {
    if ( !_currentOperation ) {
        qWarning ( ) << "Can't add single operation to paths";
        return;
    }
    QJsonValue pathValue = _pathsJson.take ( _currentOperation->path ( ) );
    QJsonObject pathJson = pathValue.toObject ( QJsonObject ( ) );
    QJsonObject operationJson = _createOperationJson ( );
    pathJson.insert ( Base::OperationFieldBase::operationTypeValueToString (
                          _currentOperation->operationType ( ) ).toLower ( ), operationJson );
    _pathsJson.insert ( _currentOperation->path ( ), pathJson );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonObject SwaggerJsonSerializer::_createOperationJson ( ) {
    QJsonObject operationJson {
        { "description", _currentOperation->description ( ) },
        { "summary", _currentOperation->summary ( ) },
        { "operationId", _currentOperation->operationId ( ) }
    };
    _addJsonArrayToJsonObject ( operationJson, "tags", _currentOperation->tags ( ) );
    _addJsonArrayToJsonObject ( operationJson, "consumes", _currentOperation->consumes ( ) );
    _addJsonArrayToJsonObject ( operationJson, "produces", _currentOperation->produces ( ) );
    _addJsonArrayToJsonObject ( operationJson, "schemes", _currentOperation->schemes ( ) );
    _addParametersForCurrentOperation ( operationJson );
    _addResponsesForCurrentOperation ( operationJson );
    return operationJson;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addJsonArrayToJsonObject ( QJsonObject &object, QString inputKey,
        const QStringList &inputValues ) {
    QJsonArray array;
    for ( QString value : inputValues ) {
        array.append ( value );
    }
    object.insert ( inputKey, array );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addParametersForCurrentOperation ( QJsonObject &operationJson ) {
    QJsonArray parameters;
    for ( Base::ParameterFieldBase *parameter : _currentOperation->parameters ( ) ) {
        _currentParameter = parameter;
        _addCurrentParameterToParametersJson ( parameters );
    }
    operationJson.insert ( "parameters", parameters );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addCurrentParameterToParametersJson ( QJsonArray &parameters ) {
    if ( !_currentParameter ) {
        qWarning ( ) << "Can't add single parameter to operation" << QString ( "'%1 %2'" )
                     .arg ( _currentOperation->operationTypeAsString ( ) ).arg (  _currentOperation->path ( ) );
        return;
    }
    QJsonObject parameter {
        { "name", _currentParameter->name ( ) },
        { "in", _currentParameter->in ( ) },
        { "description", _currentParameter->description ( ) },
        { "required", _currentParameter->required ( ) }
    };
    if ( !_currentParameter->in ( ).isEmpty ( ) && ( _currentParameter->in ( ) != "body" ) ) {
        _extendParameterByDefaultParameterProperties ( parameter );
    } else {
        //        _extendParameterByBodyParameterProperties ( parameter );
    }
    parameters.append ( parameter );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_extendParameterByDefaultParameterProperties ( QJsonObject &parameter ) {
    Data::ParameterDefaultField *parameterDefault = reinterpret_cast < Data::ParameterDefaultField * >
            ( _currentParameter );
    if ( !parameterDefault ) {
        qWarning ( ) << "Can't extend json parameter object by default parameter proeprties in operations"
                     << QString ( "'%1 %2'" ).arg ( _currentOperation->operationTypeAsString ( ) )
                     .arg (  _currentOperation->path ( ) );
        return;
    }
    parameter.insert ( "type", parameterDefault->type ( ) );
    parameter.insert ( "format", parameterDefault->format ( ) );
    parameter.insert ( "allowEmptyValue", parameterDefault->allowEmptyValue ( ) );
    // items to add
    parameter.insert ( "collectionFormat", parameterDefault->collectionFormat ( ) );
    parameter.insert ( "maximum", parameterDefault->maximum ( ) );
    parameter.insert ( "exclusiveMaximum", parameterDefault->exclusiveMaximum ( ) );
    parameter.insert ( "minimum", parameterDefault->minimum ( ) );
    parameter.insert ( "exclusiveMinimum", parameterDefault->exclusiveMinimum ( ) );
    parameter.insert ( "maxLength", parameterDefault->maxLength ( ) );
    parameter.insert ( "minLength", parameterDefault->minLength ( ) );
    parameter.insert ( "pattern", parameterDefault->pattern ( ) );
    parameter.insert ( "maxItems", parameterDefault->maxItems ( ) );
    parameter.insert ( "minItems", parameterDefault->minItems ( ) );
    parameter.insert ( "uniqueItems", parameterDefault->uniqueItems ( ) );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addResponsesForCurrentOperation ( QJsonObject &operationJson ) {
    QJsonObject responses;
    for ( Data::ResponseField *response : _currentOperation->responses ( ) ) {
        _currentResponse = response;
        _addCurrentResponseToResponsesJson ( responses );
    }
    operationJson.insert ( "responses", responses );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addCurrentResponseToResponsesJson ( QJsonObject &responses ) {
    if ( !_currentResponse ) {
        qWarning ( ) << "Can't add single response to operation" << QString ( "'%1 %2'" )
                     .arg ( _currentOperation->operationTypeAsString ( ) ).arg (  _currentOperation->path ( ) );
        return;
    }
    responses.insert ( _currentResponse->responseKey ( ), QJsonObject {
        { "description", _currentResponse->description ( ) }
    } );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// definitions
void SwaggerJsonSerializer::_addDefinitionsToSwaggerJson ( ) {
    _clearJsonObject ( _definitionsJson );
    for ( Data::DefinitionField *definition : _swagger->definitions ( ) ) {
        _currentDefinition = definition;
        _addDefinitionToDefinitionsJson ( );
    }
    _swaggerJson.insert ( "definitions", _definitionsJson );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addDefinitionToDefinitionsJson ( ) {
    if ( !_currentDefinition ) {
        qWarning ( ) << "Can't add single definition to definitions";
        return;
    }
    QJsonObject definitonJson = _createDefinitionJson ( );
    _definitionsJson.insert ( _currentDefinition->name ( ), definitonJson );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonObject SwaggerJsonSerializer::_createDefinitionJson ( ) {
    QJsonObject definitionJson {
        { "type", _currentDefinition->type ( ) }
    };
    _addPropertiesForCurrentDefinition ( definitionJson );
    return definitionJson;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addPropertiesForCurrentDefinition ( QJsonObject &definitionJson ) {
    QJsonObject properties;
    for ( Data::PropertyField *property : _currentDefinition->properties ( ) ) {
        _currentProperty = property;
        _addCurrentPropertyToPropertiesJson ( properties );
    }
    definitionJson.insert ( "properties", properties );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerJsonSerializer::_addCurrentPropertyToPropertiesJson ( QJsonObject &properties ) {
    if ( !_currentProperty ) {
        qWarning ( ) << "Can't add single property to definition" << QString ( "'%1 %2'" )
                     .arg ( _currentProperty->name ( ) ).arg (  _currentDefinition->name ( ) );
        return;
    }
    properties.insert ( _currentProperty->name ( ), QJsonObject {
        { "type", _currentProperty->type ( ) },
        { "format", _currentProperty->format ( ) },
        { "description", _currentProperty->description ( ) }
    } );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// property
QJsonObject SwaggerJsonSerializer::swaggerJson ( ) const {
    return _swaggerJson;
}


} // Core
} // Swagger
