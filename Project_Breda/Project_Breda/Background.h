#pragma once
#include "Entity.h"
class Background :
    public Entity
{
public:

    //functions
    Background();
    void loop();
    void draw(sf::RenderWindow& window);

    //public variables
    sf::FloatRect iceRect;

    //needs to be public so main can draw the sprite
    sf::Sprite backgroundSP;

private:

    //background variables
    sf::Texture backgroundTex;

    //ice variables
    sf::Texture iceTex;
    sf::Sprite iceSP;

protected:

};

