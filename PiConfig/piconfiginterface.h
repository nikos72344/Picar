#ifndef PICONFIGINTERFACE_H
#define PICONFIGINTERFACE_H

#include <QtPlugin>

#define PiConfigInterface_iid "ru.spbstu.Picar.PiConfig/1.0"

class PiConfigInterface
{

public:
     virtual bool setPath(QString* path) = 0;
     virtual bool readConfig(void) = 0;
     virtual const QMap<const QString*, const QStringList*>* getValues(void) = 0;
     virtual bool setValues(QMap<const QString*, const QStringList*>* data) = 0;
     virtual bool writeConfig(void) = 0;
};

Q_DECLARE_INTERFACE(PiConfigInterface, PiConfigInterface_iid)

#endif // PICONFIG_H
