#include "GameObject.h"

GameObject::GameObject(){}

GameObject::GameObject(int itsX, int itsY):x(itsX), y(itsY){}

GameObject::~GameObject(){}

GameObject::GameObject(const GameObject& rhs){*this = rhs;}

GameObject& GameObject::operator=(const GameObject& rhs)
{
	if (this != &rhs)
	{
		isLeft = rhs.isLeft;
		IsSingleGame = rhs.IsSingleGame;
		dirX = rhs.dirX;
		dirY = rhs.dirY;
		speed = rhs.speed;
		radius = rhs.radius;
		angle = rhs.angle;
		objectType = rhs.objectType;
		x = rhs.x;
		y = rhs.y;
		width = rhs.width;
		height = rhs.height;
		texObject = rhs.texObject;
	}
	return *this;
}

void GameObject::setLeft(bool status)
{
	isLeft = status;
}

bool GameObject::IsLeft()const
{
	return isLeft;
}

int GameObject::getX()const{return x;}

int GameObject::getY()const {return y;}

void GameObject::setX(int itsX)	{x = itsX;}

void GameObject::setY(int itsY)	{y = itsY;}

int GameObject::getWidth()const {return width;}

int GameObject::getHeight()const	{ return height; }

void GameObject::setWidth(int itsX) { width = itsX; }

void GameObject::setHeight(int itsY) { height = itsY; }

int GameObject::getObjectType()const
{
	return objectType;
}

void GameObject::setObjectType(int tmp)
{
	objectType = tmp;
}

void GameObject::loadTexture(const char* str)
{
	SDL_Surface* pTempSurface;

	if ((pTempSurface = IMG_Load(str)) == nullptr)
	{
		throw std::runtime_error(IMG_GetError());
	}

	texObject = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(RENDERER, pTempSurface));

	if (texObject.get() == nullptr)
	{
		throw std::runtime_error(IMG_GetError());
	}
	SDL_QueryTexture(*texObject.get(), NULL, NULL, &width, &height);
	SDL_FreeSurface(pTempSurface);
}

bool GameObject::getTypeGame()const
{
	return IsSingleGame;
}

void GameObject::setTypeGame(bool status)
{
	IsSingleGame = status;
}

void GameObject::update(InputHandler& inputHandler) {}
void GameObject::render(InputHandler& inputHandler) {}

void GameObject::setdirX(int itsX) { dirX = itsX; }
void GameObject::setdirY(int itsY) { dirY = itsY; }
int GameObject::getRadius()const { return radius; }
int GameObject::getdirX()const { return dirX; }
int GameObject::getdirY()const { return dirY; }
int GameObject::getSpeed()const { return speed; }
