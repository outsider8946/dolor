#include "Background.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Assets.h"

namespace sf
{

    Background::Background()
    {

    }


    Background::Background(const std::string& imagePath, bool isAnim)
    {
        filePath = imagePath;
        width = VideoMode::getDesktopMode().width;
        height = VideoMode::getDesktopMode().height;
        image.loadFromFile(imagePath);
        texture.loadFromImage(image);
        setTexture(texture);      
    }

    Background::Background(const std::string& imagePath, float x, float y, float _x, float _y, bool _isAnim)
    {
        filePath = imagePath;
        width = _x - x;
        height = _y - y;
        image.loadFromFile(imagePath);
        texture.loadFromImage(image, IntRect(x, y, width, height));
        setTexture(texture);
    }

    float Background::getWidth() const
    {
        return width;
    }

    float Background::getHeight() const
    {
        return height;
    }

    bool Background::getIsAnim() const
    {
        return isAnim;
    }

    void Background::updateShop(float& currentFrame, float& time)
    {
        if (filePath == SHOP_ANIM)
        {
            if (currentFrame >= 6)
            {
                currentFrame -= 6;
            }
            currentFrame += 0.01 * time;
            texture.loadFromImage(image, IntRect(120 * int(currentFrame)-10, 0, 120, 120));
            setScale(4, 4);
            setTexture(texture);
        }
        else
        {
            setScale(4, 4);
        }
    }

}