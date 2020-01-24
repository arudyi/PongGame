#include "Score.h"

Score::Score() :GameObject{0,0}
{
	Font = TTF_OpenFont("C:\\Windows\\Fonts\\Arial.ttf", 25);
	if (Font == nullptr)
	{
		throw std::runtime_error(TTF_GetError());
	}
}

Score::Score(int x, int y) :GameObject{ x,y }
{
	Font = TTF_OpenFont("C:\\Windows\\Fonts\\Arial.ttf", 25);
	if (Font == nullptr)
	{
		throw std::runtime_error(TTF_GetError());
	}
}

Score::Score(const Score& rhs) { *this = rhs; }

Score::~Score() {}

Score & Score::operator=(const Score& rhs)
{
	if (this != &rhs)
	{
		counter = rhs.counter;
	}
	return *this;
}
int Score::getCounter()const { return counter; }

void Score::setCounter(int itsCounter) { counter = itsCounter; }

void Score::update(InputHandler& inputHandler)
{

}

void Score::renderScore(const SDL_Color& Color)
{
	SDL_Surface* surfaceScore = TTF_RenderText_Solid(Font, std::to_string(counter).c_str(), Color);

	if (surfaceScore == nullptr)
	{
		throw std::runtime_error(TTF_GetError());
	}

	SDL_Texture* texScore = SDL_CreateTextureFromSurface(RENDERER, surfaceScore);

	if (texScore == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
	SDL_QueryTexture(texScore, NULL, NULL, &width, &height);

	draw(texScore, x, y, width, height, RENDERER, SDL_FLIP_NONE);

	SDL_FreeSurface(surfaceScore);
	SDL_DestroyTexture(texScore);
}

void Score::render(InputHandler& inputHandler)
{
	renderScore({255,255,255});
}