#include "Hero.h"
#include "SFML/Graphics/Sprite.hpp"

namespace sf
{
Hero::Hero()
{
}


Hero::Hero(const Texture& texture_, float posX, float posY)
{
	texture = texture_;
	x = posX;
	y = posY;
	setPosition(x, y);
	setScale(3, 3);
}

Hero::Hero(const std::string imagePath, float posX, float posY)
{
	image.loadFromFile(imagePath);
	texture.loadFromImage(image);
	x = posX;
	y = posY;
	action = Action::idle;
	setPosition(x, y);
	setScale(3, 3);

}


void Hero::runToLeft(float &currentFrame, float& time)
{
	action = Action::runToLeft;
	currentFrame += 100 * time;

	if (currentFrame > framesCount)
	{
		currentFrame -= framesCount;
	}

	const uint16_t width = image.getSize().x / framesCount;
	const uint16_t heigth = image.getSize().y;
    texture.loadFromImage(image, IntRect(width * int(currentFrame), 0, width, heigth));
	setTexture(texture);

	if (getScale().x > 0)
	{
		setScale(-5, 5);
		setPosition(getPosition().x + 5*width, getPosition().y);
	}

	move(-10000 * time,0);
}

void Hero::runToRight(float& currentFrame, float& time)
{
	action = Action::runToRight;
	currentFrame += 100 * time;

	if (currentFrame > framesCount)
	{
		currentFrame -= framesCount;
	}
	
	const uint16_t width = image.getSize().x/framesCount;
	const uint16_t heigth = image.getSize().y;
	texture.loadFromImage(image, IntRect(width* int(currentFrame), 0, width, heigth));
	setTexture(texture);

	if (getScale().x < 0)
	{
		setScale(5, 5);
		setPosition(getPosition().x - 5*width, getPosition().y);
	}
	
    move( 10000*time,0);
}

void Hero::stay(float& currentFrame, float& time)
{
	action = Action::idle;
	currentFrame +=  10*time;

	if (currentFrame > framesCount)
	{
		currentFrame -= framesCount;
	}	
	
	const uint16_t width = image.getSize().x/framesCount;
	const uint16_t heigth = image.getSize().y;
	texture.loadFromImage(image, IntRect(width * int(currentFrame), 0, width, heigth));
	setTexture(texture);
}

bool Hero::jump(float& currentFrame, float& time)
{
	bool isSucess = false;
	if (currentFrame == 6)
	{
		currentFrame -= 6;
		isSucess = true;
	}
	currentFrame += 0.12 * time;

	texture.loadFromImage(image, IntRect(30 * int(currentFrame), 170, 32, 30));
	setTexture(texture);
	return isSucess;
}

void Hero::changeAnimation(const std::string& imagePath, uint16_t frames)
{
	image.loadFromFile(imagePath);
	texture.loadFromImage(image);
	framesCount = frames;
}

Action Hero::getAction()
{
	return action;
}

}

