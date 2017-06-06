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
#include <PropertyField.h>

namespace Swagger {
namespace Data {

/// \brief SchemaField -> class of single Swagger Schema field object
class SchemaField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString ref READ ref WRITE setRef NOTIFY refChanged )
    Q_PROPERTY ( QString type READ type WRITE setType NOTIFY typeChanged )
    Q_PROPERTY ( QJsonValue Properties READ propertiesJson WRITE setPropertiesJson NOTIFY
                 setPropertiesDetected )

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


    QString type ( ) const;
    void setType ( QString type );

    QJsonValue propertiesJson ( ) const;
    void setPropertiesJson ( QJsonValue properties );
    QList<PropertyField *> properties ( ) const;

    // -- properties
    /// \brief isPropertyAlreadyExist -> check is given property already added to this properties
    bool isPropertyAlreadyExist ( PropertyField *property );
    /// \brief addProperty -> adding new property object to list
    void addProperty ( PropertyField *property );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void refChanged ( QString ref );
    void typeChanged ( QString type );
    void setPropertiesDetected ( QJsonValue properties );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _ref -> keep reference to another JSON value in a JSON document
    QString _ref = QString ( );
    /// \brief _type -> name of definition
    QString _type = QString ( );
    /// \brief _parameters -> list of operation parameters
    QList < PropertyField * > _properties;

};

} // Data
} // Swagger

#endif // SCHEMAFIELD_H
