DEFINES += SWAGGER_LIBRARY

# Swagger files
include($$PWD/source/source.pri)
#include($$PWD/../SwaggerApi/source/source.pri)

# link library: SwaggeerApi
#LIBS += -L$$OUT_PWD/../SwaggerApi -lSwaggerApi

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SwaggerApi/release/ -lSwaggerApi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SwaggerApi/debug/ -lSwaggerApi
else:unix: LIBS += -L$$OUT_PWD/../SwaggerApi/ -lSwaggerApi

INCLUDEPATH += $$PWD/../SwaggerApi
DEPENDPATH += $$PWD/../SwaggerApi

LIBS += -L../projectexplorer \
        -lProjectExplorer

# Qt Creator linking

## Either set the IDE_SOURCE_TREE when running qmake,
## or set the QTC_SOURCE environment variable, to override the default setting
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = $$(QTC_SOURCE)
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = "/media/lampart/data/projekty/source/Qt/qtcreator-src"

## Either set the IDE_BUILD_TREE when running qmake,
## or set the QTC_BUILD environment variable, to override the default setting
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = "/media/lampart/data/projekty/build/Qt/qtcreator"

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on OS X
# USE_USER_DESTDIR = yes

###### If the plugin can be depended upon by other plugins, this code needs to be outsourced to
###### <dirname>_dependencies.pri, where <dirname> is the name of the directory containing the
###### plugin's sources.

QTC_PLUGIN_NAME = Swagger
QTC_LIB_DEPENDS += \
    # nothing here at this time

QTC_PLUGIN_DEPENDS += \
    coreplugin

QTC_PLUGIN_RECOMMENDS += \
    # optional plugin dependencies. nothing here at this time

###### End _dependencies.pri contents ######

include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)

