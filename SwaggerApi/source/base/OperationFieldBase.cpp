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
// property
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
