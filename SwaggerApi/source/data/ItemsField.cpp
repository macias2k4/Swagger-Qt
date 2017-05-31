#include "ItemsField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ItemsField::ItemsField ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ItemsField::ItemsField ( const ItemsField &object )
    : Base::SwaggerFieldBase ( nullptr ),
      _type                  ( object.type ( ) ),
      _format                ( object.format ( ) ),
      _ref                   ( object.ref ( ) ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ItemsField::~ItemsField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ItemsField::isFieldAlreadySet ( ) const {
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ItemsField::clear ( ) {
    _type = QString ( );
    _format = QString ( );
    _ref = QString ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ItemsField::type ( ) const {
    return _type;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ItemsField::setType ( QString type ) {
    if ( _type == type ) {
        return;
    }
    _type = type;
    emit typeChanged ( type );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ItemsField::format ( ) const {
    return _format;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ItemsField::setFormat ( QString format ) {
    if ( _format == format ) {
        return;
    }
    _format = format;
    emit formatChanged ( format );
}


// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ItemsField::ref ( ) const {
    return _ref;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ItemsField::setRef ( QString ref ) {
    if ( _ref == ref ) {
        return;
    }
    _ref = ref;
    emit refChanged ( ref );
}

} // Data
} // Swagger
