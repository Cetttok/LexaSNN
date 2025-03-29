#include "widget.h"
#include <QDebug>
const int TIC_INTERVAL = 60;

Widget::Widget(int width, int height, QWidget *parent):QWidget(parent),mField(Field(width,height))
{
    //_ticTimer.setInterval(TIC_INTERVAL);
    _ticTimer = new QTimer();
    resize(width,height);
    QObject::connect(_ticTimer, SIGNAL(timeout()), this, SLOT(everyTic()));
    _ticTimer->start(TIC_INTERVAL);
    QObject::connect(&mField._engine, SIGNAL(onBallTouchMark()), this, SLOT(onBallTouchMark()));
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    mField.draw(painter);
    QPen pen = QPen(Qt::blue);
    painter.end();

}

void Widget::everyTic()
{
    //qDebug() << "helo";
    repaint();
    mField.onTic();
}

void Widget::onBallTouchMark()
{
    qDebug() << "remake!!!";
}

