#ifndef SCENE0_H
#define SCENE0_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "jetSki.h"
#include "Ball.h"
#include "Body.h"

using namespace MATH;

class Scene0 : public Scene {
private:
	SDL_Window *window;
	jetSki* JetSki;
	SDL_Surface* JetSkiImage;
	Matrix4 projection;
	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();

	float totalTime;
};

#endif

