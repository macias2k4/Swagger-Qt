/**
  * \file     SwaggerFiller.h
  * \author   m.lamparski
  * \date     2017-04-09
  * \brief    File with class to fill Swagger object by annotations from source code files

*/
#ifndef SWAGGERFILLER_H
#define SWAGGERFILLER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <Swagger.h>

namespace Swagger {
namespace Core {

/// \brief SwaggerFiller -> class to fill Swagger object by annotations from source code files
class SwaggerFiller : public QObject {
    Q_OBJECT
    Q_PROPERTY ( QJsonValue Swagger READ swagger WRITE setSwagger )
    Q_PROPERTY ( QJsonValue Info READ Info WRITE setInfo )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit SwaggerFiller ( Data::Swagger &swagger, QObject *parent = 0 );
    ~SwaggerFiller ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    // - property

    QJsonValue swagger ( ) const;
    void setSwagger ( QJsonValue swagger );

    QJsonValue Info ( ) const;
    void setInfo ( QJsonValue Info );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots
    /// \brief fill -> fill correct swagger field by annotationContent
    void fill ( const QString &annotationName, const QJsonValue &annotationContent );


private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _ModuleName -> name of module
    const QString _ModuleName = "<SwaggerFiller>";
    /// \brief _swagger -> root object of swagger document
    Data::Swagger *_swagger = nullptr;
    /// \brief _lastError -> last error message
    QString _lastErrorMessage = QString ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief _extractFieldNameFromAnnotationName -> extracring filed name from annotation name
    QString _extractFieldNameFromAnnotationName ( const QString &annotationName );
    /// \brief _setLastErrorMessage -> set error message
    void _setLastErrorMessage ( const QString &message );

    /// \brief _fillSwaggerField -> fill swagger 'advanced' field
    void _fillSwaggerField ( Base::SwaggerFieldBase &swaggerField,
                             const QJsonObject &annotationContent );
};


} // Core
} // Swagger

#endif // SWAGGERFILLER_H
