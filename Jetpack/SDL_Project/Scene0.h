#ifndef SCENE0_H
#define SCENE0_H
#include "Body.h"
#include "Ball.h"
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>

using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	const SDL_Rect* ye;
	Body* jetski;
	Body* jetski2;
	SDL_Surface* jetskiImage;
	SDL_Surface* jetskiImage2;
	SDL_Surface* waterImage;
	Matrix4 projection;
	float elapsedTime;
	Vec3 Force;
	Vec3 Force2;
	float totalTime;

	
	

	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
	
	
};

#endif

