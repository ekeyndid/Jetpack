#include "GameObject.h"
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"
#pragma once
class Star : public GameObject
{
private:	
	Body* Star_1;
	Body* Star_2;
	SDL_Surface* Star_1Image;
	SDL_Surface* Star_2Image;

public:
	bool OnCreate() override;
	 void OnDestroy() override;
	 void Update(const float deltaTime) override;
	 void Render() const override;
	 void HandleEvents(const SDL_Event& event) override;

};

