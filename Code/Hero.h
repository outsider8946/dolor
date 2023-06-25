#pragma once
#include <SFML/Graphics.hpp>
#include "Abstract.h"

namespace sf
{
enum class Action { idle = 0, runToRight, runToLeft };

class Hero : public Sprite
{
public:
	Hero();
	Hero(const Texture& texture, float posX, float posY);
	Hero(const std::string imagePath, float x, float y);

	void runToLeft(float& currentFrame, float& time);
	void runToRight(float& currentFrame, float& time);
	void stay(float& currentFrame, float& time);
	bool jump(float& currentFrame, float& time);
	void changeAnimation(const std::string& imagePath, uint16_t frames);
	Action getAction();
private:
	Action action;
	float x;
	float y;
	Image image;
	Texture texture;
	uint16_t framesCount;
	
};}

