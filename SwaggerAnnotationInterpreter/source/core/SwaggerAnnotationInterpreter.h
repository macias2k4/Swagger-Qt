/**
  * \file     SwaggerAnnotationInterpreter.h
  * \author   m.lamparski
  * \date     2017-04-05 -> $Date$
  * \version  $Revision$
  * \brief    Main class of library to interprate Swagger annotation written in source code in set
  * path

*/
#ifndef SWAGGERANNOTATIONINTERPRETER_H
#define SWAGGERANNOTATIONINTERPRETER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger
#include "swaggerannotationinterpreter_global.h"

namespace Swagger {

/// \brief SwaggerAnnotationInterpreter -> main class of library
class SWAGGERANNOTATIONINTERPRETERSHARED_EXPORT SwaggerAnnotationInterpreter : public QObject {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    SwaggerAnnotationInterpreter ( );
    ~SwaggerAnnotationInterpreter ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    // - property

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property

};

} // Swagger

#endif // SWAGGERANNOTATIONINTERPRETER_H
