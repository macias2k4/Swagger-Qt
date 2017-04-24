#include "ParameterDefaultField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ParameterDefaultField::ParameterDefaultField ( QObject *parent )
    : Swagger::Base::ParameterFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ParameterDefaultField::~ParameterDefaultField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ParameterDefaultField::isFieldAlreadySet ( ) const {
    return !_name.isEmpty ( ) && !_in.isEmpty ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::clear ( ) {
    ParameterFieldBase::clear ( );
    _type = QString ( );
    _format = QString ( );
    _allowEmptyValue = false;
    _collectionFormat = _acceptableCollectionFormat [ 0 ];
    _maximum = 0;
    _exclusiveMaximum = true;
    _minimum = 0;
    _exclusiveMinimum = true;
    _maxLength = 0;
    _minLength = 0;
    _pattern = QString ( );
    _maxItems = 0;
    _minItems = 0;
    _uniqueItems = false;
    _multipleOf = 0;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// property
QString ParameterDefaultField::type ( ) const {
    return _type;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setType ( QString type ) {
    if ( _type == type ) {
        return;
    }
    _type = type;
    emit typeChanged ( type );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ParameterDefaultField::format ( ) const {
    return _format;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setFormat ( QString format ) {
    if ( _format == format ) {
        return;
    }
    _format = format;
    emit formatChanged ( format );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ParameterDefaultField::allowEmptyValue ( ) const {
    return _allowEmptyValue;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setAllowEmptyValue ( bool allowEmptyValue ) {
    if ( _allowEmptyValue == allowEmptyValue ) {
        return;
    }
    _allowEmptyValue = allowEmptyValue;
    emit allowEmptyValueChanged ( allowEmptyValue );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ParameterDefaultField::collectionFormat ( ) const {
    return _collectionFormat;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setCollectionFormat ( QString collectionFormat ) {
    if ( _collectionFormat == collectionFormat ) {
        return;
    }
    _collectionFormat = collectionFormat;
    emit collectionFormatChanged ( collectionFormat );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
double ParameterDefaultField::maximum ( ) const {
    return _maximum;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setMaximum ( double maximum ) {
    if ( _maximum == maximum ) {
        return;
    }
    _maximum = maximum;
    emit maximumChanged ( maximum );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ParameterDefaultField::exclusiveMaximum ( ) const {
    return _exclusiveMaximum;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setExclusiveMaximum ( bool exclusiveMaximum ) {
    if ( _exclusiveMaximum == exclusiveMaximum ) {
        return;
    }
    _exclusiveMaximum = exclusiveMaximum;
    emit exclusiveMaximumChanged ( exclusiveMaximum );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
double ParameterDefaultField::minimum ( ) const {
    return _minimum;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setMinimum ( double minimum ) {
    if ( _minimum == minimum ) {
        return;
    }
    _minimum = minimum;
    emit minimumChanged ( minimum );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ParameterDefaultField::exclusiveMinimum ( ) const {
    return _exclusiveMinimum;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setExclusiveMinimum ( bool exclusiveMinimum ) {
    if ( _exclusiveMinimum == exclusiveMinimum ) {
        return;
    }
    _exclusiveMinimum = exclusiveMinimum;
    emit exclusiveMinimumChanged ( exclusiveMinimum );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
qint32 ParameterDefaultField::maxLength ( ) const {
    return _maxLength;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setMaxLength ( qint32 maxLength ) {
    if ( _maxLength == maxLength ) {
        return;
    }
    _maxLength = maxLength;
    emit maxLengthChanged ( maxLength );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
qint32 ParameterDefaultField::minLength ( ) const {
    return _minLength;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setMinLength ( qint32 minLength ) {
    if ( _minLength == minLength ) {
        return;
    }
    _minLength = minLength;
    emit minLengthChanged ( minLength );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
QString ParameterDefaultField::pattern ( ) const {
    return _pattern;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setPattern ( QString pattern ) {
    if ( _pattern == pattern ) {
        return;
    }
    _pattern = pattern;
    emit patternChanged ( pattern );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
qint32 ParameterDefaultField::maxItems ( ) const {
    return _maxItems;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setMaxItems ( qint32 maxItems ) {
    if ( _maxItems == maxItems ) {
        return;
    }
    _maxItems = maxItems;
    emit maxItemsChanged ( maxItems );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
qint32 ParameterDefaultField::minItems ( ) const {
    return _minItems;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setMinItems ( qint32 minItems ) {
    if ( _minItems == minItems ) {
        return;
    }
    _minItems = minItems;
    emit minItemsChanged ( minItems );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ParameterDefaultField::uniqueItems ( ) const {
    return _uniqueItems;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setUniqueItems ( bool uniqueItems ) {
    if ( _uniqueItems == uniqueItems ) {
        return;
    }
    _uniqueItems = uniqueItems;
    emit uniqueItemsChanged ( uniqueItems );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
double ParameterDefaultField::multipleOf ( ) const {
    return _multipleOf;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ParameterDefaultField::setMultipleOf ( double multipleOf ) {
    if ( _multipleOf == multipleOf ) {
        return;
    }
    _multipleOf = multipleOf;
    emit multipleOfChanged ( multipleOf );
}

} // Data
} // Swagger
