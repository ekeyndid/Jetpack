#include "Planet.h"

bool Planet::OnCreate()
{
	Planet =  new Body(Vec3(10.0f, 20.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(2.5f, 0.0f, 0.0f), 1.0f);
	return false;
}

void Planet::OnDestroy()
{
}

void Planet::Update(const float deltaTime)
{
}

void Planet::Render() const
{
}

void Planet::HandleEvents(const SDL_Event& event)
{
}
