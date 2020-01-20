#include "Star.h"
#include <SDL_image.h>

bool Star::OnCreate()
{
	Star_1 = new Body(Vec3(5.0f, 10.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(2.5f, 0.0f, 0.0f), 100.0f);
	Star_2 = new Body(Vec3(15.0f, 25.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(2.5f, 0.0f, 0.0f), 150.0f);
	Star_1Image = IMG_Load("Star1Image.png");
	Star_2Image = IMG_Load("Star2Image.png");
	return false;

}

void Star::OnDestroy()
{
	Star_1 = nullptr;
	Star_2 = nullptr;
}

void Star::Update(const float deltaTime)
{


}

void Star::Render() const
{
}

void Star::HandleEvents(const SDL_Event& event)
{
}
