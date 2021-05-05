#include "piconfig.h"

PiConfig::PiConfig(QObject *parent)
    : QObject(parent), configFile(new QFile), configData(new QMap<const QString*, const QStringList*>)
{
}

bool PiConfig::setPath(QString* path)
{
    configFile->setFileName(*path);
    return true;
}

bool PiConfig::readConfig(void)
{
    qDeleteAll(*configData);
    configData->clear();
    if(!configFile->exists())
        return false;
    if(!configFile->open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    while(true)
    {
        char buffer[1024];
        qint64 lineLenghth = configFile->readLine(buffer, sizeof (buffer) / sizeof (char));
        if(lineLenghth <= 0)
            break;
        if(!parseLine(buffer))
        {
            configFile->close();
            return false;
        }
    }
    configFile->close();
    return true;
}

bool PiConfig::parseLine(char buffer[])
{
    QString line(buffer);
    QStringList lineContent = line.split(' ', Qt::SkipEmptyParts);
    if(lineContent.isEmpty())
        return false;
    QString* token = new QString(lineContent.takeFirst());
    QStringList* values = new QStringList(lineContent);
    configData->insert(token, values);
    return true;
}

const QMap<const QString*, const QStringList*>* PiConfig::getValues(void)
{
    return configData;
}

bool PiConfig::setValues(QMap<const QString *, const QStringList *> *data)
{
    qDeleteAll(*configData);
    *configData = *data;
    return true;
}

bool PiConfig::writeConfig(void)
{
    bool flag = false;
    if(!configFile->open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    for(const QString* key: configData->keys())
    {
        if(flag)
            configFile->write("\n");
        configFile->write(key->toUtf8());
        flag = true;
        const QStringList* values = configData->value(key);
        for(QString value: *values)
            configFile->write(' ' + value.toUtf8());
    }
    configFile->close();
    return true;
}

PiConfig::~PiConfig()
{
    qDeleteAll(*configData);
    delete configFile;
    delete configData;
}
