#include "SwaggerApi.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerApi::SwaggerApi ( QObject *parent )
    : QObject                ( parent ),
      _swaggerFiller         ( _swagger ),
      _swaggerJsonSerializer ( _swagger ) {
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
    _serializeSwaggerToJson ( );
    _saveSwaggerJsonToFile ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_findAnnotations ( ) {
    _annotationFinder.setSourceCodeFilesPath ( _sourceCodeFilesPath );
    _annotationFinder.findAnnotations ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_serializeSwaggerToJson ( ) {
    _swaggerJsonSerializer.serialize ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::_saveSwaggerJsonToFile ( ) {
    QFile file ( QString ( "%1/QtSwagger.json" ).arg ( _outputDocumentationPath ) );
    if ( !file.open ( QIODevice::ReadWrite ) ) {
        qWarning ( ) << "Can't save swagger file" << file.fileName ( );
    }
    file.write ( QJsonDocument ( _swaggerJsonSerializer.swaggerJson ( ) ).toJson ( ) );
    file.close ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property
QString SwaggerApi::sourceCodeFilesPath ( ) const {
    return _sourceCodeFilesPath;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::setSourceCodeFilesPath ( const QString &sourceCodeFilesPath ) {
    _sourceCodeFilesPath = sourceCodeFilesPath;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString SwaggerApi::outputDocumentationPath ( ) const {
    return _outputDocumentationPath;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerApi::setOutputDocumentationPath ( const QString &outputDocumentationFilePath ) {
    _outputDocumentationPath = outputDocumentationFilePath;
}

} // Core
} // Swagger
