#ifndef ITEM_H
#define ITEM_H
#include <QPainter>

class Item
{
public:
    virtual void draw(QPainter  &painter) = 0;
    virtual void move(int tic) = 0;
    virtual bool isPointIn(const QPoint &point) = 0;
    virtual void setSpeed(QPoint speed) = 0;
    virtual bool isIntersectsWithRect(QRect & rect) = 0;
    virtual QRect getRect() = 0;
    virtual void rotateSpeed() = 0;
};

enum Shape{
    Ellipse, Rect
};



#endif // ITEM_H
