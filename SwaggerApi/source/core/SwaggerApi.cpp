#include "SwaggerApi.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerApi::SwaggerApi ( QObject *parent )
    : QObject        ( parent ),
      _swaggerFiller ( _swagger ) {
    _setConnections ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerApi::~SwaggerApi ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_setConnections ( ) {
    connect ( &_annotationFinder, &AnnotationFinder::foundAnnotation,
              &_swaggerFiller, &SwaggerFiller::fill );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::interprete ( ) {
    _clearAllInterpreteVariables ( );
    if ( _isAllPropertySet ( ) ) {
        _startInterprete ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_clearAllInterpreteVariables ( ) {
    _lastErrorMessage = QString ( );
    _swagger.clear ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool SwaggerApi::_isAllPropertySet ( ) {
    if ( _sourceCodeFilesPath.isEmpty ( ) ) {
        _setLastErrorMessage ( "Path to source code files  is not set" );
        return false;
    }
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_setLastErrorMessage ( const QString &message ) {
    _lastErrorMessage = message;
    qWarning ( ) << _ModuleName << message;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_startInterprete ( ) {
    _findAnnotations ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_findAnnotations ( ) {
    _annotationFinder.setSourceCodeFilesPath ( _sourceCodeFilesPath );
    _annotationFinder.findAnnotations ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property
void SwaggerApi::setSourceCodeFilesPath ( const QString &sourceCodeFilesPath ) {
    _sourceCodeFilesPath = sourceCodeFilesPath;
}

} // Core
} // Swagger
