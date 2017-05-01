#ifndef RESPONSEFIELD_H
#define RESPONSEFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>

namespace Swagger {
namespace Data {

/// \brief ResponseField -> Operation response object
class ResponseField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString description READ description WRITE setDescription NOTIFY descriptionChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit ResponseField ( QObject *parent = 0 );
    ResponseField ( const ResponseField &object );
    ~ResponseField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief isFieldAlreadySet -> return information is Response field properties already set
    bool isFieldAlreadySet ( ) const;
    /// \brief clear -> clear properties of current field
    void clear ( ) override;

    // - property

    QString responseKey ( ) const;
    void setResponseKey ( const QString &responseKey );

    QString description ( ) const;
    void setDescription ( QString description );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void descriptionChanged ( QString description );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _responseKey -> Key describing response
    QString _responseKey = QString ( );
    /// \brief _description -> Required. A short description of the response
    QString _description = QString ( );

};

} // Data
} // Swagger

Q_DECLARE_METATYPE ( Swagger::Data::ResponseField )

#endif // RESPONSEFIELD_H
