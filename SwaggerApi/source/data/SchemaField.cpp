#include "SchemaField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SchemaField::SchemaField ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SchemaField::SchemaField ( const SchemaField &object )
    : Base::SwaggerFieldBase ( nullptr ),
       _ref                  ( object.ref ( ) ),
       _type                 ( object.type ( ) ) {
    for ( PropertyField *property : object.properties ( ) ) {
        _properties.append ( new PropertyField ( *property ) );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SchemaField::~SchemaField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool SchemaField::isFieldAlreadySet ( ) const {
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SchemaField::clear ( ) {
    _ref = QString ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString SchemaField::ref ( ) const {
    return _ref;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SchemaField::setRef ( QString ref ) {
    if ( _ref == ref ) {
        return;
    }
    _ref = ref;
    emit refChanged ( ref );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString SchemaField::type ( ) const {
    return _type;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SchemaField::setType ( QString type ) {
    if ( _type == type ) {
        return;
    }
    _type = type;
    emit typeChanged ( type );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonValue SchemaField::propertiesJson ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SchemaField::setPropertiesJson ( QJsonValue properties ) {
    emit setPropertiesDetected ( properties );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QList<PropertyField *> SchemaField::properties ( ) const {
    return _properties;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool SchemaField::isPropertyAlreadyExist ( PropertyField *property ) {
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
void SchemaField::addProperty ( PropertyField *property ) {
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
