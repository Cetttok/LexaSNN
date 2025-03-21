#ifndef POLYGON_H
#define POLYGON_H
#include <QPointF>
#include <QList>
#include <QPainter>
class Polygon
{
protected:
    QList<QPointF> _points = QList<QPointF>();
    QPointF _center;
    QList<QLineF> _linesForDraw;
    void updatelines();
public:
    Polygon(QList<QPointF> points);
    void moveAt(QPointF diff);
    void draw(QPainter &painter,  QPen &pen);
    void rotate(double atAngle);
    void debug();

};

#endif // POLYGON_H
