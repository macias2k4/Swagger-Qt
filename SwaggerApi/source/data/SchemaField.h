/**
  * \file     class.h
  * \author   m.lamparski
  * \date     2017-05-31
  * \brief    File with class of single Swagger Schema field object

*/
#ifndef SCHEMAFIELD_H
#define SCHEMAFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>

namespace Swagger {
namespace Data {

/// \brief SchemaField -> class of single Swagger Schema field object
class SchemaField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString ref READ ref WRITE setRef NOTIFY refChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit SchemaField ( QObject *parent = 0 );
    SchemaField ( const SchemaField &object );
    ~SchemaField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief isFieldAlreadySet -> return information is Schema field properties already set
    bool isFieldAlreadySet ( ) const override;
    /// \brief clear -> clear properties of current field
    void clear ( ) override;

    // - property
    /// \brief ref -> return reference to another JSON value in a JSON document
    QString ref ( ) const;
    /// \brief setRef -> set reference to another JSON value in a JSON document
    void setRef ( QString ref );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void refChanged ( QString ref );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _ref -> keep reference to another JSON value in a JSON document
    QString _ref = QString ( );

};

} // Data
} // Swagger

#endif // SCHEMAFIELD_H
