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
    /// \brief fieldName -> return name of field implementing by derivative class
    virtual QString fieldName ( ) const = 0;

    // - property

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
