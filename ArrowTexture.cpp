#include "ArrowTexture.h"

ArrowTexture::ArrowTexture() :GameObject(0, 0) {}

ArrowTexture::ArrowTexture(int x, int y, const char* pathTexture) : GameObject(x, y)
{
	loadTexture(pathTexture);
	objectType = ARROW_TEX;
}

ArrowTexture::ArrowTexture(const ArrowTexture& rhs) { *this = rhs; }

ArrowTexture& ArrowTexture::operator=(const ArrowTexture& rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		width = rhs.width;
		height = rhs.height;
	}
	return *this;
}

void ArrowTexture::render(InputHandler& inputHandler)
{
	draw(*texObject.get(), x, y, width, height, RENDERER, SDL_FLIP_NONE);
}

ArrowTexture::~ArrowTexture() {}