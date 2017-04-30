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
#include <SwaggerApi.h>

namespace Swagger {
namespace Core {

/// \brief SwaggerQt ->  main class of application SwaggerQt
class SwaggerQt : public QObject {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors

    /// "@Swg.Swagger" : {
    ///     "host" : "192.168.200.57",
    ///     "basePath" : "/pxvs",
    ///     "schemes" : ["http", "https"],
    ///     "@Swg.Info" : {
    ///         "title" : "PxVS Web Methods server",
    ///         "description" : "Web Methods",
    ///         "termsOfService" : "test",
    ///         "version" : "1.0.0"
    ///     },
    ///     "produces" : ["application/json"]
    /// }
    explicit SwaggerQt ( QObject *parent = 0 );
    /// "@Swg.Info" : {
    ///         "title" : "PxVS Web Methods server 1",
    ///         "description" : "Web Methods 1",
    ///         "termsOfService" : "test",
    ///         "version" : "1.0.0"
    ///     }
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
    SwaggerApi _swaggerApi;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

};

} // Core
} // Swagger

#endif // SWAGGERQT_H
