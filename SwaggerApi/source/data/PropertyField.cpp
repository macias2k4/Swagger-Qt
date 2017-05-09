#include "PropertyField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
PropertyField::PropertyField ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
PropertyField::~PropertyField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool PropertyField::isFieldAlreadySet ( ) const {
    return !_name.isEmpty ( ) && !_type.isEmpty ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void PropertyField::clear ( ) {
    _name = QString ( );
    _type = QString ( );
    _format = QString ( );
    _description = QString ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString PropertyField::name ( ) const {
    return _name;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void PropertyField::setName ( QString name ) {
    if ( _name == name ) {
        return;
    }
    _name = name;
    emit nameChanged ( name );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString PropertyField::type ( ) const {
    return _type;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void PropertyField::setType ( QString type ) {
    if ( _type == type ) {
        return;
    }
    _type = type;
    emit typeChanged ( type );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString PropertyField::format ( ) const {
    return _format;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void PropertyField::setFormat ( QString format ) {
    if ( _format == format ) {
        return;
    }
    _format = format;
    emit formatChanged ( format );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString PropertyField::description ( ) const {
    return _description;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void PropertyField::setDescription ( QString description ) {
    if ( _description == description ) {
        return;
    }
    _description = description;
    emit descriptionChanged ( description );
}

} // Data
} // Swagger
