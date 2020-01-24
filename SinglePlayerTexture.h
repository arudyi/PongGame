#pragma once
#include "GameObject.h"
#include "Game.h"
#include "InputHandler.h"

class SinglePlayerTexture : public GameObject
{
	public:
		SinglePlayerTexture();
		SinglePlayerTexture(int x, int y, const char *pathTexture);
		SinglePlayerTexture(const SinglePlayerTexture & rhs);
		SinglePlayerTexture &operator=(const SinglePlayerTexture& rhs);
		~SinglePlayerTexture();
		void render(InputHandler& inputHandler)override;
};

