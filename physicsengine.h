#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "ball.h"
#include "polygon.h"
class PhysicsEngine
{
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

};

#endif // PHYSICSENGINE_H
