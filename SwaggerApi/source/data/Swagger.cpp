#include "Swagger.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
Swagger::Swagger ( QObject *parent )
    : Base::SwaggerFieldBase ( parent ) {
    _registerMetaTypes ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Swagger::~Swagger ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::_registerMetaTypes ( ) {
    qRegisterMetaType < InfoField > ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool Swagger::isFieldAlreadySet ( ) const {
    return !_host.isEmpty ( ) && !_basePath.isEmpty ( );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::clear ( ) {
    _info.clear ( );
    _host = QString ( );
    _basePath = QString ( );
    _schemes.clear ( );
    _consumes.clear ( );
    _produces.clear ( );
    _clearOperations ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::_clearOperations ( ) {
    while ( !_operations.isEmpty ( ) ) {
        delete _operations.takeFirst ( );
    }
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - property

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString Swagger::swagger ( ) const {
    return _swagger;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
InfoField *Swagger::info ( ) {
    return &_info;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::setInfo ( InfoField *info ) {
    _info = *info;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
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
void Swagger::setConsumes ( QStringList consumes ) {
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

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// operations
bool Swagger::isOperationAlreadyExist ( Base::OperationFieldBase *operation ) {
    if ( !operation ) {
        return false;
    }
    for ( Base::OperationFieldBase *addedOpearion : _operations ) {
        if ( addedOpearion && ( addedOpearion->operationType ( ) == operation->operationType ( ) )
                && ( addedOpearion->path ( ) == operation->path ( ) ) ) {
            return true;
        }
    }
    return false;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void Swagger::addOperation ( Base::OperationFieldBase *operation ) {
    if ( !operation ) {
        qWarning ( ) << "Can't add operation. Input object is null";
        return;
    }
    if ( !operation->path ( ).startsWith ( "/" ) ) {
        qWarning ( ) << "Can't add operation. Path of operation don't start with '/' sign (Path="
                     << operation->path ( ) << ")";
        return;
    }
    _operations.append ( operation );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QList<Base::OperationFieldBase *> Swagger::operations ( ) const {
    return _operations;
}

} // Data
} // Swagger
