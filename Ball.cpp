#include "Ball.h"

Ball::Ball() :GameObject(0, 0) {}

Ball::Ball(int x, int y, const char * pathTexture) : GameObject(x, y)
{
	srand(time(NULL));
	loadTexture(pathTexture);
	angle = 120 + rand() % 120;
	speed = 10;
	dirX = speed * cos(angle * M_PI / 180);
	dirY = speed * sin(angle * M_PI / 180);
	radius = width / 2;
	objectType = BALL;
}

Ball::Ball(const Ball& rhs)
{
	*this = rhs;
}

Ball::~Ball()
{

}

Ball& Ball::operator=(const Ball& rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		dirX = rhs.dirX;
		dirY = rhs.dirY;
		radius = rhs.radius;
		angle = rhs.angle;
		speed = speed;
		width = rhs.width;
		height = rhs.height;
	}
	return *this;
}

void Ball::restart() 
{
	x = WINWIDTH / 2;
	y = WINHEIGHT / 2;
	angle = 120 + rand() % 120;
	speed = 10;
	dirX = speed * cos(angle * M_PI / 180);
	dirY = speed * sin(angle * M_PI / 180);
}

void Ball::update(InputHandler& inputHandler)
{
	static Uint32 frameStart = SDL_GetTicks();
	
	x += dirX;
	y += dirY;

	if ((x + radius) < 0)
	{
		right.setCounter(right.getCounter() + 1);
		restart();
	}
	if ((x - radius) > WINWIDTH)
	{
		left.setCounter(left.getCounter() + 1);
		
		restart();
	}

	if ((y - radius) <= 0 || (y + radius) >= WINHEIGHT)
	{
		dirY *= -1;
	}
	Uint32 frameTime = SDL_GetTicks() - frameStart;
	if (frameTime >= 10000)
	{
		frameStart = SDL_GetTicks();
		speed += 1;
	}
}

void Ball::render(InputHandler& inputHandler)
{
	draw(*texObject.get(), x - radius, y - radius, width, height, RENDERER, SDL_FLIP_NONE);
	left.render(inputHandler);
	right.render(inputHandler);
}