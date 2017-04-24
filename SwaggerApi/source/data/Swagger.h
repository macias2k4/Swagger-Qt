/**
  * \file     SwaggerObject.h
  * \author   m.lamparski
  * \date     2017-04-05
  * \brief    File with root object of swagger document

*/
#ifndef SWAGGER_H
#define SWAGGER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>
#include <InfoField.h>
#include <GetOperationField.h>

namespace Swagger {
namespace Data {

/// \brief Swagger -> root object of swagger document
class Swagger : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString host READ host WRITE setHost NOTIFY hostChanged )
    Q_PROPERTY ( QString basePath READ basePath WRITE setBasePath NOTIFY basePathChanged )
    Q_PROPERTY ( InfoField *Info READ info WRITE setInfo )
    Q_PROPERTY ( QStringList schemes READ schemes WRITE setSchemes NOTIFY schemesChanged )
    Q_PROPERTY ( QStringList consumes READ consumes WRITE setConsumes NOTIFY consumesChanged )
    Q_PROPERTY ( QStringList produces READ produces WRITE setProduces NOTIFY producesChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit Swagger ( QObject *parent = 0 );
    ~Swagger ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    /// \brief isFieldAlreadySet -> return information is Swagger field properties already set
    bool isFieldAlreadySet ( ) const;
    /// \brief clear -> clear all fields of swagger object
    void clear ( ) override;

    // - property
    InfoField *info ( );
    void setInfo ( InfoField *info );

    QString host ( ) const;
    void setHost ( QString host );

    QString basePath ( ) const;
    void setBasePath ( QString basePath );

    QStringList schemes ( ) const;
    void setSchemes ( QStringList schemes );

    QStringList consumes ( ) const;
    void setConsumes ( QStringList consumes );

    QStringList produces ( ) const;
    void setProduces ( QStringList produces );

    // -- operation
    /// \brief isOperationAlreadyExist -> check is given operation already added in operations list
    bool isOperationAlreadyExist ( Base::OperationFieldBase *operation );
    /// \brief addOperation -> adding new operation object to list
    void addOperation ( Base::OperationFieldBase *operation );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void hostChanged ( QString host );
    void basePathChanged ( QString basePath );
    void schemesChanged ( QStringList schemes );
    void consumesChanged ( QStringList consumes );
    void producesChanged ( QStringList produces );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots



private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _swagger -> Required. Specifies the Swagger Specification version being used  (2.0)
    const QString _swagger = "2.0";
    /// \brief _info -> Required. Provides metadata about the API
    InfoField _info;
    /// \brief _host -> The host (name or ip) serving the AP
    QString _host = QString ( );
    /// \brief _basePath -> The base path on which the API is served, which is relative to the host
    QString _basePath = QString ( );
    /// \brief _schemes -> The transfer protocol of the API. Values MUST be from the list: "http",
    /// "https", "ws", "wss"
    QStringList _schemes;
    /// \brief _acceptableSchemes -> the list of acceptable schemes
    const QStringList _acceptableSchemes = { "http", "https", "ws", "wss" };
    /// \brief _consumes -> A list of MIME types the APIs can consume. This is global to all APIs
    /// but can be overridden on specific API calls
    QStringList _consumes;
    /// \brief _produces -> A list of MIME types the APIs can produce. This is global to all APIs
    /// but can be overridden on specific API calls
    QStringList _produces;
    /// \brief _operations -> list of API operations
    QList < Base::OperationFieldBase* > _operations;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief _registerMetaTypes -> register all swagger fields class in meta types
    void _registerMetaTypes ( );
    /// \brief _clearOperations -> clear swagger operations
    void _clearOperations ( );
};

} // Data
} // Swagger

#endif // SWAGGER_H
