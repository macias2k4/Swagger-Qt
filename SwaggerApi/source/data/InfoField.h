#ifndef INFOFIELD_H
#define INFOFIELD_H

#include <QObject>

class InfoField : public QObject
{
    Q_OBJECT
public:
    explicit InfoField(QObject *parent = 0);

signals:

public slots:
};

#endif // INFOFIELD_H