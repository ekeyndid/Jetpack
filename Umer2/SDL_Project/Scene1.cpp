#include "Scene1.h"
#include <SDL_image.h>


Scene1::Scene1(SDL_Window* sdlWindow_)
{
	window = sdlWindow_;

}

Scene1::~Scene1()
{
}

bool Scene1::OnCreate()
{
	Star_1 = new Body(Vec3(5.0f, 10.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(2.5f, 0.0f, 0.0f), 100.0f);
	Star_2 = new Body(Vec3(15.0f, 25.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(2.5f, 0.0f, 0.0f), 150.0f);
	
	
	Star_1Image = IMG_Load("Star1Image.png");
	Star_2Image = IMG_Load("Star2Image.png");

	Planet = new Body(Vec3(10.0f, 20.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(2.5f, 0.0f, 0.0f), 1.0f);
	PlanetImage = IMG_Load("PlanetImage.png");
	
	if (Star_1 == nullptr || Star_1Image == nullptr) {
		return false;
	}
	if (Star_2 == nullptr || Star_2Image == nullptr) {
		return false;
	}
	
	if (Planet == nullptr || PlanetImage == nullptr) {
		return false;
	}
	return true;
}

void Scene1::OnDestroy()
{
	Star_1 = Star_2 = Planet = nullptr;
}

void Scene1::Update(const float time)
{
	float fg1 = (1.0f * 100 * 1.0f) / 125.0f;
	float PS1 = (5.0f, 10.0f) - (10.0f, 20.0f);
	float PS1normal = PS1 / sqrt(PS1);


}

void Scene1::Render()
{
}
