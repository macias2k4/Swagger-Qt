#pragma once

#include <QtGlobal>

#if defined(SWAGGER_LIBRARY)
#  define SWAGGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SWAGGERSHARED_EXPORT Q_DECL_IMPORT
#endif
