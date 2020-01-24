#pragma once
#include "Game.h"
#include "InputHandler.h"


class GameObject
{
public:
	GameObject();
	GameObject(int x, int y);
	virtual ~GameObject();
	GameObject(const GameObject& rhs);
	GameObject &operator=(const GameObject& rhs);
	
	virtual void update(InputHandler &inputHandler);
	virtual void render(InputHandler &inputHandler);

	int getX()const;
	int getY()const;
	void setX(int x);
	void setY(int y);

	int getWidth()const;
	int getHeight()const;
	void setWidth(int x);
	void setHeight(int y);
	void loadTexture(const char* str);
	int getObjectType()const;
	void setObjectType(int tmp);
	void setTypeGame(bool status);
	bool getTypeGame()const;

	void setdirX(int itsX);
	void setdirY(int itsY);
	int getRadius()const;
	int getdirX()const;
	int getdirY()const;
	int getSpeed()const;
	void setLeft(bool status);
	bool IsLeft()const;
protected:
	bool isLeft = false;
	bool IsSingleGame = true;
	int dirX = 0;
	int dirY = 0;
	int speed = 0;
	int radius = 0;
	int angle = 0;
	int objectType = 0;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	std::shared_ptr<SDL_Texture*> texObject;
	//SDL_Texture* texObject = nullptr;
};

