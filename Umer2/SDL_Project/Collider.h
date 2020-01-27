#include "Ball.h"
#pragma once
class Collider
{
private:




public:
	static bool SphereSphereCollision(const Ball& ball_1, const Ball& ball2);
	static void SphereSphereCollisionResponse(Ball& ball1, Ball& ball2);

};

