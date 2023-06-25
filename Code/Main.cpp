#include "Background.h"
#include "Hero.h"
#include "Animation.h"
#include "Assets.h"


int main()
{
    //Creation of  window
    sf::String str = "Last Hero";
    sf::VideoMode screen;
    screen = screen.getDesktopMode();

    sf::RenderWindow window(sf::VideoMode(screen.width, screen.height), str);

   //Creation of background
   sf::Background YFLayer1(BGLAYER1);
   YFLayer1.scale(6, 6);
   sf::Background YFLayer2(BGLAYER2);
   YFLayer2.scale(6, 6);
   sf::Background YFLayer3(BGLAYER3);
   YFLayer3.scale(6, 6);

   sf::Background ground(WOODGROUND,120,215,190,240);
   ground.scale(6, 6);

  // sf::Background aShop(SHOP_ANIM,0,0,120,120);

   sf::Hero shop(SHOP,120,215);
   shop.changeAnimation(SHOP_ANIM, 6);
   shop.setScale(4, 4);

   

   //Creation of hero
   sf::Hero knight(KNIGHTIDLE, 100, 100);
   knight.setScale(5, 5);
  
   float currentFrame = 0;
   sf::Clock clock;

   // animation of run to right to knight 
   //sf::Animation animation(shop, 6);
   
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        
        time = time/1400;

        sf::Event event;

        while (window.pollEvent(event))
        {
            // movement hero
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }             
            else if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                                                           
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {   
                    if (knight.getAction() == sf::Action::idle)
                    {
                        knight.setPosition(knight.getPosition().x + 100, knight.getPosition().y);
                    }
                    
                    if (knight.getAction() != sf::Action::runToLeft)
                    {
                        knight.changeAnimation(KNIGHTRIGHTRUN, 8);
                    }
                   
                    knight.runToLeft(currentFrame, time);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    if (knight.getAction() == sf::Action::idle)
                    {
                        knight.setPosition(knight.getPosition().x - 100, knight.getPosition().y);
                    }

                    if (knight.getAction() != sf::Action::runToRight)
                    {
                        knight.changeAnimation(KNIGHTRIGHTRUN, 8);
                    }
                    
                    knight.runToRight(currentFrame, time);  
                }
            }
            else if(event.type == sf::Event::KeyReleased)
            {
                if (knight.getAction() == sf::Action::runToLeft)
                {
                    knight.setPosition(knight.getPosition().x - 100, knight.getPosition().y);
                }
                else if (knight.getAction() == sf::Action::runToRight)
                {
                    knight.setPosition(knight.getPosition().x + 100, knight.getPosition().y);
                }

                knight.changeAnimation(KNIGHTIDLE, 15);
                knight.stay(currentFrame, time);
            }
        }

        shop.stay(currentFrame, time);

        window.clear();

        window.draw(YFLayer1);
        window.draw(YFLayer2);
        window.draw(YFLayer3);
        for (int i = 0,j=0; i <= screen.width;j++)
        {
            window.draw(ground);
            ground.setPosition(6*ground.getWidth() * j,  screen.height - 6*ground.getHeight());
            i += 6*ground.getWidth();
        }
       
        

        if (knight.getAction() == sf::Action::idle)
        {
            knight.changeAnimation(KNIGHTIDLE, 15);
            knight.stay(currentFrame, time);
        }

        window.draw(shop);

        window.draw(knight);
        window.display();  
    }

    return 0;
}

