#include "widget.h"
#include <QDebug>
const int TIC_INTERVAL = 50;

Widget::Widget(int width, int height, QWidget *parent):QWidget(parent),mField(Field(width,height))
{
    //_ticTimer.setInterval(TIC_INTERVAL);
    _ticTimer = new QTimer();
    resize(width,height);
    QObject::connect(_ticTimer, SIGNAL(timeout()), this, SLOT(everyTic()));
    _ticTimer->start(TIC_INTERVAL);
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
    mPolygon.draw(painter, pen);
    painter.end();
    mPolygon.rotate(0.07);
    mPolygon.moveAt(QPointF(0.3,0.3));

}

void Widget::everyTic()
{
    qDebug() << "helo";
    repaint();
    mField.onTic();
}

