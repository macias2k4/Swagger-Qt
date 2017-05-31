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
       _ref                   ( object.ref ( ) ) {
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

} // Data
} // Swagger
