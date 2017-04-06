/**
  * \file     SwaggerObject.h
  * \author   m.lamparski
  * \date     2017-04-05 -> $Date$
  * \version  $Revision$
  * \brief    File with root object of swagger document

*/
#ifndef SWAGGER_H
#define SWAGGER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>

namespace Swagger {
namespace Data {

/// \brief Swagger -> root object of swagger document
class Swagger : public QObject
{
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ///
    /// \swg.Swagger {
    ///     host : "192.168.200.57",
    ///     basePath : "/pxvs",
    ///     schemas : ["http"],
    ///     \swg.Info {
    ///         title : "PxVS Web Methods server"
    ///     },
    ///     produces : ["application/json"],
    ///     \swg.Paths {
    ///
    ///     }
    /// }
    /// \param parent
    ///
    explicit Swagger ( QObject *parent = 0 );
    ~Swagger ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    // - property

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _swagger -> Required. Specifies the Swagger Specification version being used  (2.0)
    QString _swagger = "2.0";
    // InfoField ? InfoObject ->
    /// \brief _host -> The host (name or ip) serving the AP
    QString _host = QString ( );
    /// \brief _basePath -> The base path on which the API is served, which is relative to the host
    QString _basePath = QString ( );

};

} // Data
} // Swagger

#endif // SWAGGER_H
