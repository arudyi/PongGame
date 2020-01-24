#pragma once
#include "Game.h"
#include "GameObject.h"

class Score : public GameObject
{
public:
	
	Score();
	Score(int x, int y);
	Score(const Score& rhs);
	virtual ~Score();
	Score& operator=(const Score& rhs);
	int getCounter()const;
	void setCounter(int itsCounter);

	void update(InputHandler& inputHandler) override;
	void render(InputHandler& inputHandler) override;
private:
	int counter = 0;
	TTF_Font* Font = nullptr;
	void renderScore(const SDL_Color& Color);
};

