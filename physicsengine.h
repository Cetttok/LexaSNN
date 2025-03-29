#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "ball.h"
#include "polygon.h"
#include <QObject>
class PhysicsEngine : public QObject

{
Q_OBJECT
protected:
    Ball _ball;
    MarkedPhysicsPolygon _polygon;
    bool iSBallIntersectPolygon();
    bool checkIntersects();
    void reactIntersects();

public:
    PhysicsEngine(Ball ball, MarkedPhysicsPolygon polygon);
    void makeTic();
    Ball * ball();
    MarkedPhysicsPolygon * polygon();
signals:
    void onBallTouchMark();
};

#endif // PHYSICSENGINE_H
