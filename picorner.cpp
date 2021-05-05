#include "picorner.h"

PiCorner::PiCorner(QWidget *parent) : QFrame(parent, Qt::Widget), flag(false)
{
    setFrameStyle(QFrame::Box | QFrame::Plain);
    setMidLineWidth(3);
    setLineWidth(3);
    setStyleSheet("background-color: rgb(0, 0, 0);");
}

void PiCorner::setSize(int size)
{
    resize(size, size);
}

void PiCorner::setPos(int x, int y)
{
    move(x - width() / 2, y - height() / 2);
}

void PiCorner::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        qDebug() << "Mouse set";
        flag = true;
        break;
    default: break;
    }
}

void PiCorner::mouseMoveEvent(QMouseEvent *event)
{
    if(flag)
    {
        QWidget* parent = parentWidget();
        if(parent == nullptr)
            return;

        QPoint pPoint = parent->mapToGlobal(QPoint(0, 0));
        QPoint pSize(abs(event->globalPos().x() - pPoint.x()), abs(event->globalPos().y() - pPoint.y()));
        qDebug() << pSize;

        /*if(event->globalPosition().x() < pPoint.x())
        {
            pPoint.setX(event->globalPosition().x());
            pSize.setX(pSize.x() + parent->width());
        }
        if(event->globalPosition().y() < pPoint.y())
        {
            pPoint.setY(event->globalPosition().y());
            pSize.setY(pSize.y() + parent->height());
        }
        parent->move(parent->mapToParent(parent->mapFromGlobal(pPoint)));*/
        parent->resize(pSize.x(), pSize.y());
    }
}

void PiCorner::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse reset";
    flag = false;
}
