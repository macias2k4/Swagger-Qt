#pragma once

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <projectexplorer/projecttree.h>
#include <projectexplorer/project.h>
#include <utils/fileutils.h>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include "swagger_global.h"
#include <extensionsystem/iplugin.h>
#include <SwaggerApi.h>

// namespace can't be Swagger .. if it's compiler try to find 'Core::Command' i SwaggerApi
namespace SwaggerPlg {
namespace Internal {

class SwaggerPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Swagger.json")

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    SwaggerPlugin();
    ~SwaggerPlugin();

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

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
    ///
    /// \brief _SwaggerOutputDirectoryName -> name of Swagger documentation API output directory
    const QString _SwaggerOutputDirectoryName = "swaggerApi";

    /// \brief _swaggerApi -> object of swagger-Qt api library
    Swagger::Core::SwaggerApi _swaggerApi;
    /// \brief _outputDirectoryForSwagger ->
    QString _outputDirectoryForSwagger;
    /// \brief _isOutputDirectoryForSwaggerExist -> keep information is output direcotry for Swagger
    /// API exist
    bool _isOutputDirectoryForSwaggerExist = false;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    ///
    /// \brief _generateSwaggerApiForCurrentProject -> try to generate Swagger API documentation for
    /// current open project
    void _generateSwaggerApiForCurrentProject ( );
    /// \brief _createOutputDirectoryForSwaggerApi -> creating output directory for Swagger API
    void _createOutputDirectoryForSwaggerApi ( );

};

} // namespace Internal
} // namespace Swagger
