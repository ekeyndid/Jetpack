#pragma once
#include "Body.h"
#include "GameObject.h"
#include <SDL.h>

class Ball : public Body, public GameObject
{
	friend class Collider;
private:
	SDL_Surface* ballImage;

protected:
	float r = 1.0f;
	

public:

	Ball();
	~Ball();
	void Update(const float time);





};

