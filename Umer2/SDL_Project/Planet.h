#include "GameObject.h"
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"
#pragma once
class Planet : public GameObject
{
private:
	Body* Planet;

public:
	bool OnCreate() override;
	void OnDestroy() override;
	void Update(const float deltaTime) override;
	void Render() const override;
	void HandleEvents(const SDL_Event& event) override;

};

