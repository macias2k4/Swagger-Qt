#include "SwaggerAnnotationInterpreter.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerAnnotationInterpreter::SwaggerAnnotationInterpreter ( ) {
    _setConnections ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerAnnotationInterpreter::~SwaggerAnnotationInterpreter ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerAnnotationInterpreter::_setConnections ( ) {

}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerAnnotationInterpreter::interprete ( ) {
    _clearAllInterpreteVariables ( );
    if ( _isAllPropertySet ( ) ) {
        _startInterprete ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerAnnotationInterpreter::_clearAllInterpreteVariables ( ) {
    _lastErrorMessage = QString ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool SwaggerAnnotationInterpreter::_isAllPropertySet ( ) {
    if ( _sourceCodeFilesPath.isEmpty ( ) ) {
        _setLastErrorMessage ( "Path to source code files  is not set" );
        return false;
    }
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerAnnotationInterpreter::_setLastErrorMessage ( const QString &message ) {
    _lastErrorMessage = message;
    qWarning ( ) << _ModuleName << message;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerAnnotationInterpreter::_startInterprete ( ) {
    _findAnnotations ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerAnnotationInterpreter::_findAnnotations ( ) {
    _annotationFinder.setSourceCodeFilesPath ( _sourceCodeFilesPath );
    _annotationFinder.findAnnotations ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property
void SwaggerAnnotationInterpreter::setSourceCodeFilesPath ( const QString &sourceCodeFilesPath ) {
    _sourceCodeFilesPath = sourceCodeFilesPath;
}

} // Core
} // Swagger
