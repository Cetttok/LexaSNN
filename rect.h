#ifndef RECT_H
#define RECT_H

#include "item.h"

class Rect : public Item
{
protected:
    QRect _rect;
    bool _solid;
    int _tickness;
    QColor _color;
    QPoint _speed;
public:
    const Shape mShape;
    Rect(QRect rect, int tickness,QColor color, Shape shape, bool solid,QPoint speed = QPoint(0,0)) ; // tickness has to (tickness%2 == 1)
    void draw(QPainter& painter);
    void move(int tic);
    bool isPointIn(const QPoint& point);
    void setSpeed(QPoint speed);
    bool isIntersectsWithRect(QRect & rect);
    void rotateSpeed();
    QRect getRect();
};

#endif // RECT_H
