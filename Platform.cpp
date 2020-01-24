#include "Platform.h"

Platform::Platform() :GameObject{0,0}
{

}

Platform::Platform(int x, int y, const char *pathTexture, bool ItsIsLeft) : GameObject{ x, y }
{
	loadTexture(pathTexture);
	isLeft = ItsIsLeft;
	if (isLeft == true)
		objectType = LEFT;
	else
		objectType = RIGHT;
}

Platform::~Platform() {

}

Platform::Platform(const Platform& rhs) 
{
	*this = rhs;
}

Platform Platform::operator=(const Platform& rhs)
{
	if (this != &rhs) 
	{
		x = rhs.y;
		y = rhs.y;
		width = rhs.width;
		height = rhs.height;
		width = rhs.width;
		height = rhs.height;
		isLeft = rhs.isLeft;
	}
	return *this;
}

void Platform::update(InputHandler& inputHandler)
{
	if (inputHandler.getKeyState(SDL_SCANCODE_W) == true && isLeft == true)
	{
		y -= 5;
		if ((y - height / 2) <= 0)
			y = height / 2;
	}
	else if (inputHandler.getKeyState(SDL_SCANCODE_S) == true && isLeft == true)
	{
		y += 5;
		if ((y + height / 2) >= WINHEIGHT)
			y = WINHEIGHT - height / 2;
	}
	else if (inputHandler.getKeyState(SDL_SCANCODE_UP) == true && isLeft == false && IsSingleGame == false)
	{
		y -= 5;
		if ((y - height / 2) <= 0)
			y = height / 2;
	}
	else if (inputHandler.getKeyState(SDL_SCANCODE_DOWN) == true && isLeft == false && IsSingleGame == false)
	{
		y += 5;
		if ((y + height / 2) >= WINHEIGHT)
			y = WINHEIGHT - height / 2;
	}
}

void Platform::render(InputHandler& inputHandler)
{
	draw(*texObject.get(), x - width / 2, y - height / 2, width, height, RENDERER, SDL_FLIP_NONE);
}