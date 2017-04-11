#include "SwaggerFiller.h"

namespace Swagger {
namespace Core {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerFiller::SwaggerFiller ( Data::Swagger &swagger, QObject *parent )
    : QObject   ( parent ),
      _swagger  ( &swagger ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerFiller::~SwaggerFiller ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::fill ( const QString &annotationName, const QJsonObject &annotationContent ) {
    // fill _swagger object fields by received annotationContent
    QString fieldName = _extractFieldNameFromAnnotationName ( annotationName );
    if ( fieldName.isEmpty ( ) ) {
        _setLastErrorMessage ( QString ( "Incorrect annotationName '%1'" ).arg ( annotationName ) );
        return;
    }
    if ( !this->setProperty ( fieldName.toLatin1 ( ).data ( ), annotationContent ) ) {
        _setLastErrorMessage ( QString ( "Can't set value of field '%1'" ).arg ( fieldName  ) );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString SwaggerFiller::_extractFieldNameFromAnnotationName ( const QString &annotationName ) {
    QString annotationPrefix = QString ( "%1." ).arg ( Base::SwaggerFieldBase::AnnotationKeyword );
    if ( !annotationName.startsWith ( annotationPrefix ) ) {
        return QString ( );
    }
    return QString ( annotationName ).remove ( 0, annotationPrefix.length ( ) );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_setLastErrorMessage ( const QString &message ) {
    _lastErrorMessage = message;
    qWarning ( ) << _ModuleName << message;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonObject SwaggerFiller::swagger ( ) const {
    return QJsonObject ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::setSwagger ( QJsonObject swagger ) {
    _fillSwaggerField ( *_swagger, swagger );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::_fillSwaggerField ( Base::SwaggerFieldBase &swaggerField,
                                        const QJsonObject &annotationContent ) {
    QStringList keys = annotationContent.keys ( );
    QString fieldName = QString ( );
    for ( QString key : keys ) {
        // extract to sub method !
        fieldName = _extractFieldNameFromAnnotationName ( key );
        QJsonValue value = annotationContent.value ( key );
        if ( fieldName.isEmpty ( ) ) {
            if ( value.isArray ( ) ) {
                QVariantList list = value.toArray ( ).toVariantList ( );
                swaggerField.setProperty ( key.toLatin1 ( ).data ( ), list );
            } else {
                swaggerField.setProperty ( key.toLatin1 ( ).data ( ), value );
            }
        } else {
            this->setProperty ( fieldName.toLatin1 ( ).data ( ), value );
        }
    }
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QJsonValue SwaggerFiller::Info ( ) const {
    return QJsonValue ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerFiller::setInfo ( QJsonValue Info ) {
    if ( !Info.isObject ( ) ) {
        _setLastErrorMessage ( "Can't set Info field, in parammeter is not a QJsonObject" );
        return;
    }
    _fillSwaggerField ( _swagger->infoField ( ), Info.toObject ( ) );
}

} // Core
} // Swagger
