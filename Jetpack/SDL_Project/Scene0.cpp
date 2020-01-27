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

	
	
	jetskiImage = IMG_Load("jetski.png");
	jetskiImage2 = IMG_Load("jetski2.png");
	waterImage = IMG_Load("water.jpg");
	Force = Vec3(500.0f, 0.0f, 0.0f);
	Force2 = Vec3(0.0f, 0.0f, 0.0f);
	totalTime = 0.0f;
	go = false;
	return true;
}

void Scene0::OnDestroy() {
	delete jetski;
	jetski = nullptr;
	delete jetski2;
	jetski2 = nullptr;
}

void Scene0::Update(const float time) {
	if (go) {

	
	jetski->Update(time);
	jetski->ApplyForce(Force);
	
	jetski2->Update(time);
	Force2 = Vec3(500.0f * Direction, 0, 0);
	jetski2->ApplyForce(Force2);
	
	


	if (totalTime >= 5.5f && totalTime < 10) {
		Force = Vec3(0.0f, 0.0f, 0.0f);
	}
	else if (totalTime >= 10 && totalTime < 15) {
		Force = Vec3(-625.0f, 0.0f, 0.0f);
	}
	else if (totalTime > 14) {
		Force = Vec3(0.0f, 0.0f, 0.0f);
		//jetski->StopVel();
	}
	else if (totalTime < 5.5f && !totalTime > 5.5f) {
		Force = Vec3(500.0f, 0.0f, 0.0f);
	}
	if (totalTime < 16) {
		jetski->Print();
		
	}
	jetski2->Print();
	system("CLS");
	
	
	totalTime += time;
	}
}

void Scene0::HandleEvents(const SDL_Event& event) {
	
}


void Scene0::Render() {
	Vec3 pos = jetski->GetPos();
	Vec3 pos2 = jetski2->GetPos();
	Vec3 screenPos = projection * pos;
	Vec3 screenPos2 = projection * pos2;
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = 220;
	SDL_Rect dstrect2;
	dstrect2.x = static_cast<int>(screenPos2.x);
	dstrect2.y = 330;
	SDL_Rect Water;
	Water.h = 50;
	Water.w = 1000;
	Water.x = 0;
	Water.y = 280;


	
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_BlitSurface(waterImage, nullptr, screenSurface, &Water);
	SDL_BlitSurface(jetskiImage, nullptr, screenSurface, &dstrect);
	SDL_BlitSurface(jetskiImage2, nullptr, screenSurface, &dstrect2);
	
	
	
	
		
		SDL_UpdateWindowSurface(window);
}


