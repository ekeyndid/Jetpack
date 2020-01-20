#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "jetSki.h"
#include "Ball.h"
#include "Collider.h"
#include "Body.h"
#pragma once

using namespace MATH;

class Scene2 : public Scene
{
private:
	SDL_Window* window;
	Ball* ball;
	Ball* ball2;
	Matrix4 projection;

public:
	Scene2(SDL_Window* sdlWindow);
	~Scene2();
	bool OnCreate() override;
	void OnDestroy() override;
	void Update(const float time) override;
	void Render() override;

};

