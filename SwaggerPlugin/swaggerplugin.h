#pragma once

#include "swagger_global.h"

#include <extensionsystem/iplugin.h>

namespace Swagger {
namespace Internal {

class SwaggerPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Swagger.json")

public:
    SwaggerPlugin();
    ~SwaggerPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace Swagger
