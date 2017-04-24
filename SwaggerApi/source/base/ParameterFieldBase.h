/**
  * \file     ParameterFieldBase.h
  * \author   m.lamparski
  * \date     2017-04-24
  * \brief    File with base class for parameter object

*/
#ifndef PARAMETERFIELDBASE_H
#define PARAMETERFIELDBASE_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerFieldBase.h>

namespace Swagger {
namespace Base {

/// \brief ParameterFieldBase -> base class for parameter object, it can by use in Operation
class ParameterFieldBase : Base::SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY ( QString in READ in WRITE setIn NOTIFY inChanged )
    Q_PROPERTY ( QString description READ description WRITE setDescription NOTIFY descriptionChanged )
    Q_PROPERTY ( bool required READ required WRITE setRequired NOTIFY requiredChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit ParameterFieldBase ( QObject *parent = 0 );
    ~ParameterFieldBase ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    /// \brief clear -> clear properties of current field
    virtual void clear ( ) override;

    // - property

    QString name ( ) const;
    void setName ( QString name );

    QString in ( ) const;
    void setIn ( QString in );

    QString description ( ) const;
    void setDescription ( QString description );

    bool required ( ) const;
    void setRequired ( bool required );


signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void nameChanged ( QString name );
    void inChanged ( QString in );
    void descriptionChanged ( QString description );
    void requiredChanged ( bool required );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots


protected:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _name -> Required. The name of the parameter. Parameter names are case sensitive
    QString _name = QString ( );
    /// \brief _in -> Required. The location of the parameter.
    QString _in = QString ( );
    /// \brief _acceptableIn -> Possible values for _in property
    const QStringList _acceptableIn = { "query", "header", "path", "formData", "body" };
    /// \brief _description -> A brief description of the parameter. This could contain examples of use
    QString _description = QString ( );
    /// \brief _required -> Determines whether this parameter is mandatory. If the parameter is
    /// in "path", this property is required and its value MUST be true
    bool _required = false;

};

} // Base
} // Swagger

#endif // PARAMETERFIELDBASE_H
