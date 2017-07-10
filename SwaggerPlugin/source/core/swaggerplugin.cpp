#include "swaggerplugin.h"
#include "swaggerconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

namespace SwaggerPlg {
namespace Internal {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerPlugin::SwaggerPlugin ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SwaggerPlugin::~SwaggerPlugin ( ) {
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool SwaggerPlugin::initialize ( const QStringList &arguments, QString *errorString ) {
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.
    Q_UNUSED ( arguments )
    Q_UNUSED ( errorString )
    QAction *generateApiAction = new QAction ( tr ( "Generate Swagger API for current project" ), this );
    Core::Command *cmd = Core::ActionManager::registerAction ( generateApiAction, Constants::ACTION_ID,
                         Core::Context ( Core::Constants::C_GLOBAL ) );
    cmd->setDefaultKeySequence ( QKeySequence ( tr ( "Ctrl+Alt+Meta+A" ) ) );
    connect ( generateApiAction, &QAction::triggered, this, &SwaggerPlugin::_generateSwaggerApiForCurrentProject );
    Core::ActionContainer *menu = Core::ActionManager::createMenu ( Constants::MENU_ID );
    menu->menu ( )->setTitle ( tr ( "Swagger" ) );
    menu->addAction ( cmd );
    Core::ActionManager::actionContainer ( Core::Constants::M_TOOLS )->addMenu ( menu );
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerPlugin::extensionsInitialized ( ) {
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ExtensionSystem::IPlugin::ShutdownFlag SwaggerPlugin::aboutToShutdown ( ) {
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerPlugin::_generateSwaggerApiForCurrentProject ( ) {
    if ( !ProjectExplorer::ProjectTree::currentProject ( ) ) {
        QMessageBox::information ( Core::ICore::mainWindow ( ),
                                   tr ( "Swagger warning" ),
                                   tr ( "Can't generate Swagger API for current project. No project has been opened." ) );
        return;
    }
    QString sourcePath = ProjectExplorer::ProjectTree::currentProject ( )->projectDirectory ( ).toString ( );
    _swaggerApi.setSourceCodeFilesPath ( sourcePath );
    _createOutputDirectoryForSwaggerApi ( );
    if ( !_isOutputDirectoryForSwaggerExist ) {
        QMessageBox::information ( Core::ICore::mainWindow ( ),
                                   tr ( "Swagger warning" ),
                                   tr ( "Can't create Swagger API output directory %1" ).arg( _SwaggerOutputDirectoryName ) );
        return;
    }
    _swaggerApi.setOutputDocumentationPath ( QString ( "%1/%2" ).arg ( sourcePath ).arg ( _SwaggerOutputDirectoryName ) );
    _swaggerApi.interprete ( );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SwaggerPlugin::_createOutputDirectoryForSwaggerApi ( ) {
    _isOutputDirectoryForSwaggerExist = true;
    if ( QDir ( QString ( "%1/%2" ).arg ( _swaggerApi.sourceCodeFilesPath ( ) ).arg ( _SwaggerOutputDirectoryName ) ).exists ( ) ) {
        return;
    }
    _isOutputDirectoryForSwaggerExist = QDir ( _swaggerApi.sourceCodeFilesPath ( ) ).mkdir ( _SwaggerOutputDirectoryName );
}

} // namespace Internal
} // namespace Swagger
