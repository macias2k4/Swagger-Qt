/**
  * \file     SwaggerJsonSerializer.h
  * \author   m.lamparski
  * \date     2017-05-01
  * \brief    File with class serializing Swagger object into QJonObject

*/
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
#include <ParameterDefaultField.h>

namespace Swagger {
namespace Core {

/// \brief JsonSerializer -> class to serialize Swagger object into QJonObject
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
    /// \brief _currentOperation -> operation currently adding to json
    Base::OperationFieldBase *_currentOperation = nullptr;
    /// \brief _currentParameter -> parameter currently adding to json
    Base::ParameterFieldBase *_currentParameter = nullptr;
    /// \brief _currentResponse -> response currently adding to json
    Data::ResponseField *_currentResponse = nullptr;

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
    /// \brief _addJsonArrayToJsonObject -> adding QJsonArray into QJsonObject
    void _addJsonArrayToJsonObject ( QJsonObject &object, QString inputKey, const QStringList &inputValues );
    /// \brief _addParametersForCurrentOperation -> adding parameters for operation currently adding
    /// to json
    void _addParametersForCurrentOperation ( QJsonObject &operationJson );
    /// \brief _addCurrentParameterToParametersJson -> adding current parameter for operation currently
    /// adding to json
    void _addCurrentParameterToParametersJson ( QJsonArray &parameters );
    /// \brief _extendParameterByDefaultParameterProperties -> extending parameter json object by
    /// Default (in different then 'body') _currentParameter property
    void _extendParameterByDefaultParameterProperties ( QJsonObject &parameter );
    /// \brief _addResponsesForCurrentOperation -> adding responses for operation currently adding
    /// to json
    void _addResponsesForCurrentOperation ( QJsonObject &operationJson );
    /// \brief _addCurrentResponseToResponsesJson -> adding current response for operation currently
    /// adding to json
    void _addCurrentResponseToResponsesJson ( QJsonObject &responses );

};

} // Core
} // Swagger

#endif // SWAGGERJSONSERIALIZER_H