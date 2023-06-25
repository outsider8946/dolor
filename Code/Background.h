#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{

class Background: public Sprite
{
public:
	Background();
	Background(const std::string& imagePath, bool _isAnim = false);
	Background(const std::string& imagePath, float x, float y, float _x, float _y, bool _isAnim = false);
	float getWidth () const;
	float getHeight() const;
	bool getIsAnim() const;
	void updateShop(float& currentFrame, float& time);

private:
	Texture texture;
	Image image;
	float width;
	float height;
	bool isAnim;
	std::string filePath;

};}
