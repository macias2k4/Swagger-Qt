#include "AnnotationFinder.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
AnnotationFinder::AnnotationFinder ( QObject *parent )
    : QObject ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
AnnotationFinder::~AnnotationFinder ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::findAnnotations ( ) {
    _clearAllFindAnnotationsVariables ( );
    if ( _isAllPropertySet ( ) ) {
        _startFindAnnotations ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_clearAllFindAnnotationsVariables ( ) {
    _lastErrorMessage = QString ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool AnnotationFinder::_isAllPropertySet ( ) {
    if ( _sourceCodeFilesPath.isEmpty ( ) ) {
        _setLastErrorMessage ( "Path to source code files  is not set" );
        return false;
    }
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_setLastErrorMessage ( const QString &message ) {
    _lastErrorMessage = message;
    qWarning ( ) << _ModuleName << message;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_startFindAnnotations ( ) {
    _sourceCodeFilesModel.fillModelWithRelativeRootPath ( _sourceCodeFilesPath );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property
void AnnotationFinder::setSourceCodeFilesPath ( const QString &sourceCodeFilesPath ) {
    _sourceCodeFilesPath = sourceCodeFilesPath;
}

} // Core
} // Swagger
