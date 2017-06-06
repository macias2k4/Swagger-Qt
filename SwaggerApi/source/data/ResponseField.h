#ifndef RESPONSEFIELD_H
#define RESPONSEFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>
#include <SchemaField.h>

namespace Swagger {
namespace Data {

/// \brief ResponseField -> Operation response object
class ResponseField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString description READ description WRITE setDescription NOTIFY descriptionChanged )
    Q_PROPERTY ( QJsonValue Schema READ schemaJson WRITE setSchemaJson NOTIFY setSchemaDetected )

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

    /// \brief schemaJson -> return empty JsonValue
    QJsonValue schemaJson ( ) const;
    /// \brief setSchemaJson -> inform about detect to try set schema
    void setSchemaJson ( QJsonValue schemaJson );
    /// \brief schema -> return definition of the response structure
    SchemaField schema ( ) const;

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void descriptionChanged ( QString description );
    void setSchemaDetected ( SchemaField *schema, QJsonValue schemaValue );

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
    /// \brief _schema -> A definition of the response structure. It can be a primitive, an array
    /// or an object. If this field does not exist, it means no content is returned as part of the
    /// response.
    SchemaField _schema;

};

} // Data
} // Swagger

Q_DECLARE_METATYPE ( Swagger::Data::ResponseField )

#endif // RESPONSEFIELD_H
