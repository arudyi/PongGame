#pragma once
#include "Game.h"

class InputHandler
{
public:
	InputHandler();
	InputHandler(const InputHandler& rhs);
	InputHandler &operator=(const InputHandler& rhs);
	~InputHandler();
	bool proccesInput();
	void setKeyState(size_t index, bool status);
	bool getKeyState(size_t index);
	
protected:
	bool keystates[323] = { false };
};

