#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QPointF>


class Ball
{
protected:
    QPointF _center;
    int _radius;
    QPointF _speed;
public:
    Ball(QPointF center, int radius, QPointF speed = QPointF(0,0));
    void moveTo(QPointF newPoint);
    void moveAt(QPointF diff);
    void moveAtSpeed(double tic = 1);
    void speedSwap(QLineF atLine);
    void draw(QPainter & painter, QPen & pen);
    QPointF center() const;

    int radius() const;
};

#endif // BALL_H
