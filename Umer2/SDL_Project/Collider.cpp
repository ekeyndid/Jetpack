#include "Collider.h"
#include "VMath.h"
#include "Vector.h"


bool Collider::SphereSphereCollision(const Ball& ball_1, const Ball& ball2)
{
	float dist = VMath::distance(ball_1.pos, ball2.pos);

	if (dist < (ball_1.r + ball2.r)) {
		return true;
	}
	return false;
}

void Collider::SphereSphereCollisionResponse(Ball& ball1, Ball& ball2)
{
	float e = 1.0f;
	Vec3 lineOfAction = ball1.pos - ball2.pos;
	Vec3 normalizedLineOfAction = VMath::normalize(lineOfAction);
	float vp1 = VMath::dot(normalizedLineOfAction, ball1.vel);
	float vp2 = VMath::dot(normalizedLineOfAction, ball2.vel);

	float vp1new = (((ball1.mass - e * ball2.mass) * vp1) + ((1.0f + e) * ball2.mass * vp2)) / (ball1.mass + ball2.mass);
	float vp2new = (((ball2.mass - e * ball1.mass) * vp2) + ((1.0f + e) * ball1.mass * vp1)) / (ball1.mass + ball2.mass);

	ball1.vel += (vp1new - vp1) * normalizedLineOfAction;
	ball2.vel = ball2.vel + (vp2new - vp2) * normalizedLineOfAction;


}
