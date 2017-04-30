#ifndef SWAGGERJSONSERIALIZER_H
#define SWAGGERJSONSERIALIZER_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>
#include <QMetaProperty>
#include <QJsonObject>
#include <QJsonArray>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <Swagger.h>

namespace Swagger {
namespace Core {

class SwaggerJsonSerializer : public QObject {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit SwaggerJsonSerializer ( Data::Swagger &swagger, QObject *parent = 0 );
    ~SwaggerJsonSerializer ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief serialize -> serialize actual _swagger object to json object
    void serialize ( );

    // - property
    /// \brief swaggerJson -> return swagger json object
    QJsonObject swaggerJson ( ) const;

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _swagger -> root object of swagger document
    Data::Swagger *_swagger = nullptr;
    /// \brief _swaggerJson -> swagger json object
    QJsonObject _swaggerJson;
    /// \brief _pathsJson -> objest with paths
    QJsonObject _pathsJson;
    /// \brief _currentOperation -> operation currently added to json
    Base::OperationFieldBase *_currentOperation = nullptr;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief _clearJsonObject -> clearing passed json object
    void _clearJsonObject ( QJsonObject &object );
    /// \brief _createSwaggerRootJsonObject -> creating root swagger json object
    void _createSwaggerRootJsonObject ( );
    /// \brief _addInfoToSwaggerJson -> add info to swagger json object
    void _addInfoToSwaggerJson ( );
    /// \brief _addSchemesToSwaggerJson -> add schemes to swagger json object
    void _addSchemesToSwaggerJson ( );
    /// \brief _addPathsToSwaggerJson -> add paths to swagger json object
    void _addPathsToSwaggerJson ( );
    /// \brief _addOperationToPathsJson -> add single operation for paths in swagger
    void _addOperationToPathsJson ( );
    /// \brief _createOperationJson -> creating operation json object
    QJsonObject _createOperationJson ( );

};

} // Core
} // Swagger

#endif // SWAGGERJSONSERIALIZER_H
