#include "TwoPlayerTexture.h"

TwoPlayerTexture::TwoPlayerTexture() :GameObject(0, 0) {}

TwoPlayerTexture::TwoPlayerTexture(int x, int y, const char* pathTexture) : GameObject(x, y)
{
	loadTexture(pathTexture);
	objectType = TWO_TEX;
}

TwoPlayerTexture::TwoPlayerTexture(const TwoPlayerTexture& rhs) { *this = rhs; }

TwoPlayerTexture& TwoPlayerTexture::operator=(const TwoPlayerTexture& rhs)
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

void TwoPlayerTexture::render(InputHandler& inputHandler)
{
	draw(*texObject.get(), x, y, width, height, RENDERER, SDL_FLIP_NONE);
}

TwoPlayerTexture::~TwoPlayerTexture() {}