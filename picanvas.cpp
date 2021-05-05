#include "picanvas.h"
#include "ui_picanvas.h"

PiCanvas::PiCanvas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PiCanvas)
{
    ui->setupUi(this);
}

PiCanvas::~PiCanvas()
{
    delete ui;
}

