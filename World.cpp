#include "World.h"

World::World() :GameObject(0, 0) {}

World::World(int x, int y, const char* pathTexture) : GameObject(x, y)
{
	loadTexture(pathTexture);
	objectType = WORLD_TEX;
}

World::World(const World& rhs) { *this = rhs; }

World& World::operator=(const World& rhs)
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

void World::render(InputHandler& inputHandler)
{
	SDL_RenderCopy(RENDERER, *texObject.get(), 0, 0);
}

World::~World() {}