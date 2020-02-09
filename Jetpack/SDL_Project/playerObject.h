#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include "Body.h"
#include "GameObject.h"
#include <SDL.h>
#include "MMath.h"

class playerObject : public GameObject, public Body
{
public:
	SDL_Surface* Image;
	float Direction = 0;
	float SphereRadiusBox = 69;
	bool grounded = false;
	//void Update(const float deltaTime);
	bool OnCreate();
	bool OnCreate(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, std::string name_, float Rad_);
	void OnDestory();
	void Update(const float deltaTime);
	void Render() const;
	void HandleEvents(const SDL_Event& SDL_Event);
	void ApplyHor(float x_);

};





#endif // PLAYEROBJECT_H