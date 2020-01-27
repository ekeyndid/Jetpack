#include "Scene0.h"
#include <SDL_image.h> 
#include <SDL.h>
#include <SDL_ttf.h>
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(-10.0f, 200.0f, 0.0f, 10.0f, 0.0f, 10.0f);
	projection = ndc * ortho;
	

	//jetski = new Body();
	//jetski->BodyOnCreate(Vec3(0.0f, 0.0f, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f), 200.0f, "Umer and Scott");
	//
	//jetski2 = new Body();
	//jetski2->BodyOnCreate(Vec3(-10.0f, 0, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f), 200.0f, "Jetski2");

	
	
	
	return true;
}

void Scene0::OnDestroy() {
	
}

void Scene0::Update(const float time) {
	
}

void Scene0::HandleEvents(const SDL_Event& event) {
	
}


void Scene0::Render() {
	//Vec3 pos = 
	
	//Vec3 screenPos = 
	
	//SDL_Rect dstrect;
	//dstrect.x = 
	//dstrect.y = 




	
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//SDL_BlitSurface(image, nullptr, screenSurface, &dstrect);

	
	
	
	
		
		SDL_UpdateWindowSurface(window);
}


