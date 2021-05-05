#ifndef PICONFIG_H
#define PICONFIG_H

#include "piconfiginterface.h"

#include <QFile>
#include <QMap>

class PiConfig : public QObject, public PiConfigInterface
{
    Q_OBJECT
    Q_INTERFACES(PiConfigInterface)
    Q_PLUGIN_METADATA(IID PiConfigInterface_iid FILE "PiConfig.json")

private:
    QFile* configFile;
    QMap<const QString*, const QStringList*>* configData;

    bool parseLine(char buffer[]);

public:
    explicit PiConfig(QObject *parent = nullptr);
    ~PiConfig();

    bool setPath(QString* path);
    bool readConfig(void);
    const QMap<const QString*, const QStringList*>* getValues(void);
    bool setValues(QMap<const QString*, const QStringList*>* data);
    bool writeConfig(void);
};

#endif // PICONFIG_H
