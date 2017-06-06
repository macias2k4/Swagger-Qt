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
#include <ParameterDefaultField.h>
#include <ParameterInBodyField.h>

namespace Swagger {
namespace Core {

/// \brief SwaggerFiller -> class to fill Swagger object by annotations from source code files
class SwaggerFiller : public QObject {
    Q_OBJECT
    Q_PROPERTY ( QJsonValue Swagger READ emptyJsonObject WRITE setSwagger )
    Q_PROPERTY ( QJsonValue Info READ emptyJsonObject WRITE setInfo )
    Q_PROPERTY ( QJsonValue Get READ emptyJsonObject WRITE setGet )
    Q_PROPERTY ( QJsonValue Post READ emptyJsonObject WRITE setPost )
    Q_PROPERTY ( QJsonValue Definition READ emptyJsonObject WRITE setDefinition )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit SwaggerFiller ( Data::Swagger &swagger, QObject *parent = 0 );
    ~SwaggerFiller ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    // - property

    QJsonValue emptyJsonObject ( ) const;
    void setSwagger ( QJsonValue swagger );

    void setInfo ( QJsonValue Info );

    // -- operations
    void setGet ( QJsonValue Get );

    void setPost ( QJsonValue Post );

    // -- definitions
    void setDefinition ( QJsonValue Definition );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots
    /// \brief fill -> fill correct swagger field by annotationContent
    void fill ( const QString &annotationName, const QJsonValue &annotationContent );

private slots:
    // - operations
    /// \brief _addOperationParameters -> adding parameters objects to operation object (sender)
    void _addOperationParameters ( QJsonValue parameters );
    /// \brief _fillSchemaFromJson -> fill sended schema object parameters from json
    void _fillSchemaFromJson ( Data::SchemaField *schema, QJsonValue schemaValue );
    /// \brief _addSchemaProperties -> adding properties objects to schema object (sender)
    void _addSchemaProperties (  QJsonValue properties );
    /// \brief _addOperationResponses -> adding responses objects to operation object (sender)
    void _addOperationResponses ( QJsonValue responses );

    // - definitions
    /// \brief _addDefinitionProperties -> adding properties objects to definition object (sender)
    void _addDefinitionProperties ( QJsonValue properties );
    /// \brief _fillItemsFromJson -> fill sended items object parameters from json
    void _fillItemsFromJson ( Data::ItemsField *items, QJsonValue itemsValue );

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _ModuleName -> name of module
    const QString _ModuleName = "<SwaggerFiller>";
    /// \brief _swagger -> root object of swagger document
    Data::Swagger *_swagger = nullptr;
    /// \brief _lastErrorMessage -> last error message
    QString _lastErrorMessage = QString ( );
    /// \brief _currentOperation -> operation, into which parameters and responses are adding
    Base::OperationFieldBase *_currentOperation = nullptr;
    /// \brief _currentSchema -> schema, into which properties are adding
    Data::SchemaField *_currentSchema = nullptr;
    /// \brief _currentSchemaPropertyName -> name of current adding property to current Schema
    QString _currentSchemaPropertyName = QString ( );
    /// \brief _currentDefinition -> definition, into which properties are adding
    Data::DefinitionField *_currentDefinition = nullptr;
    /// \brief _currentDefinitionPropertyName -> name of current adding property to current Definition
    QString _currentDefinitionPropertyName = QString ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief _extractFieldNameFromAnnotationName -> extracring filed name from annotation name
    QString _extractFieldNameFromAnnotationName ( const QString &annotationName );
    /// \brief _setLastErrorMessage -> set error message
    void _setLastErrorMessage ( const QString &message );

    /// \brief _fillSwaggerField -> fill swagger 'advanced' field
    void _fillSwaggerField ( Base::SwaggerFieldBase &swaggerField,
                             const QJsonObject &annotationContent );

    // - operations
    /// \brief _addOperationParameter -> adding single parameter into current operation
    void _addOperationParameter ( const QJsonValue &parameterValue );
    /// \brief _addOperationResponse -> adding single response into current operation
    void _addOperationResponse ( const QString &responseKey, const QJsonValue &responseValue );

    // -- schema

    // - definitions
    /// \brief _addSchemaProperty -> adding current Property objects to current Schema object
    void _addSchemaProperty ( QJsonValue propertyValue );

    // - definitions
    /// \brief _addDefinitionProperty -> adding current property objects to current definition object
    void _addDefinitionProperty ( QJsonValue propertyValue );

};


} // Core
} // Swagger

#endif // SWAGGERFILLER_H
