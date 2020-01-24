#include "Engine.h"

SDL_Renderer* RENDERER;
SDL_Window* WINDOW;

Engine::Engine(){}

Engine::Engine(const Engine& rhs) { *this = rhs; }

Engine::~Engine()
{
	delete gameObjects.find(BALL)->second;
	delete gameObjects.find(LEFT)->second;
	delete gameObjects.find(RIGHT)->second;
	delete gameObjects.find(WORLD_TEX)->second;
	delete gameObjects.find(SINGLE_TEX)->second;
	delete gameObjects.find(TWO_TEX)->second;
	delete gameObjects.find(ARROW_TEX)->second;

	gameObjects.clear();

	SDL_DestroyWindow(WINDOW);
	SDL_DestroyRenderer(RENDERER);
	TTF_Quit();
	SDL_Quit();
}

Engine& Engine::operator=(const Engine& rhs)
{
	if (this != &rhs)
	{
		IsSingleGame = rhs.IsSingleGame;
		IsChooseMenu = rhs.IsChooseMenu;
		isRunGame = rhs.isRunGame;
		inputHandler = rhs.inputHandler;
		gameObjects = rhs.gameObjects;
	}
	return *this;
}

void Engine::setStatusGame(bool status)
{
	isRunGame = status;
}

void Engine::initGameObjects()
{
	GameObject *ball = new Ball{ WINWIDTH / 2, WINHEIGHT / 2, "ball.png" };
	
	GameObject *left = new Platform{ 15, WINHEIGHT / 2, "Platform.png", true };
	
	GameObject *right = new Platform{ WINWIDTH - 20, WINHEIGHT / 2, "Platform.png", false };

	GameObject *world = new World{ 0, 0, "background.png" };

	GameObject *singlePlayerTexture = new SinglePlayerTexture{WINWIDTH / 4, WINHEIGHT / 4, "PlayerOne.png" };

	GameObject *twoPlayerTexture = new TwoPlayerTexture{WINWIDTH / 4, WINHEIGHT / 2, "PlayerTwo.png"};

	GameObject *arrowTexture = new ArrowTexture{ WINWIDTH / 6, WINHEIGHT / 4, "arrow.png" };

	gameObjects.insert(std::pair<int, GameObject*>(WORLD_TEX, world));
	gameObjects.insert(std::pair<int, GameObject*>(LEFT, left));
	gameObjects.insert(std::pair<int, GameObject*>(RIGHT, right));
	gameObjects.insert(std::pair<int, GameObject*>(BALL, ball));
	gameObjects.insert(std::pair<int, GameObject*>(SINGLE_TEX, singlePlayerTexture));
	gameObjects.insert(std::pair<int, GameObject*>(TWO_TEX, twoPlayerTexture));
	gameObjects.insert(std::pair<int, GameObject*>(ARROW_TEX, arrowTexture));

}

void Engine::start()
{
	Uint32 frameStart, frameTime;
	

	while (isRunGame == true) {

		frameStart = SDL_GetTicks();

		isRunGame = inputHandler.proccesInput();
		update(inputHandler);
		render(inputHandler);


		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameTime < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
}

void Engine::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		throw std::runtime_error("SDL initialization failed");
	}
	else
	{
		TTF_Init();

		WINDOW = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINWIDTH, WINHEIGHT, SDL_WINDOW_SHOWN);

		if (WINDOW == nullptr) {

			throw std::runtime_error("Window could not be created!");

		}

		RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_TARGETTEXTURE);
		if (RENDERER == nullptr)
		{
			throw std::runtime_error("Window could not be created!");
		}
		initGameObjects();
	}
}

void Engine::render(InputHandler& inputHandler)
{
	SDL_RenderClear(RENDERER);
	
	gameObjects.find(WORLD_TEX)->second->render(inputHandler);
	gameObjects.find(BALL)->second->render(inputHandler);
	gameObjects.find(LEFT)->second->render(inputHandler);
	gameObjects.find(RIGHT)->second->render(inputHandler);

	if (IsChooseMenu == true)
	{
		gameObjects.find(SINGLE_TEX)->second->render(inputHandler);
		gameObjects.find(TWO_TEX)->second->render(inputHandler);
		gameObjects.find(ARROW_TEX)->second->render(inputHandler);
	}
	
	SDL_RenderPresent(RENDERER);
}

