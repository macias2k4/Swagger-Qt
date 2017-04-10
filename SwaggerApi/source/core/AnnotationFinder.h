/**
  * \file     AnnotationFinder.h
  * \author   m.lamparski
  * \date     2017-04-06
  * \brief    File with class to search annotation in source code files

*/
#ifndef ANNOTATIONFINDER_H
#define ANNOTATIONFINDER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>
#include <QFileInfo>
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonObject>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SourceCodeFilesModel.h>
#include <SwaggerFieldBase.h>

namespace Swagger {
namespace Core {

/// \brief AnnotationFinder -> class to search annotation in source code files
class AnnotationFinder : public QObject {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit AnnotationFinder ( QObject *parent = 0 );
    ~AnnotationFinder ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief findAnnotations -> try to search annotiations in source files in set path
    void findAnnotations ( );

    // - property
    /// \brief setSourceCodeFilesPath -> set path to the source files to search
    void setSourceCodeFilesPath ( const QString &sourceCodeFilesPath );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    /// \brief foundAnnotation -> send found annotation with content
    void foundAnnotation ( const QString &annotationName, const QJsonObject &annotationContent );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _ModuleName -> name of module
    const QString _ModuleName = "<AnnotationFinder>";
    /// \brief _sourceCodeFilesPath -> path to the source files to search
    QString _sourceCodeFilesPath = QString ( );
    /// \brief _lastError -> last error message
    QString _lastErrorMessage = QString ( );
    /// \brief _sourceCodeFilesModel -> model to keep list of found source code files
    Model::SourceCodeFilesModel _sourceCodeFilesModel;
    /// \brief _currentSourceCodeFileInfo -> current reading source code file info
    QFileInfo _currentSourceCodeFileInfo;
    /// \brief _currentSourceCodeFile -> current reading source code file
    QFile _currentSourceCodeFile;
    /// \brief _currentLine -> current line reading from file
    QByteArray _currentLine;
    /// \brief _isAnnotationBlockStarted -> keep information is annotation block started
    bool _isAnnotationBlockStarted = false;
    /// \brief _currentAnnotationBuffor -> buffor of current annotation
    QByteArray _currentAnnotationBuffor;
    /// \brief _commentSigns -> comment signs found in annotation first line
    QString _commentSigns = QString ( );
    /// \brief _commentSigns -> name of current annotation
    QString _currentAnnotationName = QString ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief _clearAllFindAnnotationsVariables -> clearing all variables which are used in
    /// find annotations process
    void _clearAllFindAnnotationsVariables ( );
    /// \brief _isAllPropertySet -> return information is all need property set
    bool _isAllPropertySet ( );
    /// \brief _setLastErrorMessage -> set error message
    void _setLastErrorMessage ( const QString &message );
    /// \brief _startFindAnnotations -> start to search annotiations in source files in set path
    void _startFindAnnotations ( );
    /// \brief _findAnnotationsInCurrentFile -> search annotations in current file
    void _findAnnotationsInCurrentFile ( );
    /// \brief _readCurrentFile -> read current file
    void _readCurrentFile ( );
    /// \brief _readCurrentLine -> read current line of file
    void _readCurrentLine ( );
    /// \brief _checkIsCurrentLineStartAnnotationBlock -> check is current line start annotation
    /// block
    void _checkIsCurrentLineStartAnnotationBlock ( );
    /// \brief _clearAllSingleAnnotationVariables -> clear all variables using in single annotation
    /// read
    void _clearAllSingleAnnotationVariables ( );
    /// \brief _extractCommentSignsFromCurrentLine -> extract comment signs from current line,
    /// when it has annotation keyword
    void _extractCommentSignsFromCurrentLine ( );
    /// \brief _extractAnnotationNameFromCurrentLine -> extract annotation name from current line,
    /// when it has annotation keyword
    void _extractAnnotationNameFromCurrentLine ( );
    /// \brief _appendCurrentLineToAnnotationBlock -> adding current line to anotation block,
    /// after deleting comment signs
    void _appendCurrentLineToAnnotationBlock ( );
    /// \brief _isCurrentAnnotationBufforIsComplete -> check is current annotation buffor is correct
    /// JSon object
    bool _isCurrentAnnotationBufforIsComplete ( );

};

} // Core
} // Swagger

#endif // ANNOTATIONFINDER_H
