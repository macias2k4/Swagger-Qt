TEMPLATE = subdirs

CONFIG += ordered

# aplikacje budowane na koniec
SUBDIRS += \
    $$PWD/SwaggerApi \                                                                              # library for Swagger
    $$PWD/SwaggerQt \                                                                               # console application, using SwaggerApi library
    $$PWD/SwaggerPlugin/SwaggerPlugin.pro                                                           # plugin Swagger do Qt Creator'a

