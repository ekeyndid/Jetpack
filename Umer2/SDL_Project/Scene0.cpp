#include "Scene0.h"
#include <SDL.h>
#include <SDL_image.h>
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 20.0, 0.0, 10.0, 0.0, 1.0);
	projection = ndc * ortho;

	//					(pos)						(vel)						(accel)
	JetSki = new jetSki();
	JetSkiImage = IMG_Load("jetSki.jpg");
	if (JetSki == nullptr || JetSkiImage == nullptr) {
		return false;
	}
	

	return true;
}

void Scene0::OnDestroy() {
	delete JetSki;
	JetSki = nullptr;
}

void Scene0::Update(const float time) {
	totalTime += time;
	Vec3 force;

	if (totalTime >= 0.0f && totalTime < 5.5f) {

		force.x = 500.0f;
	}
	if (totalTime >= 5.5f && totalTime < 10.0f) {

		force.x = 0.0f;
	}

	if (totalTime > 9.0f && totalTime < 15.1f) {

		force.x = -500.0f;
	}

	if (totalTime > 6.6f & JetSki->vel.x >= -0.2f & JetSki->vel.x <= 0.2f) {

		JetSki->vel.x = 0.0f;
		force.x = 0.0f;
	}
	JetSki->ApplyForce(force);
	JetSki->Update(time);
}

void Scene0::Render() {
	Vec3 pos = JetSki->GetPos();
	Vec3 screenPos = projection * pos;
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);
	
	
	// DO NOT TOUCH
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	// DO NOT TOUCH
	
	
	SDL_BlitSurface(JetSkiImage, nullptr, screenSurface, &dstrect);
	
	SDL_UpdateWindowSurface(window);
}

