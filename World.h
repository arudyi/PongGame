#pragma once
#include "GameObject.h"
#include "InputHandler.h"

class World :public GameObject
{
public:
	World();
	World(int x, int y, const char *pathTexture);
	World(const World& rhs);
	World& operator=(const World& rhs);
	~World();
	void render(InputHandler& inputHandler) override;
};

