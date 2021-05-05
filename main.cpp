#include "picanvas.h"
#include "piobject.h"
#include "picalc.h"

#include <QApplication>
#include <QFrame>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*PiCanvas w;
    PiObject* one = new PiObject(&w);
    one->setMinimumSize(100, 50);
    one->resize(500, 100);
    PiObject* two = new PiObject(&w);
    two->setMinimumSize(50, 50);
    QFrame* frOne = new QFrame(one);
    frOne->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    //frOne->setLineWidth(3);
    //frOne->setMidLineWidth(4);
    QFrame* frTwo = new QFrame(two);
    frTwo->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    //frTwo->setLineWidth(3);
    //frTwo->setMidLineWidth(4);
    QVBoxLayout* lay = new QVBoxLayout(&w);
    lay->addWidget(one);
    lay->addStretch(5);
    lay->addWidget(two);
    w.setLayout(lay);
    w.setMinimumSize(one->minimumWidth() + two->minimumWidth(), one->minimumHeight() + two->minimumHeight());
    w.show();*/
    /*QWidget* w = new QWidget;
    w->resize(500, 500);
    w->setMinimumSize(500, 500);
    QFrame* fr = new QFrame(w, Qt::Widget);
    fr->setFrameStyle(QFrame::Box | QFrame::Plain);
    fr->setLineWidth(3);
    fr->setMidLineWidth(3);
    fr->resize(450, 450);
    fr->move(25, 25);
    w->show();*/
    QWidget* w = new QWidget;
    PiObject* p1 = new PiObject(w);
    /*PiObject* p2 = new PiObject(w);
    PiObject* p3 = new PiObject(w);*/
    PiCalc* c1 = new PiCalc(w);
    PiCalc* c2 = new PiCalc(w);
    w->resize(1000, 500);
    w->show();

    /*PiCorner* c = new PiCorner;
    c->setSize(100);
    c->setCursor(Qt::SizeBDiagCursor);
    c->show();*/
    return a.exec();
}
