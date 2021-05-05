#include "picalc.h"

PiCalc::PiCalc(QWidget *parent) : PiObject(parent)
{
    QFont font("Arciform");

    input = new QLineEdit(body);
    input->setObjectName("PiInput");
    input->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QPalette pal(body->palette());
    pal.setColor(QPalette::Base, Qt::transparent);
    input->setPalette(pal);
    input->setStyleSheet("#PiInput { border: " + QString::number(frameWidth) + "px solid black; color: black; selection-background-color: black } ");
    input->setFrame(false);
    input->move(0, 0);
    input->resize(width(), log(height()) / log(10) * fieldCoef);
    font.setPixelSize(input->height() - 2 * frameWidth);
    input->setFont(font);

    QObject::connect(input, SIGNAL(returnPressed()), this, SLOT(doCalc()));

    answer = new QLineEdit(body);
    answer->setObjectName("PiAnswer");
    answer->setFont(font);
    answer->setReadOnly(true);
    answer->setPalette(pal);
    answer->setFrame(false);
    answer->setStyleSheet("#PiAnswer { border: " + QString::number(frameWidth) + "px solid black; color: black; selection-background-color: black }");
    answer->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    answer->resize(input->size());
    answer->move(0, height() - answer->height() - header->height() + frameWidth);

    label = new QLabel("PiCalc", body, Qt::Widget);
    label->setObjectName("PiCalcLabel");
    label->setFont(font);
    label->setStyleSheet("#PiCalcLabel { color: black }");
    //label->setFrameStyle(QFrame::Box | QFrame::Plain);
    label->setAlignment(Qt::AlignCenter);
    label->resize(input->size());
    label->move(0, answer->y() - label->height() - frameWidth);
}

void PiCalc::doCalc(){
    QByteArray ba = input->text().toLocal8Bit();
    unsigned int error = 0;
    double result = symbol_processing(ba.data(), 0, ba.size(), &error);
    if(error == 0)
        qDebug()<<result;
    else
        qDebug()<<"error!";
    if(error == 0)
        answer->setText(QString::number(result));
    else
        answer->setText("Error");
}

void PiCalc::mousePressEvent(QMouseEvent *event){
    PiObject::mousePressEvent(event);

    switch (event->button()) {
    case Qt::LeftButton:
        input->setFocus();
        break;
    }
}

void PiCalc::resizeEvent(QResizeEvent *event){
    PiObject::resizeEvent(event);

    input->resize(event->size().width(), log(event->size().height()) / log(10) * fieldCoef);

    QFont font("Arciform");
    font.setPixelSize(input->height() - 2 * frameWidth);
    input->setFont(font);

    answer->resize(input->size());
    answer->move(0, height() - answer->height() - header->height() + frameWidth);
    answer->setFont(font);

    label->resize(input->size());
    label->move(0, answer->y() - label->height() - frameWidth);
    label->setFont(font);
}
