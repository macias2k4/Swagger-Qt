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
QString OperationFieldBase::operationTypeValueToString ( OperationFieldBase::OperationType value ) {
    QMetaEnum metaEnum = OperationFieldBase::staticMetaObject.enumerator (
                             OperationFieldBase::staticMetaObject.indexOfEnumerator ( "OperationType" ) );
    return QString ( metaEnum.valueToKey ( static_cast < int > ( value ) ) );
}


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
    while ( !_parameters.isEmpty ( ) ) {
        delete _parameters.takeFirst ( );
    }
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
QJsonValue OperationFieldBase::parametersJson ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::setParametersJson ( QJsonValue parameters ) {
    emit setParametersDetected ( parameters );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QList<Base::ParameterFieldBase *> OperationFieldBase::parameters ( ) const {
    return _parameters;
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

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool OperationFieldBase::isParameterAlreadyExist ( ParameterFieldBase *parameter ) {
    if ( !parameter ) {
        return false;
    }
    for ( Base::ParameterFieldBase *addedParameter : _parameters ) {
        if ( addedParameter && ( addedParameter->name ( ) == parameter->name ( ) ) ) {
            return true;
        }
    }
    return false;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void OperationFieldBase::addParameter ( ParameterFieldBase *parameter ) {
    if ( !parameter ) {
        qWarning ( ) << "Can't add parameter. Input object is null";
        return;
    }
    if ( parameter->name ( ).isNull ( ) ) {
        qWarning ( ) << "Can't add parameter. Name of parameter is not set";
        return;
    }
    _parameters.append ( parameter );
}

} // Base
} // Swagger
