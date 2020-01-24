#pragma once
#include "GameObject.h"
#include "Game.h"
#include "InputHandler.h"

class TwoPlayerTexture :public GameObject
{
public:
	TwoPlayerTexture();
	TwoPlayerTexture(int x, int y, const char * pathTexture);
	TwoPlayerTexture(const TwoPlayerTexture& rhs);
	TwoPlayerTexture& operator=(const TwoPlayerTexture& rhs);
	~TwoPlayerTexture();
	void render(InputHandler& inputHandler)override;
};

