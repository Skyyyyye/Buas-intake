#pragma once
#include "Entity.h"

class Weapon : public Entity
{
public: 
    Weapon();
    void attack();
    void draw(sf::Vector2f playerPos, sf::RenderWindow& window);
    sf::FloatRect weaponRect;
private:
    sf::Sprite weaponSP;
    sf::Texture weaponT;
    sf::Clock clock;
    sf::Time elapsed;
    float sec;

};

