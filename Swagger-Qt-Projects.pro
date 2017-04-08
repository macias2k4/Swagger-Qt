TEMPLATE = subdirs

CONFIG += ordered

# aplikacje budowane na koniec
SUBDIRS += \
    $$PWD/SwaggerAnnotationInterpreter \                                                            # library to interprate Swagger annotation written in source code in set path
    $$PWD/SwaggerQt                                                                                 # console application, using SwaggerApi library

