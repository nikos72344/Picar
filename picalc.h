#ifndef PICALC_H
#define PICALC_H

#include "piobject.h"
#include "PiCalcCore/core.h"
#include <QtWidgets>
#include <QFrame>

class PiCalc: public PiObject
{
    Q_OBJECT
private:
    static const unsigned int fieldCoef = 25;

    QLineEdit* input;
    QLineEdit* answer;
    QLabel* label;

protected:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void resizeEvent(QResizeEvent* event);

public:
    PiCalc(QWidget *parent = nullptr);

private slots:
    void doCalc();
};

#endif // PICALC_H
