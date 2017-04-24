/**
  * \file     SwaggerFieldBase.h
  * \author   m.lamparski
  * \date     2017-04-05 -> $Date$
  * \version  $Revision$
  * \brief    File with base class for all Swagger Field Type objects

*/
#ifndef SWAGGERFIELDBASE_H
#define SWAGGERFIELDBASE_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>
#include <QDebug>
#include <QJsonValue>

namespace Swagger {
namespace Base {

/// \brief The SwaggerFieldBase -> base class for all Swagger Field Type objects
class SwaggerFieldBase : public QObject {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit SwaggerFieldBase ( QObject *parent = 0 );
    ~SwaggerFieldBase ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    // - property
    /// \brief AnnotationKeyword -> swagger annotation keyword
    static const QString AnnotationKeyword;

    /// \brief isFieldAlreadySet -> return information is field properties already set
    virtual bool isFieldAlreadySet ( ) const = 0;
    /// \brief clear -> clear properties of current field
    virtual void clear ( ) = 0;

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

protected:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property

};

} // Base
} // Swagger


#endif // SWAGGERFIELDBASE_H
