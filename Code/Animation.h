#pragma once
#include <SFML/Graphics.hpp>
#include "Hero.h"
namespace sf
{
class Animation
{
public:
	Animation(Sprite& target1, const int imagesCount);
	void update(float& currentFrame, float& time);
private:
	Sprite target;
	Image image;
	int count;
};
}
