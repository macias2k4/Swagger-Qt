/**
  * \file     SwaggerQt.h
  * \author   m.lamparski
  * \date     2017-04-08 -> $Date$
  * \version  $Revision$
  * \brief    File with main class of application SwaggerQt

*/
#ifndef SWAGGERQT_H
#define SWAGGERQT_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerAnnotationInterpreter.h>

namespace Swagger {
namespace Core {

/// \brief SwaggerQt ->  main class of application SwaggerQt
class SwaggerQt : public QObject {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    /// @Swg.Swagger {
    ///     "host" : "192.168.200.57",
    ///     "basePath" : "/pxvs",
    ///     "schemas" : ["http"],
    ///     "@Swg.Info" : {
    ///         "title" : "PxVS Web Methods server"
    ///     },
    ///     "produces" : ["application/json"],
    ///     "@Swg.Paths" : {
    ///
    ///     }
    /// }
    explicit SwaggerQt ( QObject *parent = 0 );
    ~SwaggerQt ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief generateSwaggerFile -> generate swagger file from source code files
    void generateSwaggerFile ( );

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
    const QString _ModuleName = "<SwaggerQt>";
    /// \brief _swaggerApi -> objest of swagger-Qt api library
    SwaggerAnnotationInterpreter _swaggerApi;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

};

} // Core
} // Swagger

#endif // SWAGGERQT_H
