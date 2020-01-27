#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene0.h"
#include "Scene1.h"
#include "Scene2.h"
#include <iostream>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}


/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 400;
	const int SCREEN_HEIGHT = 400;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (ptr == nullptr) {
		OnDestroy();
		return false;
	}
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	currentScene = new Scene1(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

/// Here's the whole game
void GameManager::Run() {
	timer->Start();
	while (isRunning) {
		timer->UpdateFrameTicks();
		HandleEvents();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();

		/// Keeep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(60)); ///60 frames per sec
	}
}

GameManager::~GameManager() {}

void GameManager::OnDestroy(){
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}


void GameManager::HandleEvents() {
	SDL_Event a;
	
	while (SDL_PollEvent(&a)) {
		//std::cout << a.type << std::endl;
		switch (a.type) {
		case SDL_EventType::SDL_QUIT:
			SDL_Log("program finna closed at %i ticks", a.quit.timestamp);
			isRunning = false;
			return;
		case SDL_EventType::SDL_KEYDOWN:
			
			switch (a.key.keysym.sym) {
			case SDLK_LEFT:
				//std::cout << "Left press" << std::endl;
				currentScene->Direction = -1;
				break;
			case SDLK_RIGHT:
				//std::cout << "Right press" << std::endl;
				currentScene->Direction = 1;
				break;
			case SDLK_SPACE:
				currentScene->go = true;
			default:
				//std::cout << "No Press" << std::endl;
				currentScene->Direction = 0;
				break;
			}
			break;
		case SDL_EventType::SDL_KEYUP:

			switch (a.key.keysym.sym) {
			case SDLK_LEFT:
				//std::cout << "Left press up" << std::endl;
				currentScene->Direction = 0;
				break;
			case SDLK_RIGHT:
				//std::cout << "Right press up" << std::endl;
				currentScene->Direction = 0;
				break;
			default:
				//std::cout << "No Press up" << std::endl;
				currentScene->Direction = 0;
				break;
			}
			break;
			
		
		default:
			break;

		}
	}
	
}