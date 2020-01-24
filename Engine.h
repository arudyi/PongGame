#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Ball.h"
#include "Platform.h"
#include "ArrowTexture.h"
#include "SinglePlayerTexture.h"
#include "TwoPlayerTexture.h"
#include "World.h"
#include "InputHandler.h"
#include "Score.h"

class Engine
{
	public:
		Engine();
		Engine(const Engine& rhs);
		~Engine();
		Engine& operator=(const Engine& rhs);
		
		void start();
		void init();
		void render(InputHandler &inputHandler);
		void update(InputHandler &inputHandler);
		void setStatusGame(bool status);
	private:
		bool IsSingleGame = true;
		bool IsChooseMenu = true;
		bool isRunGame = true;
		InputHandler inputHandler;
		std::map <int, GameObject*> gameObjects;
		void initGameObjects();
		void checkCollision(GameObject& ball, GameObject& left, GameObject& right);
		void checkInputInChooseMenu(InputHandler& inputHandler);
		void calculateBot(GameObject& right, GameObject& ball);
		int calculateFuturePosition(GameObject ball);

};

