#include "playerObject.h"

bool playerObject::OnCreate() {
	pos = Vec3();
	vel = Vec3();
	accel = Vec3();
	mass = 1;
	Name = "bad";
	SphereRadiusBox = 1;
	Image = nullptr;
	return true;
}
bool playerObject::OnCreate(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, std::string name_, float Rad_) {
	pos = pos_;
	vel = vel_;
	accel = accel_;
	mass = mass_;
	Name = name_;
	SphereRadiusBox = Rad_;
	Image = IMG_Load("player.jpg");
	if (Image != nullptr) {
		return true;
	}
	else {
		return false;
	}
}
void playerObject::OnDestory() {
	Image = nullptr;
	delete Image;
}
void playerObject::Update(const float deltaTime) {
	
	if (grounded) {
		vel.y = 0;
		accel.y = 0;
	}
	else if (!grounded) {
		ApplyForce(Vec3(0.0f, -5.0f, 0.0f));
	}
	// TEMP TEST
	if (pos.y < -5.0f) {
		grounded = true;
	}
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;

	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;

	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;
}
void playerObject::ApplyHor(float x_){
	vel.x = x_;
}
void playerObject::Render() const{

}
void playerObject::HandleEvents(const SDL_Event& SDL_Event) {
	switch (SDL_Event.type) {
	case SDL_EventType::SDL_KEYDOWN:

		switch (SDL_Event.key.keysym.sym) {
		case SDLK_LEFT:
			//std::cout << "Left press" << std::endl;
			Direction = -1;
			break;
		case SDLK_RIGHT:
			//std::cout << "Right press" << std::endl;
			Direction = 1;
			break;
		case SDLK_SPACE:

		default:
			//std::cout << "No Press" << std::endl;
			Direction = 0;
			break;
		}
		break;
	case SDL_EventType::SDL_KEYUP:

		switch (SDL_Event.key.keysym.sym) {
		case SDLK_LEFT:
			//std::cout << "Left press up" << std::endl;
			Direction = 0;
			break;
		case SDLK_RIGHT:
			//std::cout << "Right press up" << std::endl;
			Direction = 0;
			break;
		default:
			//std::cout << "No Press up" << std::endl;
			Direction = 0;
			break;
		}
		break;


	default:
		break;

	}
	std::cout << Direction << std::endl;
}




