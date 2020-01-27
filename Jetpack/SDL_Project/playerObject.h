#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include "Body.h"
#include "GameObject.h"

class playerObject : public GameObject, public Body
{
public:
	SDL_Surface* ballimage;
	
	
	
	void Update(const float deltaTime);
	bool OnCreate();
	void OnDestory();
	//void Update(const float deltaTime);
	void Render() const;
	void HandleEvents(const SDL_Event& SDL_Event);

};





#endif // PLAYEROBJECT_H