#include "widget.h"
#include "rect.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w(400,300);
    w.mField.addItem(new class Rect(QRect(20,20,40,80), 1,Qt::black, Shape::Rect, true) );
    w.mField.addItem(new class Rect(QRect(20,100,100,40), 1,Qt::yellow, Shape::Rect, true) );
    w.mField.addItem(new class Rect(QRect(120,20,40,120), 1,Qt::blue, Shape::Rect, true) );
    w.mField.addItem(new class Rect(QRect(60,20,60,40), 1,Qt::green, Shape::Rect, true) );
    w.mField.addItem(new class Rect(QRect(80,80,10,10), 1,Qt::red, Shape::Ellipse, true, QPoint(-1,-1)) );

    w.show();
    return a.exec();
}
