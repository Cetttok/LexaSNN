#include "physicsengine.h"



bool PhysicsEngine::iSBallIntersectPolygon()
{
    if (_polygon.getSmallestDistanceForPoint(_ball.center())< _ball.radius()){
        return true;
    }
    return false;
}

bool PhysicsEngine::checkIntersects()
{

    if (iSBallIntersectPolygon()){
        return true;
    }
    return false;

}

void PhysicsEngine::reactIntersects()
{
    _ball.speedSwap(_polygon.getNearestLineForPoint(_ball.center()));
}


PhysicsEngine::PhysicsEngine(Ball ball, MarkedPhysicsPolygon polygon): _ball(ball), _polygon(polygon)
{

}

void PhysicsEngine::makeTic()
{
    _ball.moveAtSpeed();
    if (checkIntersects()){
        //_ball.moveAtSpeed(-1);
        reactIntersects();
        _ball.moveAtSpeed(1);

    }
    _polygon.moveAtSpeed();
    _polygon.rotateAtSpeed();
    _polygon.moveMark(1);
}

Ball *PhysicsEngine::ball()
{
    return & _ball;
}

MarkedPhysicsPolygon *PhysicsEngine::polygon()
{
    return  & _polygon;
}



