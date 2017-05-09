/**
  * \file     DefinitionField.h
  * \author   m.lamparski
  * \date     2017-05-09
  * \brief    File with class of single Swagger Definition field object

*/
#ifndef DEFINITIONFIELD_H
#define DEFINITIONFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>
#include <PropertyField.h>

namespace Swagger {
namespace Data {

/// \brief DefinitionField -> class of single Swagger Definition field object
class DefinitionField : public Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY ( QString type READ type WRITE setType NOTIFY typeChanged )
    Q_PROPERTY ( QJsonValue Properties READ propertiesJson WRITE setPropertiesJson NOTIFY
                 setPropertiesDetected )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit DefinitionField ( QObject *parent = 0 );
    ~DefinitionField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief isFieldAlreadySet -> return information is Definition field properties already set
    bool isFieldAlreadySet ( ) const override;
    /// \brief clear -> clear properties of current field
    void clear ( ) override;

    // - property

    QString name ( ) const;
    void setName ( QString name );

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
    void nameChanged ( QString name );
    void typeChanged ( QString type );
    void setPropertiesDetected ( QJsonValue properties );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _name -> Required. name of definition (model)
    QString _name = QString ( );
    /// \brief _type -> name of definition
    QString _type = QString ( );
    /// \brief _parameters -> list of operation parameters
    QList < PropertyField * > _properties;

};

} // Data
} // Swagger

#endif // DEFINITIONFIELD_H
