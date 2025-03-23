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

double Polygon::chatGptMagicFormula(QLineF line, QPointF center)
{
    QPointF point1 = line.p1();
    QPointF point2 = line.p2();
    double op1 = fabs((point2.x()-point1.x())*(center.y()-point1.y()) - (center.x()-point1.x())*(point2.y()-point1.y()));
    double op2 = sqrt(pow((point2.x()-point1.x()),2) + pow((point2.y()-point1.y()),2) );
    return op1/op2;
}

Polygon::Polygon(QList<QPointF> points) {
    _points = points;
    QPointF pointsSum = QPointF(0,0);
    for (QPointF &point : _points){
        pointsSum += point;

    }
    _center = pointsSum/_points.size();
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

void Polygon::moveTo(QPointF newCenter)
{
    QPointF diff = newCenter - _center;
    for (QPointF &point : _points){
        point += diff;

    }
    _center += diff;
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

double Polygon::getSmallestDistanceForPoint(QPointF point)
{
    double min = chatGptMagicFormula(_linesForDraw.first(), point);
    for (int i = 1; i < _linesForDraw.size(); i++){
        double thisValue=chatGptMagicFormula(_linesForDraw[i],point);
        if (thisValue<min){
            min =thisValue;
        }
    }
    return min;

}

QLineF Polygon::getNearestLineForPoint(QPointF point)
{
    double min = 1;
    double minValue = chatGptMagicFormula(_linesForDraw[0],point);
    for (int i = 1; i < _linesForDraw.size(); i++){
        if (chatGptMagicFormula(_linesForDraw[i],point)<minValue){
            min = i;
            minValue = chatGptMagicFormula(_linesForDraw[i],point);
        }
    }
    return _linesForDraw[min];

}

PhysicsPolygon::PhysicsPolygon(QList<QPointF> points, QPointF speed, double rotateSpeed):Polygon(points), _speed(speed), _rotateSpeed(rotateSpeed)
{

}

void PhysicsPolygon::moveAtSpeed(double tics)
{
    moveAt(_speed * tics);
}

void PhysicsPolygon::rotateAtSpeed(double tics)
{
    rotate(_rotateSpeed*tics);
}
