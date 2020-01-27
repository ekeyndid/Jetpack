#include "Scene1.h"
#include <SDL_image.h> 
#include <SDL.h>
#include <SDL_ttf.h>
#include "Physics.h"
Scene1::Scene1(SDL_Window* sdlWindow_) {
	window = sdlWindow_;

}

Scene1::~Scene1() {
}

bool Scene1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(-20.0f, 20.0f, -20.0f, 20.0f, 0.0f, 10.0f);
	projection = ndc * ortho;
	
	
	
	
	Balls[0] =  Ball(Vec3(-18.0f, 0.0f, 0.0f),//pos 
		         Vec3(0.0f, 0.0f, 0.0f),//vel 
		         Vec3(0.0f, 0.0f, 0.0f),//accel
		         2, 10.0f,"Ball1");//radius mass and name
	Balls[1] = Ball(Vec3(18.0f, -1.0f, 0.0f),//pos
				  Vec3(0.0f, 0.0f, 0.0f),//vel
				  Vec3(0.0f, 0.0f, 0.0f),//accel
				  2,10.0f, "Ball2");//radius mass and name
	Balls[2] = Ball(Vec3(0.0f, -18.0f, 0.0f),//pos
		Vec3(0.0f, 0.0f, 0.0f),//vel
		Vec3(0.0f, 0.0f, 0.0f),//accel
		2, 10.0f, "Ball3");//radius mass and name
	Balls[3] = Ball(Vec3(0.0f, 18.0f, 0.0f),//pos
		Vec3(0.0f, 0.0f, 0.0f),//vel
		Vec3(0.0f, 0.0f, 0.0f),//accel
		2, 10.0f, "Ball4");//radius mass and name
	Balls[4] = Ball(Vec3(18.0f, -18.0f, 0.0f),//pos
		Vec3(0.0f, 0.0f, 0.0f),//vel
		Vec3(0.0f, 0.0f, 0.0f),//accel
		2, 10.0f, "Ball5");//radius mass and name
	Balls[5] = Ball(Vec3(0.0f, 7.0f, 0.0f),//pos
		Vec3(0.0f, 0.0f, 0.0f),//vel
		Vec3(0.0f, 0.0f, 0.0f),//accel
		2, 10.0f, "Ball6");//radius mass and name
	


	Roof = Plane(0.0f, 1.0f, 0.0f, 10.0f);
	
	
	
	for (int i = 0; i < 6; i++) {
		Balls[i].Print();
		Balls[i].SetVel(Vec3(20.0f, 20.0f, 0.0f));
	}
	
	
	return true;
}

void Scene1::OnDestroy() {
	
}

void Scene1::Update(const float time) {
	int f = 0;
	for (int i = 0; i < 6; f++) {
		if (f == i) {
			f = i++;
		}
		
		if (f == 6) {
			i++;
			f = i++;
		}
		if (Physics::isCollideSphereSphere(Balls[i], Balls[f])) {
			Physics::CollideSphereSphere(Balls[i], Balls[f]);
		}
	}
	for (int i = 0; i < 6; i++) {
		Balls[i].Update(time);
	}
	
	
		
	
	
	


	
}

void Scene1::Render() {
	Vec3 ScreenPosz[6];
	for (int f = 0; f < 6; f++) {
		ScreenPosz[f] = projection * Balls[f].GetPos();
	}
	
	
	/*Vec3 pos2 = jetski2->GetPos();*/
	
	
	/*Vec3 screenPos2 = projection * pos2;*/
	SDL_Rect dstrects[6];
	for (int x = 0; x < 6; x++) {
		dstrects[x].x = static_cast<int>(ScreenPosz[x].x);
		dstrects[x].y = static_cast<int>(ScreenPosz[x].y);
	}
	
	
	
	
	/*SDL_Rect dstrect2;
	dstrect2.x = static_cast<int>(screenPos2.x);
	dstrect2.y = 330;
	*/
	



	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	//SDL_BlitSurface(waterImage, nullptr, screenSurface, &Water);
	for (int e = 0; e < 6; e++) {
		SDL_BlitSurface(Balls[e].ballimage, nullptr, screenSurface, &dstrects[e]);
	}
	
	
	//SDL_BlitSurface(jetskiImage2, nullptr, screenSurface, &dstrect2);





	SDL_UpdateWindowSurface(window);
}

void Scene1::HandleEvents(const SDL_Event& event) {

}

