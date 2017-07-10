/**
  * \file     PropertyField.h
  * \author   m.lamparski
  * \date     2017-05-09
  * \brief    File with class of Property object which list is used in DefinitionField

*/
#ifndef PROPERTYFIELD_H
#define PROPERTYFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>
#include <ItemsField.h>

namespace Swagger {
namespace Data {

/// \brief PropertyField -> Property object which list is used in DefinitionField
class PropertyField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY ( QString type READ type WRITE setType NOTIFY typeChanged )
    Q_PROPERTY ( QString format READ format WRITE setFormat NOTIFY formatChanged )
    Q_PROPERTY ( QString description READ description WRITE setDescription NOTIFY descriptionChanged )
    Q_PROPERTY ( QString ref READ ref WRITE setRef NOTIFY refChanged )
    Q_PROPERTY ( QJsonValue Items READ itemsJson WRITE setItemsJson NOTIFY setItemsDetected )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit PropertyField ( QObject *parent = 0 );
    PropertyField ( const PropertyField &object );
    ~PropertyField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief isFieldAlreadySet -> return information is Property field properties already set
    bool isFieldAlreadySet ( ) const override;
    /// \brief clear -> clear properties of current field
    void clear ( ) override;

    // - property

    QString name ( ) const;
    void setName ( QString name );

    QString type ( ) const;
    void setType ( QString type );

    QString format ( ) const;
    void setFormat ( QString format );

    QString description ( ) const;
    void setDescription ( QString description );

    /// \brief ref -> return reference to another JSON value in a JSON document
    QString ref ( ) const;
    /// \brief setRef -> set reference to another JSON value in a JSON document
    void setRef ( QString ref );

    /// \brief items -> retrun describe of items in the array.
    ItemsField items ( ) const;
    QJsonValue itemsJson ( ) const;
    void setItemsJson ( QJsonValue itemsValue );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void nameChanged ( QString name );
    void typeChanged ( QString type );
    void formatChanged ( QString format );
    void descriptionChanged ( QString description );
    void refChanged ( QString ref );
    void setItemsDetected ( ItemsField *items, QJsonValue itemsValue );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _name -> Required. Name of the property
    QString _name;
    /// \brief _type -> Required. The type of the property
    QString _type;
    /// \brief _format -> The extending format for the previously mentioned type
    QString _format;
    /// \brief _description -> A verbose explanation of property meaning
    QString _description;
    /// \brief _ref -> keep reference to another JSON value in a JSON document
    QString _ref;
    /// \brief _items -> Required if type is "array". Describes the type of items in the array.
    ItemsField _items;

};

} // Data
} // Swagger

#endif // PROPERTYFIELD_H
