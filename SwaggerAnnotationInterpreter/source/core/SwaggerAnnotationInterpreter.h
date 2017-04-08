/**
  * \file     SwaggerAnnotationInterpreter.h
  * \author   m.lamparski
  * \date     2017-04-05 -> $Date$
  * \version  $Revision$
  * \brief    Main class of library to interprate Swagger annotation written in source code in set
  * path

*/
#ifndef SWAGGERANNOTATIONINTERPRETER_H
#define SWAGGERANNOTATIONINTERPRETER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger
#include "swaggerannotationinterpreter_global.h"
#include <AnnotationFinder.h>

namespace Swagger {
namespace Core {

/// \brief SwaggerAnnotationInterpreter -> main class of library
class SWAGGERANNOTATIONINTERPRETERSHARED_EXPORT SwaggerAnnotationInterpreter : public QObject {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    SwaggerAnnotationInterpreter ( );
    ~SwaggerAnnotationInterpreter ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief interprete -> try to start interprating swagger annotation in source code files
    void interprete ( );


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
    const QString _ModuleName = "<SwaggerAnnotation>";
    /// \brief _sourceCodeFilesPath -> path to the source files to search
    QString _sourceCodeFilesPath = QString ( );
    /// \brief _lastError -> last error message
    QString _lastErrorMessage = QString ( );
    /// \brief _annotationFinder -> object to search annotation in source code files
    AnnotationFinder _annotationFinder;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief _setConnections -> set connections between class objects
    void _setConnections ( );
    /// \brief _clearAllInterpreteVariables -> clearing all variables which are used in interprete
    /// process
    void _clearAllInterpreteVariables ( );
    /// \brief _isAllPropertySet -> return information is all need property set
    bool _isAllPropertySet ( );
    /// \brief _setLastErrorMessage -> set error message
    void _setLastErrorMessage ( const QString &message );
    /// \brief _startInterprete -> start interprete process
    void _startInterprete ( );
    /// \brief _findAnnotations -> start to search annotiations in source files in set path
    void _findAnnotations ( );
;
};

} // Core
} // Swagger

#endif // SWAGGERANNOTATIONINTERPRETER_H
