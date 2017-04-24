#include "OperationFieldBase.h"

namespace Swagger {
namespace Base {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
OperationFieldBase::OperationFieldBase ( QObject *parent )
    : SwaggerFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
OperationFieldBase::~OperationFieldBase ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool OperationFieldBase::isFieldAlreadySet ( ) const {
    return false;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::clear ( ) {
    _path = QString ( );
    _tags.clear ( );
    _summary = QString ( );
    _description = QString ( );
    _operationId = QString ( );
    _consumes.clear ( );
    _produces.clear ( );
    _schemes.clear ( );
    _deprecated = false;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// property
QString OperationFieldBase::path ( ) const {
    return _path;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setPath ( QString path ) {
    if ( _path == path ) {
        return;
    }
    _path = path;
    emit pathChanged ( path );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QStringList OperationFieldBase::tags ( ) const {
    return _tags;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setTags ( QStringList tags ) {
    if ( _tags == tags ) {
        return;
    }
    _tags = tags;
    emit tagsChanged ( tags );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString OperationFieldBase::summary ( ) const {
    return _summary;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setSummary ( QString summary ) {
    if ( _summary == summary ) {
        return;
    }
    _summary = summary;
    emit summaryChanged ( summary );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString OperationFieldBase::description ( ) const {
    return _description;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setDescription ( QString description ) {
    if ( _description == description ) {
        return;
    }
    _description = description;
    emit descriptionChanged ( description );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString OperationFieldBase::operationId ( ) const {
    return _operationId;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setOperationId ( QString operationId ) {
    if ( _operationId == operationId ) {
        return;
    }
    _operationId = operationId;
    emit operationIdChanged ( operationId );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QStringList OperationFieldBase::consumes ( ) const {
    return _consumes;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setConsumes ( QStringList consumes ) {
    if ( _consumes == consumes ) {
        return;
    }
    _consumes = consumes;
    emit consumesChanged ( consumes );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QStringList OperationFieldBase::produces ( ) const {
    return _produces;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setProduces ( QStringList produces ) {
    if ( _produces == produces ) {
        return;
    }
    _produces = produces;
    emit producesChanged ( produces );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonValue OperationFieldBase::parameters ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setParameters ( QJsonValue parameters ) {
    emit setParametersDetected ( parameters );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QStringList OperationFieldBase::schemes ( ) const {
    return _schemes;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setSchemes ( QStringList schemes ) {
    if ( _schemes == schemes ) {
        return;
    }
    _schemes = schemes;
    emit schemesChanged ( schemes );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool OperationFieldBase::deprecated ( ) const {
    return _deprecated;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setDeprecated ( bool deprecated ) {
    if ( _deprecated == deprecated ) {
        return;
    }
    _deprecated = deprecated;
    emit deprecatedChanged ( deprecated );
}

} // Base
} // Swagger
