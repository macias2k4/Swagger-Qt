#include "ParameterFieldBase.h"

namespace Swagger {
namespace Base {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ParameterFieldBase::ParameterFieldBase ( QObject *parent )
    : SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ParameterFieldBase::~ParameterFieldBase ( ) {

}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterFieldBase::clear ( ) {
    _name = QString ( );
    _in = QString ( );
    _description = QString ( );
    _required = false;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ParameterFieldBase::name ( ) const {
    return _name;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterFieldBase::setName ( QString name ) {
    if ( _name == name ) {
        return;
    }
    _name = name;
    emit nameChanged ( name );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ParameterFieldBase::in ( ) const {
    return _in;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterFieldBase::setIn ( QString in ) {
    if ( _in == in ) {
        return;
    }
    if ( !_acceptableIn.contains ( in ) ) {
        qWarning ( )<< "Can't set parameter in" << in << ". It not contain in acceptable in types";
        return;
    }
    _in = in;
    emit inChanged ( in );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ParameterFieldBase::description ( ) const {
    return _description;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterFieldBase::setDescription ( QString description ) {
    if ( _description == description ) {
        return;
    }
    _description = description;
    emit descriptionChanged ( description );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ParameterFieldBase::required ( ) const {
    return _required;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterFieldBase::setRequired ( bool required ) {
    if ( _required == required ) {
        return;
    }
    _required = required;
    emit requiredChanged ( required );
}

} // Base
} // Swagger
