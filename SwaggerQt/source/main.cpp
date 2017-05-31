#include <QCoreApplication>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerQt.h>

int main ( int argc, char *argv[] ) {
    QCoreApplication a ( argc, argv );
    Swagger::Core::SwaggerQt swaggerQt;
//    swaggerQt.setSourceCodeFilesPath ( "/media/lampart/data/projekty/source/Qt/Swagger-Qt/SwaggerQt" );
//    swaggerQt.setSourceCodeFilesPath ( "/media/lampart/data/projekty/source/Qt/PxVS/c++/PxVS-DataProvider" );
//    swaggerQt.setSourceCodeFilesPath ( "/media/lampart/data/projekty/source/Qt/PxVS/c++/PxVS-Compiler" );
    swaggerQt.setSourceCodeFilesPath ( "/media/lampart/data/projekty/source/Qt/PxVS/c++/PxVS-DataAccessServer" );
    swaggerQt.generateSwaggerFile ( );
    return a.exec ( );
}