void Engine::update(InputHandler& inputHandler)
{
	if (IsChooseMenu == true)
	{
		checkInputInChooseMenu(inputHandler);
	}
	else
	{
		gameObjects.find(BALL)->second->update(inputHandler);
		gameObjects.find(LEFT)->second->update(inputHandler);
		
		if (IsSingleGame == true && gameObjects.find(RIGHT)->second->IsLeft() == false)
		{
			calculateBot(*gameObjects.find(RIGHT)->second, *gameObjects.find(BALL)->second);
		}
		else
		{
			gameObjects.find(RIGHT)->second->update(inputHandler);
		}

		checkCollision(*gameObjects.find(BALL)->second, *gameObjects.find(LEFT)->second, *gameObjects.find(RIGHT)->second);
	}
}

void Engine::checkCollision(GameObject &ball, GameObject&left, GameObject&right)
{
	if ((ball.getX() - ball.getRadius()) <= (left.getX() + left.getWidth() / 2) &&
		(ball.getY() - ball.getRadius()) <= (left.getY() + left.getHeight() / 2) &&

		(ball.getY() + ball.getRadius()) >= (left.getY() - left.getHeight() / 2)

		)
	{
		if (ball.getdirX() < 0)
		{
			int angle = ball.getY() - left.getY();
			if (angle == 0)
				angle = 10;
			ball.setdirX(ball.getSpeed() * cos(angle * M_PI / 180));
			ball.setdirY(ball.getSpeed() * sin(angle * M_PI / 180));
		}
	}


	if ((ball.getX() + ball.getRadius()) >= (right.getX() - right.getWidth() / 2) &&
		(ball.getY() - ball.getRadius()) <= (right.getY() + right.getHeight() / 2) &&

		(ball.getY() + ball.getRadius()) >= (right.getY() - right.getHeight() / 2)
		)
	{
		if (ball.getdirX() > 0)
		{
			int angle = ball.getY() - right.getY();
			if (angle == 0)
				angle = 10; 
			ball.setdirX(ball.getSpeed() * cos(angle * M_PI / 180));
			ball.setdirY(ball.getSpeed() * sin(angle * M_PI / 180));
			ball.setdirX(ball.getdirX() * -1);
		}
	}
}

void Engine::checkInputInChooseMenu(InputHandler& inputHandler)
{
	if (inputHandler.getKeyState(SDL_SCANCODE_UP) == true)
	{
		gameObjects.find(ARROW_TEX)->second->setY(WINHEIGHT / 4);
	}
	else if (inputHandler.getKeyState(SDL_SCANCODE_DOWN) == true)
	{
		gameObjects.find(ARROW_TEX)->second->setY(WINHEIGHT / 2);
	}
	else if (inputHandler.getKeyState(SDL_SCANCODE_RETURN) == true)
	{
		if (gameObjects.find(ARROW_TEX)->second->getY() == WINHEIGHT / 4)
		{
			gameObjects.find(LEFT)->second->setTypeGame(true);
			gameObjects.find(RIGHT)->second->setTypeGame(true); 
			IsSingleGame = true;
		}
		else
		{
			gameObjects.find(LEFT)->second->setTypeGame(false);
			gameObjects.find(RIGHT)->second->setTypeGame(false);
			IsSingleGame = false;
		}
		IsChooseMenu = false;
	}
}

void Engine::calculateBot(GameObject& right, GameObject& ball)
{
	static bool IsFindFuturePos = false;
	static int yFuture = 0;

	if (IsFindFuturePos == false && ball.getdirX() > 0)
	{
		yFuture = calculateFuturePosition(ball);
		IsFindFuturePos = true;
	}
	else if (ball.getdirX() < 0)
	{
		IsFindFuturePos = false;
	}

	if (IsFindFuturePos == true)
	{
		if (right.getY() < yFuture)
		{
			if ((yFuture - right.getY()) < 5)
				right.setY(right.getY() + 1);
			else
				right.setY(right.getY() + 5);

			if ((right.getY() + right.getHeight() / 2) >= WINHEIGHT)
				right.setY(WINHEIGHT - right.getHeight() / 2);
		}
		else if (right.getY() == yFuture)
		{

		}
		else
		{
			if ((right.getY() - yFuture) < 5)
				right.setY(right.getY() - 1);
			else
				right.setY(right.getY() - 5);

			if ((right.getY() - right.getHeight() / 2) <= 0)
				right.setY(right.getHeight() / 2);
		}
	}
}

int Engine::calculateFuturePosition(GameObject ball)
{
	while (ball.getX() <= WINWIDTH)
	{
		ball.setX(ball.getX() + ball.getdirX());
		ball.setY(ball.getY() + ball.getdirY());

		if ((ball.getY()) <= 0 || (ball.getY()) >= WINHEIGHT)
		{
			ball.setdirY(ball.getdirY() * -1);
		}
	}
	return ball.getY();
}