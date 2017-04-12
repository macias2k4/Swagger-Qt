#include "Swagger.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
Swagger::Swagger ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Swagger::~Swagger ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool Swagger::isFieldAlreadySet ( ) const {
    return !_host.isEmpty ( ) && !_basePath.isEmpty ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property

// ────────────────────────────────────────────────────────────────────────────────────────────── //
InfoField &Swagger::infoField ( ) {
    return _infoField;
}


QString Swagger::host ( ) const {
    return _host;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::setHost ( QString host ) {
    if ( _host == host ) {
        return;
    }
    _host = host;
    emit hostChanged ( host );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString Swagger::basePath ( ) const {
    return _basePath;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::setBasePath ( QString basePath ) {
    if ( _basePath == basePath ) {
        return;
    }
    _basePath = basePath;
    emit basePathChanged ( basePath );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QStringList Swagger::schemes ( ) const {
    return _schemes;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::setSchemes ( QStringList schemes ) {
    if ( _schemes == schemes ) {
        return;
    }
    _schemes.clear ( );
    for ( QString scheme : schemes ) {
        if ( _acceptableSchemes.contains ( scheme ) ) {
            _schemes.append ( scheme );
        } else {
            qWarning ( ) << "Skip schema" << scheme << ". It not contain in acceptable schemes";
        }
    }
    emit schemesChanged ( _schemes );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QStringList Swagger::consumes ( ) const {
    return _consumes;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::setConsumes(QStringList consumes) {
    if ( _consumes == consumes ) {
        return;
    }
    _consumes.clear ( );
    for ( QString consume : consumes ) {
        _consumes.append ( consume );
    }
    emit consumesChanged ( consumes );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QStringList Swagger::produces ( ) const {
    return _produces;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::setProduces ( QStringList produces ) {
    if ( _produces == produces ) {
        return;
    }
    _produces.clear ( );
    for ( QString produce : produces ) {
        _produces.append ( produce );
    }
    emit producesChanged ( produces );
}


} // Data
} // Swagger
