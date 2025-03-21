#ifndef ITEM_H
#define ITEM_H
#include <QPainter>

class Item
{
public:
    virtual void draw(QPainter  &painter) = 0;
    virtual void move(int tic) = 0;
    virtual bool isPointIn(const QPointF &point) = 0;
    virtual void setSpeed(QPointF speed) = 0;
    virtual bool isIntersectsWithRect(QRectF & rect) = 0;
    virtual QRectF getRect() = 0;
    virtual void rotateSpeed() = 0;
};

enum Shape{
    Ellipse, Rect
};



#endif // ITEM_H
