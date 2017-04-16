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
///     "@Swg.Parameter" : {
///         "name": "transportType",
///         "in": "path",
///         "description": "Type of transport (water, land)",
///         "required": false,
///         "type": "string"
///     },
///     "@Swg.Response" : {
///         "stateCode" : "200",
///         "description" : "Operation was successful",
///         "@Swg.Schema" : {
///             "type" : "array",
///             "@Swg.Items" : {
///                 "type" : "object",
///                 "ref" : "#/definitions/Vehicle"
///             }
///         }
///     }
///     "@Swg.Response" : {
///         "stateCode" : "default",
///         "description" : "Operation was failure",
///         "@Swg.Schema" : {
///             "ref" : "#/definitions/Exception"
///         }
///     }
/// }

//@SWG\Get(
// *   path="/products",
// *   summary="list products",
// *   @SWG\Response(
// *     response=200,
// *     description="A list with products"
// *   ),
// *   @SWG\Response(
// *     response="default",
// *     description="an ""unexpected"" error"
// *   )
// * )

} // Core
} // Swagger
