#pragma once
#include "GameObject.h"
#include "Game.h"
#include "InputHandler.h"

class ArrowTexture :public GameObject
{
public:
	ArrowTexture();
	ArrowTexture(int x, int y, const char *pathTexture);
	ArrowTexture(const ArrowTexture& rhs);
	ArrowTexture& operator=(const ArrowTexture& rhs);
	~ArrowTexture();
	void render(InputHandler& inputHandler) override;
};

