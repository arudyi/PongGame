#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <exception>
#include <stdexcept>
#include <map>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

enum ObjectsType
{
	WORLD_TEX,
	BALL,
	LEFT,
	RIGHT,
	ARROW_TEX,
	SINGLE_TEX,
	TWO_TEX
};

const int WINWIDTH = 1000;
const int WINHEIGHT = 700;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
extern SDL_Renderer* RENDERER;
extern SDL_Window* WINDOW;

void draw(SDL_Texture* texture, int x, int y, int width, int height, SDL_Renderer* ren, SDL_RendererFlip flip);
	