#include "Animation.h"
namespace sf
{
	Animation::Animation(Sprite& target1, const int imagesCount)
	{
		target = target1;
		image = target.getTexture()->copyToImage();
		count = imagesCount;
	}
	void Animation::update(float& currentFrame, float& time)
	{
		currentFrame += 10 * time;

		if (currentFrame > count)
		{
			currentFrame -= count;
		}

	
		const uint16_t width = image.getSize().x / count;
		const uint16_t heigth = image.getSize().y;

		Texture texture;
		texture.loadFromImage(image, IntRect(width * int(currentFrame), 0, width, heigth));
		target.setTexture(texture);
	}
}
