#pragma once
#include "Entity.h"

class Weapon : public Entity
{
public: 
    Weapon();
    void attack();
    void draw(sf::Vector2f playerPos, sf::RenderWindow& window, float dt, int Phealth);
    sf::FloatRect weaponRect;
    int Wdam = 0;
private:
    sf::Sprite weaponSP;
    sf::Texture weaponT;
    sf::Clock clock;
    sf::Time elapsed;
    float sec = 0;
    int rank = 1;

};

