#ifndef POLYGON_H
#define POLYGON_H
#include <QPointF>
#include <QList>
#include <QPainter>
class Polygon
{
private:
    double lexaMagicFormula(QLineF line, QPointF center);
protected:
    QList<QPointF> _points = QList<QPointF>();
    QPointF _center;
    QList<QLineF> _linesForDraw;
    void updatelines();
public:
    Polygon(QList<QPointF> points);
    void moveAt(QPointF diff);
    void moveTo(QPointF newCenter);
    void draw(QPainter &painter,  QPen &pen);
    void rotate(double atAngle);
    void debug();
    double getSmallestDistanceForPoint(QPointF point);
    QLineF getNearestLineForPoint(QPointF point);

};


class PhysicsPolygon: public Polygon
{
private:
    QPointF _speed;
    double  _rotateSpeed;

public:

    PhysicsPolygon(QList<QPointF> points, QPointF speed = QPointF(0,0), double rotateSpeed = 0);
    void moveAtSpeed(double tics = 1);
    void rotateAtSpeed(double tics = 1);
};


class MarkedPhysicsPolygon: public PhysicsPolygon
{
private:
    QLineF transposeLine(QLineF &line);
protected:
    QList<QLineF> _markLines;
    double _markLen;
    QList<double >_polygonLen;
    double _markPlace;
    int _allPolygonLen;
public:
    void moveMark(int on);
    MarkedPhysicsPolygon(QList<QPointF> points,int markLen, QPointF speed = QPointF(0,0), double rotateSpeed = 0);
   // void moveAt(QPointF diff);
    //void moveTo(QPointF newCenter);
    void draw(QPainter &painter,  QPen &polyPen, QPen &markPen);
    //void rotate(double atAngle);
    void updateMark();

     

};

#endif // POLYGON_H
