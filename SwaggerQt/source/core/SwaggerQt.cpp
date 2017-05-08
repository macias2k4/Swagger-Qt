#include "SwaggerQt.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerQt::SwaggerQt ( QObject *parent ) : QObject ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerQt::~SwaggerQt ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerQt::generateSwaggerFile ( ) {
    _swaggerApi.interprete ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property
void SwaggerQt::setSourceCodeFilesPath ( const QString &sourceCodeFilesPath ) {
    _swaggerApi.setSourceCodeFilesPath ( sourceCodeFilesPath );
}

/// "@Swg.Get" : {
///     "tags" : [ "tag1" ],
///     "path" : "/vehicles",
///     "produces" : [
///         "application/json",
///         "application/xml"
///     ],
///     "@Swg.Parameters" : [ {
///         "name": "transportType",
///         "in": "path",
///         "description": "Type of transport (water, land)",
///         "required": false,
///         "type": "string"
///     }
///     ],
///     "@Swg.Responses" : {
///         "200" : {
///             "description" : "Operation was successful",
///             "@Swg.Schema" : {
///                 "type" : "array",
///                 "@Swg.Items" : {
///                     "type" : "object",
///                     "ref" : "#/definitions/Vehicle"
///                 }
///             }
///         },
///         "default" : {
///             "description" : "Operation was failure",
///             "@Swg.Schema" : {
///                 "ref" : "#/definitions/Exception"
///             }
///         }
///     }
/// }


/// "@Swg.Definition" : {
///     "name" : "model_1",
///     "type" : "object",
///     "@Swg.Properties" : {
///         "id" : {
///             "type": "integer",
///             "format" : "int64",
///             "description": "Unique identifier"
///         },
///         "name" : {
///             "type": "string",
///             "description": "name of object"
///         },
///         "arrayOfModel2": {
///             "type": "array",
///             "items": {
///                 "$ref": "#/definitions/model_2"
///             }
///         }
///     }
/// }


} // Core
} // Swagger
