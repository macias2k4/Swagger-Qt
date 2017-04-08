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

} // Core
} // Swagger
