#include "rect.h"
#include <QDebug>
Rect::Rect(QRect rect, int tickness, QColor color, Shape shape, bool solid, QPoint speed):
    _rect(rect), _tickness(tickness),_color(color), mShape(shape), _solid(solid), _speed(speed)
{

}

void Rect::draw(QPainter &painter)
{

    if (_solid){
        QPen pen = QPen(_color);
        pen.setWidth(_tickness);
        painter.setPen(pen);

        painter.setBrush(QBrush(_color));
    }
    else{
        QPen pen = QPen(_color);
        painter.setBrush(QBrush());
        pen.setWidth(_tickness);
        painter.setPen(pen);
    }
    switch(mShape){
    case Shape::Rect:
        painter.drawRect(_rect);
        break;
    case Shape::Ellipse:
        painter.drawEllipse(_rect);
        break;
    }
}

void Rect::move(int tic)
{
    qDebug() << "tic";
    _rect.moveCenter(_rect.center()+(_speed*tic));

}
void Rect::setSpeed(QPoint speed){
    _speed= speed;
}

bool Rect::isIntersectsWithRect(QRect &rect)
{
    return _rect.intersects(rect);
}

void Rect::rotateSpeed()
{
    _speed *= -1;
}

QRect Rect::getRect()
{
    return _rect;
}

bool Rect::isPointIn(const QPoint &point)
{
    if (_solid){
        return _rect.contains(point);
    }
    else{
        if (!_rect.contains(point)){
            return false;
        }
        else{
            int ticknessRad = int ((_tickness-1)/2);
            if (point.x() > (_rect.bottomLeft().x()+ticknessRad)  && point.x() < (_rect.bottomRight().x() -  ticknessRad)
                && point.y() > (_rect.bottomLeft().y() + ticknessRad)
                && point.y() < (_rect.topLeft().x() - ticknessRad)){
                return false;
            }
            else{
                return true;
            }
        }
    }
}




