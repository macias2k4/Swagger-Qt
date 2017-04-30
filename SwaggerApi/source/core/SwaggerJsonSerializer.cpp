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
    // clear code - sub methods !
    QJsonArray tags;
    for ( QString tag : _currentOperation->tags ( ) ) {
        tags.append ( tag );
    }
    operationJson.insert ( "tags", tags );
    QJsonArray consumes;
    for ( QString consume : _currentOperation->consumes ( ) ) {
        consumes.append ( consume );
    }
    operationJson.insert ( "consumes", consumes );
    QJsonArray produces;
    for ( QString produce : _currentOperation->produces ( ) ) {
        produces.append ( produce );
    }
    operationJson.insert ( "produces", produces );
    QJsonArray schemes;
    for ( QString scheme : _currentOperation->schemes ( ) ) {
        schemes.append ( scheme );
    }
    operationJson.insert ( "schemes", schemes );
    QJsonArray parameters;
    for ( Base::ParameterFieldBase *parameter : _currentOperation->parameters ( ) ) {
        if ( parameter ) {
            // depending on 'in' value different extending parameters
            parameters.append ( QJsonObject {
                { "name", parameter->name ( ) },
                { "in", parameter->in ( ) },
                { "description", parameter->description ( ) },
                { "required", parameter->required ( ) }
            } );
        }
    }
    operationJson.insert ( "parameters", parameters );
    return operationJson;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// property
QJsonObject SwaggerJsonSerializer::swaggerJson ( ) const {
    return _swaggerJson;
}


} // Core
} // Swagger
