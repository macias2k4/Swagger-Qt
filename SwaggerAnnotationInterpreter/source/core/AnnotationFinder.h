/**
  * \file     AnnotationFinder.h
  * \author   m.lamparski
  * \date     2017-04-06 -> $Date$
  * \version  $Revision$
  * \brief    File with class to search annotation in source code files

*/
#ifndef ANNOTATIONFINDER_H
#define ANNOTATIONFINDER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>
#include <QFileInfo>
#include <QDirIterator>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SourceCodeFilesModel.h>

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
    /// \brief _currentSourceCodeFile -> current reading source code file
    QFileInfo _currentSourceCodeFile;



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

};

} // Core
} // Swagger

#endif // ANNOTATIONFINDER_H
