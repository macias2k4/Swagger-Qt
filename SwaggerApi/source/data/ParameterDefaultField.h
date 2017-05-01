/**
  * \file     ParameterDefaultField.h
  * \author   m.lamparski
  * \date     2017-04-24
  * \brief    File with parameter object, with 'in' field value oder then 'body'

*/
#ifndef PARAMETERDEFAULTFIELD_H
#define PARAMETERDEFAULTFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <ParameterFieldBase.h>

namespace Swagger {
namespace Data {

/// \brief ParameterDefaultField -> Parameter object, with 'in' field value oder then 'body'
class ParameterDefaultField : public Base::ParameterFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString type READ type WRITE setType NOTIFY typeChanged )
    Q_PROPERTY ( QString format READ format WRITE setFormat NOTIFY formatChanged )
    Q_PROPERTY ( bool allowEmptyValue READ allowEmptyValue WRITE setAllowEmptyValue NOTIFY
                 allowEmptyValueChanged )
    // items to add
    Q_PROPERTY ( QString collectionFormat READ collectionFormat WRITE setCollectionFormat NOTIFY
                 collectionFormatChanged )
    Q_PROPERTY ( double maximum READ maximum WRITE setMaximum NOTIFY maximumChanged )
    Q_PROPERTY ( bool exclusiveMaximum READ exclusiveMaximum WRITE setExclusiveMaximum NOTIFY
                 exclusiveMaximumChanged )
    Q_PROPERTY ( double minimum READ minimum WRITE setMinimum NOTIFY minimumChanged )
    Q_PROPERTY ( bool exclusiveMinimum READ exclusiveMinimum WRITE setExclusiveMinimum NOTIFY
                 exclusiveMinimumChanged )
    Q_PROPERTY ( qint32 maxLength READ maxLength WRITE setMaxLength NOTIFY maxLengthChanged )
    Q_PROPERTY ( qint32 minLength READ minLength WRITE setMinLength NOTIFY minLengthChanged )
    Q_PROPERTY ( QString pattern READ pattern WRITE setPattern NOTIFY patternChanged )
    Q_PROPERTY ( qint32 maxItems READ maxItems WRITE setMaxItems NOTIFY maxItemsChanged )
    Q_PROPERTY ( qint32 minItems READ minItems WRITE setMinItems NOTIFY minItemsChanged )
    Q_PROPERTY ( bool uniqueItems READ uniqueItems WRITE setUniqueItems NOTIFY uniqueItemsChanged )
    // enum
    Q_PROPERTY ( double multipleOf READ multipleOf WRITE setMultipleOf NOTIFY multipleOfChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit ParameterDefaultField ( QObject *parent = 0 );
    ~ParameterDefaultField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    /// \brief isFieldAlreadySet -> return information is field properties already set
    virtual bool isFieldAlreadySet ( ) const override;
    /// \brief clear -> clear properties of current field
    virtual void clear ( ) override;

    // - property

    QString type ( ) const;
    void setType ( QString type );

    QString format ( ) const;
    void setFormat ( QString format );

    bool allowEmptyValue ( ) const;
    void setAllowEmptyValue ( bool allowEmptyValue );

    QString collectionFormat ( ) const;
    void setCollectionFormat ( QString collectionFormat );

    double maximum ( ) const;
    void setMaximum ( double maximum );

    bool exclusiveMaximum ( ) const;
    void setExclusiveMaximum ( bool exclusiveMaximum );

    double minimum ( ) const;
    void setMinimum ( double minimum );

    bool exclusiveMinimum ( ) const;
    void setExclusiveMinimum ( bool exclusiveMinimum );

    qint32 maxLength ( ) const;
    void setMaxLength ( qint32 maxLength );

    qint32 minLength ( ) const;
    void setMinLength ( qint32 minLength );

    QString pattern ( ) const;
    void setPattern ( QString pattern );

    qint32 maxItems ( ) const;
    void setMaxItems ( qint32 maxItems );

    qint32 minItems ( ) const;
    void setMinItems ( qint32 minItems );

    bool uniqueItems ( ) const;
    void setUniqueItems ( bool uniqueItems );

    double multipleOf ( ) const;
    void setMultipleOf ( double multipleOf );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void typeChanged ( QString type );
    void formatChanged ( QString format );
    void allowEmptyValueChanged ( bool allowEmptyValue );
    void collectionFormatChanged ( QString collectionFormat );
    void maximumChanged ( double maximum );
    void exclusiveMaximumChanged ( bool exclusiveMaximum );
    void minimumChanged ( double minimum );
    void exclusiveMinimumChanged ( bool exclusiveMinimum );
    void maxLengthChanged ( qint32 maxLength );
    void minLengthChanged ( qint32 minLength );
    void patternChanged ( QString pattern );
    void maxItemsChanged ( qint32 maxItems );
    void minItemsChanged ( qint32 minItems );
    void uniqueItemsChanged ( bool uniqueItems );
    void multipleOfChanged ( double multipleOf );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots


private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _acceptableType -> Possible values for _type property
    QStringList _acceptableType = { "string", "number", "integer", "boolean", "array", "file" };
    /// \brief _type -> Required. The type of the parameter
    QString _type = QString ( );
    /// \brief _format -> The extending format for the previously mentioned type
    QString _format = QString ( );
    /// \brief _allowEmptyValue -> Sets the ability to pass empty-valued parameters
    bool _allowEmptyValue = false;
    /// \brief _acceptableCollectionFormat -> Possible values for _collectionFormat property
    QStringList _acceptableCollectionFormat = { "csv", "ssv", "tsv", "pipes", "multi" };
    /// \brief _collectionFormat -> Determines the format of the array if type array is used
    QString _collectionFormat = _acceptableCollectionFormat [ 0 ];
    /// \brief _maximum -> maximum value of parameter
    double _maximum = 0;
    /// \brief _exclusiveMaximum -> exclusive maximum value
    bool _exclusiveMaximum = true;
    /// \brief _minimum -> minimum value of parameter
    double _minimum = 0;
    /// \brief _exclusiveMinimum -> exclusive minimum value
    bool _exclusiveMinimum = true;
    /// \brief _maxLength -> maximum length
    qint32 _maxLength = 0;
    /// \brief _minLength -> minimum length
    qint32 _minLength = 0;
    /// \brief _pattern -> pattern
    QString _pattern = QString ( );
    /// \brief _maxItems -> maximum number of items
    qint32 _maxItems = 0;
    /// \brief _minItems -> minimum number of items
    qint32 _minItems = 0;
    /// \brief _uniqueItems -> unique items
    bool _uniqueItems = false;
    /// \brief _multipleOf -> multiple of
    double _multipleOf = 0;

};

} // Data
} // Swagger

#endif // PARAMETERDEFAULTFIELD_H
