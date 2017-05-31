/**
  * \file     ParameterInBodyField.h
  * \author   m.lamparski
  * \date     2017-05-31
  * \brief    File with parameter object, with 'in' field value equal 'body'

*/
#ifndef PARAMETERINBODYFIELD_H
#define PARAMETERINBODYFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <ParameterFieldBase.h>
#include <SchemaField.h>

namespace Swagger {
namespace Data {

/// \brief ParameterInBodyField -> Parameter object, with 'in' field value equal 'body'
class ParameterInBodyField : public Base::ParameterFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QJsonValue Schema READ schemaJson WRITE setSchemaJson NOTIFY setSchemaDetected )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit ParameterInBodyField ( QObject *parent = 0 );
    ~ParameterInBodyField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    /// \brief isFieldAlreadySet -> return information is field properties already set
    virtual bool isFieldAlreadySet ( ) const override;
    /// \brief clear -> clear properties of current field
    virtual void clear ( ) override;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    // - property

    /// \brief schemaJson -> return empty JsonValue
    QJsonValue schemaJson ( ) const;
    /// \brief setSchemaJson -> inform about detect to try set schema
    void setSchemaJson ( QJsonValue schemaJson );
    /// \brief schema -> return schema defining the type used for the body parameter
    SchemaField schema ( ) const;

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void setSchemaDetected ( SchemaField *schema, QJsonValue schemaValue );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _schema -> Required. The schema defining the type used for the body parameter.
    SchemaField _schema;

};

} // Data
} // Swagger

#endif // PARAMETERINBODYFIELD_H
