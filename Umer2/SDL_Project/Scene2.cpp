#include "Scene2.h"
#include <SDL.h>
#include <SDL_image.h>

Scene2::Scene2(SDL_Window* sdlWindow)
{
	window = sdlWindow;
}


Scene2::~Scene2()
{
}

bool Scene2::OnCreate()
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 20.0, 0.0, 10.0, 0.0, 1.0);
	projection = ndc * ortho;
	
	ball = new Body(Vec3(0.0f, 10.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, -9.81f, 0.0f), 100.0f);

	return false;
}

void Scene2::OnDestroy()
{
}

void Scene2::Update(const float time)
{
	if(Collider::SphereSphereCollision(*ball, *ball2)) {
		Collider::SphereSphereCollisionResponse(*ball, *ball2);
	}

	ball->Update(time);
	ball2->Update(time);



}

void Scene2::Render()
{
}
