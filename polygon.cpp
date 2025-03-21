#include "polygon.h"

#include <QDebug>

void Polygon::updatelines()
{
    _linesForDraw.clear();
    for (int i = 0; i < _points.size()-1; i++){
        _linesForDraw.append(QLineF(_points[i],_points[i+1]));
    }
    _linesForDraw.append(QLineF(_points.last(),_points.first()));
}

Polygon::Polygon(QList<QPointF> points, QPointF center) {
    _points = points;
    _center = center;
    updatelines();
}

void Polygon::moveAt(QPointF diff)
{
    for (QPointF &point : _points){
        point += diff;
    }
    _center += diff;
    updatelines();
}

void Polygon::draw(QPainter &painter, QPen &pen)
{
    painter.setPen(pen);
    for (QLineF &line : _linesForDraw){
        painter.drawLine(line);
    }
}

void Polygon::rotate(double atAngle)
{
    for (QPointF &point : _points){
        double newX = _center.x() + (point.x()- _center.x())*cos(atAngle) - (point.y()-_center.x())*sin(atAngle);
        double newY = _center.y() + (point.y()- _center.y())*cos(atAngle) + (point.x()-_center.x())*sin(atAngle);
        point = QPointF(newX, newY);
    }

    updatelines();
}

void Polygon::debug()
{
    qDebug() << "Polygon. Points:";
    for (QPointF &point : _points){
        qDebug() << point;
    }
    qDebug() << "";

}
