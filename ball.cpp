#include "ball.h"
#include <qdebug.h>

QPointF Ball::center() const
{
    return _center;
}

int Ball::radius() const
{
    return _radius;
}

Ball::Ball(QPointF center, int radius, QPointF speed):_center(center), _radius(radius), _speed(speed)
{

}

void Ball::moveTo(QPointF newPoint)
{
    _center = newPoint;
}

void Ball::moveAt(QPointF diff)
{
    _center+= diff;
}

void Ball::moveAtSpeed(double tic)
{
    _center += _speed*tic;
    //qDebug() << _speed;
}
QPointF chatGptSpeedMagicFormula(QLineF line, QPointF speed){
    double x1 = line.p2().x();
    double x2 = line.p1().x();
    double y1 = line.p2().y();
    double y2 = line.p1().y();

    double   yn=(x1-x2)/pow(( pow(x1-x2,2)+pow(y1-y2,2)  ),0.5);
    double  xn=(y2-y1)/pow( pow(x1-x2,2)+pow(y1-y2,2),0.5);
    double  resultY =speed.y()-2*yn*(( xn*speed.x() + yn*speed.y()) );
    double  resultX=speed.x()-2*xn*( (xn*speed.x()+ yn*speed.y() ));
    return QPointF(resultX,resultY);
    // double y = speed.y();
    // double x = speed.x();
    // double n = ( line.p2().y()-line.p1().y() )/( line.p2().x()-line.p1().x() );
    // //double k = (- 1*y*( 1-pow(n,2) ) + 2*x*n )/( x*( 1-pow(n,2) ) + 2*y*n );
    // double k = tan( atan(-y/x) + 2*atan(n) );
    // double resultX   = -1*sqrt((pow(y,2)+pow(x,2)/(pow(k,2)+1) ));
    // double resultY = resultX * k;
    // qDebug() << resultX;
    // qDebug()  <<  resultY;
    // return QPointF (resultX,resultY);
   // return QPointF(speed.y(),speed.x() );
    // QPointF normal = QPointF( line.p1().y()-line.p2().y(),line.p2().x()-line.p1().x());
    // double normalLen = sqrt(pow(normal.x(),2)+pow(normal.y(),2));
    // QPointF result = (speed - 2 * (QPointF::dotProduct(speed,normal) / pow(normalLen,2)) * normal);
    // qDebug() << result;
    // return result;
}
void Ball::speedSwap(QLineF atLine)
{

    _speed = chatGptSpeedMagicFormula(atLine,_speed);
}

void Ball::draw(QPainter &painter, QPen &pen)
{
    painter.setPen(pen);
    painter.drawEllipse(_center,_radius,_radius);
}
