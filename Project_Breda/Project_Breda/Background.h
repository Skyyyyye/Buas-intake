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

private:
    //background variables
    sf::Texture backgroundTex;
    sf::Sprite backgroundSP;

    //ice variables
    sf::Texture iceTex;
    sf::Sprite iceSP;
protected:

};

