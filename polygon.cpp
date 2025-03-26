#include "polygon.h"

#include <QDebug>

void Polygon::updatelines()
{
    _linesForDraw.clear();
    for (int i = 0; i < _points.size()-1; i++){
        // if (i == 0){
        //     _linesForDraw.append(QLineF(_points[i+1],_points[i]));
        // }
        _linesForDraw.append(QLineF(_points[i],_points[i+1]));
    }
    _linesForDraw.append(QLineF(_points.last(),_points.first()));
}

double Polygon::lexaMagicFormula(QLineF line, QPointF center)
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
    double min = lexaMagicFormula(_linesForDraw.first(), point);
    for (int i = 1; i < _linesForDraw.size(); i++){
        double thisValue=lexaMagicFormula(_linesForDraw[i],point);
        if (thisValue<min){
            min =thisValue;
        }
    }
    return min;

}

QLineF Polygon::getNearestLineForPoint(QPointF point)
{
    double min = 0;
    double minValue = lexaMagicFormula(_linesForDraw[0],point);
    for (int i = 1; i < _linesForDraw.size(); i++){
        if (lexaMagicFormula(_linesForDraw[i],point)<minValue){
            min = i;
            minValue = lexaMagicFormula(_linesForDraw[i],point);
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

QLineF MarkedPhysicsPolygon::transposeLine(QLineF &line)
{
    return QLineF(line.p2(),line.p1());
}

void MarkedPhysicsPolygon::moveMark(int on)
{

    _markPlace += on;
    updateMark();
}

void MarkedPhysicsPolygon::moveMarkAtSpeed(double tics)
{
    _markPlace += int(_markSpeed*tics);
    updateMark();
}

MarkedPhysicsPolygon::MarkedPhysicsPolygon(QList<QPointF> points, int markLen, QPointF speed, double rotateSpeed, int markSpeed):PhysicsPolygon(points,speed,rotateSpeed), _markLen(markLen),_markSpeed(markSpeed)
{
    _allPolygonLen = 0;
    _polygonLen = QList<double>();
    for (int i = 0; i < _linesForDraw.size(); i++){
        _polygonLen.append(_linesForDraw[i].length());
        _allPolygonLen += _linesForDraw[i].length();

    }

    _markPlace =0;
    updateMark();

}

void MarkedPhysicsPolygon::draw(QPainter &painter, QPen &polyPen, QPen &markPen)
{
    PhysicsPolygon::draw(painter,polyPen);
    painter.setPen(markPen);
    for (QLineF &line : _markLines){
        painter.drawLine(line);
    }

}

void MarkedPhysicsPolygon::updateMark()
{
    _markLines = QList<QLineF> ();
    _markPlace = int(_markPlace)%(_allPolygonLen);
    double markLenRemain = _markLen;
    double markPlaceRemain = _markPlace;


    while(markLenRemain>  1){
        for (int i = 0; i < _polygonLen.size(); i++){
            if (_polygonLen[i] <= markPlaceRemain){
                markPlaceRemain -= _polygonLen[i];
                continue;
            }
            else if (_polygonLen[i] <= (markPlaceRemain + markLenRemain)){
                QLineF someMarkLine = transposeLine(_linesForDraw[i]);
                someMarkLine.setLength((_polygonLen[i]-markPlaceRemain));
                markLenRemain -= (_polygonLen[i]-markPlaceRemain);
                someMarkLine.setLength(_polygonLen[i]-markPlaceRemain);
                markPlaceRemain = 0;
                _markLines.append(someMarkLine);
                continue;
            }

            else if(_polygonLen[i] >= (markPlaceRemain + markLenRemain)){
                QLineF someMarkLine = transposeLine(_linesForDraw[i]);
                someMarkLine.setLength(_polygonLen[i]- markPlaceRemain);
                someMarkLine = transposeLine(someMarkLine);
                someMarkLine.setLength(markLenRemain);
                //someMarkLine.setLength(_polygonLen[i]-markPlaceRemain);
                //someMarkLine = transposeLine(someMarkLine);
                markLenRemain = 0;
                markPlaceRemain = 0;
                _markLines.append(someMarkLine);
                break;
            }
            else{
                qDebug() << "heloe";
                //int i = 1/0;
            }
        }
    }





}


