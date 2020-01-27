#include "Scene2.h"
#include <SDL_image.h> 
#include <SDL.h>
#include <SDL_ttf.h>
#include "Physics.h"
Scene2::Scene2(SDL_Window* sdlWindow_) {
	window = sdlWindow_;

}

Scene2::~Scene2() {
}

bool Scene2::OnCreate() {
	Sun1Pic = IMG_Load("sun.png");
	Sun2Pic = IMG_Load("sun.png");
	PlanetPic = IMG_Load("earth.png");
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 50.0f, -50.0f, 50.0f, 0.0f, 10.0f);
	projection = ndc * ortho;
	Sun1 = Body();
	Sun2 = Body();
	Planet = Body();
	Sun1.BodyOnCreate(Vec3(5.0f, 10.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 10.0f, 0.0f), 100.0f, "Sun 1", 2);
	Sun2.BodyOnCreate(Vec3(15.0f, 25.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 150.0f, "Sun 2", 2);
	Planet.BodyOnCreate(Vec3(10.0f, 20.0f, 0.0f), Vec3(-5.0f, 1.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 1.0f, "Planet", 1);



	



	

	return true;
}

void Scene2::OnDestroy() {

}

void Scene2::Update(const float time) {
	Vec3 ForceG1;
	Vec3 DirectionVec;
	float ForceG1MAG;
	Vec3 ForceG2;
	float ForceG2MAG;
	Vec3 FNet;
	ForceG1MAG = (GravConst * Planet.GetMass() * Sun1.GetMass()) / (VMath::distance(Sun1.GetPos(), Planet.GetPos()) * VMath::distance(Sun1.GetPos(), Planet.GetPos()));
	DirectionVec = Sun1.GetPos() - Planet.GetPos();
	DirectionVec = VMath::normalize(DirectionVec);
	ForceG1 = ForceG1MAG * DirectionVec;
	//DirectionVec = Vec3();
	ForceG2MAG = (GravConst * Planet.GetMass() * Sun2.GetMass()) / (VMath::distance(Sun2.GetPos(), Planet.GetPos()) * VMath::distance(Sun2.GetPos(), Planet.GetPos()));
	DirectionVec = Sun2.GetPos() - Planet.GetPos();
	DirectionVec = VMath::normalize(DirectionVec);
	ForceG2 = ForceG2MAG * DirectionVec;
	FNet = ForceG1 + ForceG2;
	std::cout << "Force G1 and G2---------------------------------" << std::endl;
	ForceG1.print();
	ForceG2.print();
	std::cout << "Force NET---------------------------------------" << std::endl;
	FNet.print();
	std::cout << "---------------------------------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	Planet.ApplyForce(FNet);
	Planet.Update(time);







}

void Scene2::Render() {

	Vec3 pos = Sun1.GetPos();
	Vec3 pos2 = Sun2.GetPos();
	Vec3 pos3 = Planet.GetPos();
	/*Vec3 pos2 = jetski2->GetPos();*/
	Vec3 screenPos = projection * pos;
	Vec3 screenPos2 = projection * pos2;
	Vec3 screenPos3 = projection * pos3;
	/*Vec3 screenPos2 = projection * pos2;*/
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);
	SDL_Rect dstrect2;
	dstrect2.x = static_cast<int>(screenPos2.x);
	dstrect2.y = static_cast<int>(screenPos2.y);
	SDL_Rect dstrect3;
	dstrect3.x = static_cast<int>(screenPos3.x);
	dstrect3.y = static_cast<int>(screenPos3.y);
	/*SDL_Rect dstrect2;
	dstrect2.x = static_cast<int>(screenPos2.x);
	dstrect2.y = 330;
	*/




	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	//SDL_BlitSurface(waterImage, nullptr, screenSurface, &Water);
	SDL_BlitSurface(Sun1Pic, nullptr, screenSurface, &dstrect);
	SDL_BlitSurface(Sun2Pic, nullptr, screenSurface, &dstrect2);
	SDL_BlitSurface(PlanetPic, nullptr, screenSurface, &dstrect3);
	//SDL_BlitSurface(jetskiImage2, nullptr, screenSurface, &dstrect2);





	SDL_UpdateWindowSurface(window);
}

void Scene2::HandleEvents(const SDL_Event& event) {

}

