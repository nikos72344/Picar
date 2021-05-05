#ifndef PIOBJECT_H
#define PIOBJECT_H

#include "picorner.h"

#include <QWidget>
#include <QFrame>
#include <QResizeEvent>
#include <QMouseEvent>
#include <cmath>

class PiObject : public QWidget
{
    Q_OBJECT
private:
    int xMouse, yMouse;

    PiCorner* corner;

protected:
    static const unsigned int frameWidth = 3;
    static const unsigned int headerCoef = 5;
    static const unsigned int minWidth = 180, minHeight = 3 * minWidth / 2;

    QFrame* header;
    QFrame* body;

    virtual void resizeEvent(QResizeEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
public:
    explicit PiObject(QWidget *parent = nullptr);

signals:

};

#endif // PIOBJECT_H
