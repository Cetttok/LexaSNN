#ifndef RECT_H
#define RECT_H

#include "item.h"

class Rect : public Item
{
protected:
    QRectF _rect;
    bool _solid;
    int _tickness;
    QColor _color;
    QPointF _speed;
public:
    const Shape mShape;
    Rect(QRectF rect, int tickness,QColor color, Shape shape, bool solid,QPointF speed = QPointF(0,0)) ; // tickness has to (tickness%2 == 1)
    void draw(QPainter& painter);
    void move(int tic);
    bool isPointIn(const QPointF& point);
    void setSpeed(QPointF speed);
    bool isIntersectsWithRect(QRectF & rect);
    void rotateSpeed();
    QRectF getRect();
};

#endif // RECT_H
