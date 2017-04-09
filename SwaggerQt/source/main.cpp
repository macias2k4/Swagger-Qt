#include <QCoreApplication>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <SwaggerQt.h>

int main ( int argc, char *argv[] ) {
    QCoreApplication a ( argc, argv );
    Swagger::Core::SwaggerQt swaggerQt;
    swaggerQt.setSourceCodeFilesPath ( "/media/lampart/data/projekty/source/Qt/Swagger-Qt/SwaggerQt" );
    swaggerQt.generateSwaggerFile ( );
    return a.exec();
}