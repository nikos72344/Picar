#ifndef PICANVAS_H
#define PICANVAS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PiCanvas; }
QT_END_NAMESPACE

class PiCanvas : public QWidget
{
    Q_OBJECT

public:
    PiCanvas(QWidget *parent = nullptr);
    ~PiCanvas();

private:
    Ui::PiCanvas *ui;
};
#endif // PICANVAS_H
