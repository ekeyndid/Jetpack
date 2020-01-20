#ifndef SCENE1_H
#define SCENE1_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"
class Scene1 : public Scene
{
private:
	SDL_Window* window;
	Body* Planet;
	Body* Star_1;
	Body* Star_2;
	SDL_Surface* Star_1Image;
	SDL_Surface* Star_2Image;
	SDL_Surface* PlanetImage;

public:
	Scene1(SDL_Window* sdlWindow);
	~Scene1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();

};
#endif