#ifndef SWAGGERJSONSERIALIZER_H
#define SWAGGERJSONSERIALIZER_H

#include <QObject>

class SwaggerJsonSerializer : public QObject
{
    Q_OBJECT
public:
    explicit SwaggerJsonSerializer(QObject *parent = 0);

signals:

public slots:
};

#endif // SWAGGERJSONSERIALIZER_H