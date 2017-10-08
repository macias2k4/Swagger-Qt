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
    for ( QFileInfo sourceCodeFile : _sourceCodeFilesModel.sourceCodeFilesReadOnly ( ) ) {
        _currentSourceCodeFileInfo = sourceCodeFile;
        _findAnnotationsInCurrentFile ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_findAnnotationsInCurrentFile ( ) {
    _currentSourceCodeFile.setFileName ( _currentSourceCodeFileInfo.filePath ( ) );
    if ( !_currentSourceCodeFile.open ( QIODevice::ReadOnly ) ) {
        _setLastErrorMessage ( QString ( "Can't open file %1" ).arg (
                                   _currentSourceCodeFileInfo.fileName ( ) ) );
        return;
    }
    _readCurrentFile ( );
    _currentSourceCodeFile.close ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_readCurrentFile ( ) {
    while ( !_currentSourceCodeFile.atEnd ( ) ) {
        _currentLine.clear ( );
        _currentLine.append ( _currentSourceCodeFile.readLine ( ) );
        _readCurrentLine ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_readCurrentLine ( ) {
    _checkIsCurrentLineStartAnnotationBlock ( );
    if ( _isAnnotationBlockStarted ) {
        _appendCurrentLineToAnnotationBlock ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_checkIsCurrentLineStartAnnotationBlock ( ) {
    if ( !_isAnnotationBlockStarted
            && _currentLine.indexOf ( Swagger::Base::SwaggerFieldBase::AnnotationKeyword ) > 0 ) {
        _clearAllSingleAnnotationVariables ( );
        qDebug ( ) << "Current line in file:" << _currentSourceCodeFileInfo.fileName ( ) << "start annotation:" << _currentLine;
        _isAnnotationBlockStarted = true;
        _extractCommentSignsFromCurrentLine ( );
        _extractAnnotationNameFromCurrentLine ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_clearAllSingleAnnotationVariables ( ) {
    _currentAnnotationBuffor.clear ( );
    _commentSigns = QString ( );
    _currentAnnotationName = QString ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_extractCommentSignsFromCurrentLine ( ) {
    int indexOf =  _currentLine.indexOf ( Swagger::Base::SwaggerFieldBase::AnnotationKeyword );
    _commentSigns = _currentLine;
    _commentSigns.remove ( indexOf - 1, _commentSigns.size ( ) - indexOf + 1 );
    _commentSigns.remove ( "\"" );
    _commentSigns = _commentSigns.trimmed ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_extractAnnotationNameFromCurrentLine ( ) {
    int indexOfAnnotation =  _currentLine.indexOf ( Swagger::Base::SwaggerFieldBase::AnnotationKeyword );
    int indexOfJson = _currentLine.indexOf ( ':', indexOfAnnotation );
    _currentAnnotationName = _currentLine.mid ( indexOfAnnotation, indexOfJson - indexOfAnnotation );
    _currentAnnotationName.remove ( "\"" );
    _currentAnnotationName = _currentAnnotationName.trimmed ( );
    _currentLine.remove ( indexOfAnnotation - 1, indexOfJson - indexOfAnnotation + 2 );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void AnnotationFinder::_appendCurrentLineToAnnotationBlock ( ) {
    int indexOf = _currentLine.indexOf ( _commentSigns );
    _currentLine.remove ( indexOf, _commentSigns.length ( ) );
    _currentLine = _currentLine.trimmed ( );
    _currentAnnotationBuffor.append ( _currentLine );
    if ( _isCurrentAnnotationBufforIsComplete ( ) ) {
        qInfo ( ) << "Found annotation" << _currentAnnotationName << "in file" <<
                  _currentSourceCodeFileInfo.fileName ( );
        emit foundAnnotation ( _currentAnnotationName,
                               QJsonDocument::fromJson ( _currentAnnotationBuffor ).object ( ) );
        _isAnnotationBlockStarted = false;
        _currentAnnotationName = QString ( );
        _currentAnnotationBuffor.clear ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool AnnotationFinder::_isCurrentAnnotationBufforIsComplete ( ) {
    QJsonObject annotation = QJsonDocument::fromJson ( _currentAnnotationBuffor ).object ( );
    return !annotation.isEmpty ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property
void AnnotationFinder::setSourceCodeFilesPath ( const QString &sourceCodeFilesPath ) {
    _sourceCodeFilesPath = sourceCodeFilesPath;
}

} // Core
} // Swagger
