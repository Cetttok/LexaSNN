#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "ball.h"
#include "polygon.h"
class PhysicsEngine
{
protected:
    Ball _ball;
    PhysicsPolygon _polygon;
    bool iSBallIntersectPolygon();
    bool checkIntersects();
    void reactIntersects();

public:
    PhysicsEngine(Ball ball, PhysicsPolygon polygon);
    void makeTic();
    Ball * ball();
    PhysicsPolygon * polygon();

};

#endif // PHYSICSENGINE_H
