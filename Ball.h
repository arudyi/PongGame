#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Score.h"
#include "InputHandler.h"

class Ball : public GameObject
{
public:
	Ball();
	Ball(int x, int y, const char* pathTexture);
	Ball(const Ball& rhs);
	virtual ~Ball();
	Ball& operator=(const Ball& rhs);

	void update(InputHandler& inputHandler) override;
	void render(InputHandler& inputHandler) override;

private:
	void restart();
	Score left{ WINWIDTH / 6, WINHEIGHT / 8 };
	Score right{ WINWIDTH - WINWIDTH / 6, WINHEIGHT / 8};

};

