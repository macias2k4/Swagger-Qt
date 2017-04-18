#include "SwaggerFieldBase.h"

namespace Swagger {
namespace Base {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerFieldBase::SwaggerFieldBase ( QObject *parent )
    : QObject ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerFieldBase::~SwaggerFieldBase ( ) {
}

const QString SwaggerFieldBase::AnnotationKeyword = "@Swg";

} // Base
} // Swagger
