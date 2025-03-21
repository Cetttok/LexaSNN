#include <QApplication>
#include "rect.h"
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w(400, 300);
   // w.mField.addItem(new class Rect(QRectF(20, 20, 40, 80), 1, Qt::black, Shape::Rect, true));
   // w.mField.addItem(new class Rect(QRectF(20, 100, 100, 40), 1, Qt::yellow, Shape::Rect, true));
   // w.mField.addItem(new class Rect(QRectF(120, 20, 40, 120), 1, Qt::blue, Shape::Rect, true));
   // w.mField.addItem(new class Rect(QRectF(60, 20, 60, 40), 1, Qt::green, Shape::Rect, true));
   // w.mField.addItem(
     //   new class Rect(QRectF(80, 80, 10, 10), 1, Qt::red, Shape::Ellipse, true, QPointF(-1, -1)));

    w.show();
    return a.exec();
}
