#ifndef INFOFIELD_H
#define INFOFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>

namespace Swagger {
namespace Data {

/// \brief InfoField -> Info object, it is Swagger root object field
class InfoField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString title READ title WRITE setTitle NOTIFY titleChanged )
    Q_PROPERTY ( QString description READ description WRITE setDescription NOTIFY descriptionChanged )
    Q_PROPERTY ( QString termsOfService READ termsOfService WRITE setTermsOfService NOTIFY
                 termsOfServiceChanged )
    Q_PROPERTY ( QString version READ version WRITE setVersion NOTIFY versionChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit InfoField ( QObject *parent = 0 );
    ~InfoField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    /// \brief isFieldAlreadySet -> return information is Info field properties already set
    bool isFieldAlreadySet ( ) const;

    // - property

    QString title ( ) const;
    void setTitle ( QString title );

    QString description ( ) const;
    void setDescription ( QString description );

    QString termsOfService ( ) const;
    void setTermsOfService ( QString termsOfService );

    QString version ( ) const;
    void setVersion ( QString version );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void titleChanged ( QString title );
    void descriptionChanged ( QString description );
    void termsOfServiceChanged ( QString termsOfService );
    void versionChanged ( QString version );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _title -> Required. The title of the application.
    QString _title;
    /// \brief _description -> A short description of the application
    QString _description;
    /// \brief _termsOfService -> The Terms of Service for the API
    QString _termsOfService;
    /// \brief _version -> Required Provides the version of the application API
    QString _version;
};

} // Data
} // Swagger

#endif // INFOFIELD_H
