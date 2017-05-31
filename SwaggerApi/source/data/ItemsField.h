/**
  * \file     ItemsField.h
  * \author   m.lamparski
  * \date     2017-05-31
  * \brief    File with class of single Swagger Items field object

*/
#ifndef ITEMSFIELD_H
#define ITEMSFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>

namespace Swagger {
namespace Data {

/// \brief ItemsField -> class of single Swagger Items field object
class ItemsField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString type READ type WRITE setType NOTIFY typeChanged )
    Q_PROPERTY ( QString format READ format WRITE setFormat NOTIFY formatChanged )
    Q_PROPERTY ( QString ref READ ref WRITE setRef NOTIFY refChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit ItemsField ( QObject *parent = 0 );
    ItemsField ( const ItemsField &object );
    ~ItemsField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief isFieldAlreadySet -> return information is Schema field properties already set
    bool isFieldAlreadySet ( ) const override;
    /// \brief clear -> clear properties of current field
    void clear ( ) override;

    // - property

    /// \brief type -> return the type of the property
    QString type ( ) const;
    /// \brief setType -> set the type of the property
    void setType ( QString type );

    /// \brief format -> return the extending format for the previously mentioned type
    QString format ( ) const;
    /// \brief setFormat -> set the extending format for the previously mentioned type
    void setFormat ( QString format );

    /// \brief ref -> return reference to another JSON value in a JSON document
    QString ref ( ) const;
    /// \brief setRef -> set reference to another JSON value in a JSON document
    void setRef ( QString ref );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void typeChanged ( QString type );
    void formatChanged ( QString format );
    void refChanged ( QString ref );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _type -> Required. The type of the property
    QString _type = QString ( );
    /// \brief _format -> The extending format for the previously mentioned type
    QString _format = QString ( );
    /// \brief _ref -> keep reference to another JSON value in a JSON document
    QString _ref = QString ( );

};

} // Data
} // Swagger

#endif // ITEMSFIELD_H
