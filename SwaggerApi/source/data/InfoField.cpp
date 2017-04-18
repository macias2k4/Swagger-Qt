#include "InfoField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
InfoField::InfoField ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
InfoField::InfoField ( const InfoField &object )
    : Base::SwaggerFieldBase ( nullptr ) {
    _cloneFrom ( object );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
InfoField::~InfoField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //


// ────────────────────────────────────────────────────────────────────────────────────────────── //
void InfoField::_cloneFrom ( const InfoField &object ) {
    _title = object.title ( );
    _description = object.description ( );
    _termsOfService = object.termsOfService ( );
    _version = object.version ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
InfoField &InfoField::operator = ( const InfoField &object ) {
    _cloneFrom ( object );
    return *this;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool InfoField::isFieldAlreadySet ( ) const {
    return !_title.isEmpty ( ) && !_version.isEmpty ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString InfoField::title ( ) const {
    return _title;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void InfoField::setTitle ( QString title ) {
    if ( _title == title ) {
        return;
    }
    _title = title;
    emit titleChanged ( title );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString InfoField::description ( ) const {
    return _description;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void InfoField::setDescription ( QString description ) {
    if ( _description == description ) {
        return;
    }
    _description = description;
    emit descriptionChanged ( description );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString InfoField::termsOfService ( ) const {
    return _termsOfService;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void InfoField::setTermsOfService ( QString termsOfService ) {
    if ( _termsOfService == termsOfService ) {
        return;
    }
    _termsOfService = termsOfService;
    emit termsOfServiceChanged ( termsOfService );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString InfoField::version ( ) const {
    return _version;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void InfoField::setVersion ( QString version ) {
    if ( _version == version ) {
        return;
    }
    _version = version;
    emit versionChanged ( version );
}


} // Data
} // Swagger
