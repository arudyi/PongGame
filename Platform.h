#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Ball.h"
#include "InputHandler.h"

class Platform : public GameObject
{
	public:
		Platform();
		Platform(int x, int y, const char * pathTexture, bool ItsIsLeft);
		virtual ~Platform();
		Platform(const Platform & rhs);
		Platform operator=(const Platform & rhs);
		
		void update(InputHandler& inputHandler) override;
		void render(InputHandler& inputHandler) override;
		
	private:
};

