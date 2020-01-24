#include "InputHandler.h"

InputHandler::InputHandler(){}
InputHandler::InputHandler(const InputHandler& rhs) { *this = rhs; }
InputHandler& InputHandler::operator=(const InputHandler& rhs)
{
	if (this != &rhs)
	{
		*keystates = rhs.keystates;
	}
	return *this;
}
InputHandler::~InputHandler(){}

bool InputHandler::proccesInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			return false;
		}
		else if (event.type == SDL_KEYDOWN)
			keystates[event.key.keysym.scancode] = true;
		else if (event.type == SDL_KEYUP)
			keystates[event.key.keysym.scancode] = false;
	}
	return true;
}

void InputHandler::setKeyState(size_t index, bool status)
{
	if (index > 322)
	{
		throw std::out_of_range("index > 322");
	}
	keystates[index] = status;
}

bool InputHandler::getKeyState(size_t index)
{
	if (index > 322)
	{
		throw std::out_of_range("index > 322");
	}
	return keystates[index];
}