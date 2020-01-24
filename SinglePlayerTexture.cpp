#include "SinglePlayerTexture.h"


SinglePlayerTexture::SinglePlayerTexture() :GameObject(0, 0) {}

SinglePlayerTexture::SinglePlayerTexture(int x, int y, const char* pathTexture) : GameObject(x, y)
{
	loadTexture(pathTexture);
	objectType = SINGLE_TEX;
}

SinglePlayerTexture::SinglePlayerTexture(const SinglePlayerTexture& rhs) { *this = rhs; }

SinglePlayerTexture& SinglePlayerTexture::operator=(const SinglePlayerTexture& rhs)
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

void SinglePlayerTexture::render(InputHandler& inputHandler)
{
	draw(*texObject.get(), x, y, width, height, RENDERER, SDL_FLIP_NONE);
}

SinglePlayerTexture::~SinglePlayerTexture() {}