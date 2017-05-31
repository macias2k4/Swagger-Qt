#include "ParameterInBodyField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ParameterInBodyField::ParameterInBodyField ( QObject *parent )
    : Swagger::Base::ParameterFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ParameterInBodyField::~ParameterInBodyField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ParameterInBodyField::isFieldAlreadySet ( ) const {
    return !_name.isEmpty ( ) && !_in.isEmpty ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterInBodyField::clear ( ) {
    ParameterFieldBase::clear ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonValue ParameterInBodyField::schemaJson ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterInBodyField::setSchemaJson ( QJsonValue schemaJson ) {
    emit setSchemaDetected ( &_schema, schemaJson );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SchemaField ParameterInBodyField::schema ( ) const {
    return _schema;
}

} // Data
} // Swagger
