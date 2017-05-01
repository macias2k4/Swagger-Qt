#include "ResponseField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ResponseField::ResponseField ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ResponseField::ResponseField ( const ResponseField &object )
    : Base::SwaggerFieldBase ( nullptr ),
      _responseKey           ( object.responseKey ( ) ),
      _description           ( object.description ( ) ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ResponseField::~ResponseField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ResponseField::isFieldAlreadySet ( ) const {
    return !_responseKey.isEmpty ( ) && !_description.isEmpty ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ResponseField::clear ( ) {
    _responseKey = QString ( );
    _description = QString ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// property
QString ResponseField::responseKey ( ) const {
    return _responseKey;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ResponseField::setResponseKey ( const QString &responseKey ) {
    if ( _responseKey == responseKey ) {
        return;
    }
    _responseKey = responseKey;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ResponseField::description ( ) const {
    return _description;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ResponseField::setDescription ( QString description ) {
    if ( _description == description ) {
        return;
    }
    _description = description;
    emit descriptionChanged ( description );
}


} // Data
} // Swagger
