#include "piobject.h"

PiObject::PiObject(QWidget *parent) : QWidget(parent), xMouse(0), yMouse(0)
{
    header = new QFrame(this, Qt::Widget);
    header->setObjectName("PiHeader");
    header->setLineWidth(frameWidth);
    header->setMidLineWidth(frameWidth);
    header->setFrameStyle(QFrame::Box | QFrame::Plain);
    header->setStyleSheet("#PiHeader { border: " + QString::number(frameWidth) + "px solid black; background-color: white }");
    header->setAutoFillBackground(true);
    header->move(0, 0);
    header->resize(width(), log(height()) / log(10) * headerCoef);
    header->setCursor(Qt::OpenHandCursor);

    body = new QFrame(this, Qt::Widget);
    body->setObjectName("PiBody");
    body->setLineWidth(frameWidth);
    body->setMidLineWidth(frameWidth);
    body->setFrameStyle(QFrame::Box | QFrame::Plain);
    body->setStyleSheet("#PiBody {  border: " + QString::number(frameWidth) + "px solid black; background-color: white }");
    body->setAutoFillBackground(true);
    body->move(0, header->height() - frameWidth);
    body->resize(width(), height() - header->height() + frameWidth);

    setMinimumSize(minWidth, minHeight);
    resize(minWidth, minHeight);

    corner = new PiCorner(this);
    corner->setSize(3 * frameWidth);
    corner->setPos(width() - frameWidth, height() - frameWidth);
    corner->setCursor(Qt::SizeFDiagCursor);

    qDebug() << "PiObject created";
}


void PiObject::resizeEvent(QResizeEvent *event)
{
    header->resize(event->size().width(), log(event->size().height()) / log(10) * headerCoef);

    body->move(0, header->height() - frameWidth);
    body->resize(event->size().width(), event->size().height() - header->height() + frameWidth);

    corner->setPos(event->size().width() - frameWidth, event->size().height() - frameWidth);

    raise();
    qDebug() << event->size();
}

void PiObject::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        if(event->pos().x() <= header->width() && event->pos().y() <= header->height())
        {
            qDebug() << "CloseHandCursor set";
            header->setCursor(Qt::ClosedHandCursor);
            xMouse = event->globalPos().x() - x();
            yMouse = event->globalPos().y() - y();
        }
        break;
    default: break;
    }
    raise();
    qDebug() << "mousePressEvent";
}

void PiObject::mouseMoveEvent(QMouseEvent *event)
{
    if(header->cursor().shape() == Qt::ClosedHandCursor)
    {
        qDebug() << "move Header";

        QWidget::move(event->globalPos().x() - xMouse, event->globalPos().y() - yMouse);
    }
    else
        header->setCursor(Qt::OpenHandCursor);
    qDebug() << "mouseMoveEvent";
}

void PiObject::mouseReleaseEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        //if(event->pos().x() <= header->width() && event->pos().y() <= header->height())
            header->setCursor(Qt::OpenHandCursor);
        break;
    default: break;
    }
    qDebug() << "mouseReleaseEvent";
}
