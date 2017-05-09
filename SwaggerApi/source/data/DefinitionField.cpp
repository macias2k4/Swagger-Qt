#include "DefinitionField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
DefinitionField::DefinitionField ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
DefinitionField::~DefinitionField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool DefinitionField::isFieldAlreadySet ( ) const {
    return !_name.isEmpty ( ) && !_properties.isEmpty ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void DefinitionField::clear ( ) {
    _name = QString ( );
    _type = QString ( );
    while ( !_properties.isEmpty ( ) ) {
        delete _properties.takeFirst ( );
    }
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString DefinitionField::name ( ) const {
    return _name;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void DefinitionField::setName ( QString name ) {
    if ( _name == name ) {
        return;
    }
    _name = name;
    emit nameChanged ( name );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString DefinitionField::type ( ) const {
    return _type;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void DefinitionField::setType ( QString type ) {
    if ( _type == type ) {
        return;
    }
    _type = type;
    emit typeChanged ( type );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonValue DefinitionField::propertiesJson ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void DefinitionField::setPropertiesJson ( QJsonValue properties ) {
    emit setPropertiesDetected ( properties );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QList<PropertyField *> DefinitionField::properties ( ) const {
    return _properties;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool DefinitionField::isPropertyAlreadyExist ( PropertyField *property ) {
    if ( !property ) {
        return false;
    }
    for ( Data::PropertyField *addedProperty : _properties ) {
        if ( addedProperty && ( addedProperty->name ( ) == property->name ( ) ) ) {
            return true;
        }
    }
    return false;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void DefinitionField::addProperty ( PropertyField *property ) {
    if ( !property ) {
        qWarning ( ) << "Can't add property. Input object is null";
        return;
    }
    if ( property->name ( ).isNull ( ) ) {
        qWarning ( ) << "Can't add property. Name of property is not set";
        return;
    }
    _properties.append ( property );
}

} // Data
} // Swagger
