#ifndef PICORNER_H
#define PICORNER_H

#include <QWidget>
#include <QMouseEvent>
#include <QFrame>
#include <QApplication>
#include <QDebug>

class PiCorner : public QFrame
{
    Q_OBJECT
private:
    bool flag;

protected:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);

public:
    explicit PiCorner(QWidget *parent = nullptr);
    void setSize(int size);
    void setPos(int x, int y);
};

#endif // PICORNER_H
