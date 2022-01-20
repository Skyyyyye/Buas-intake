#pragma once
#include "Entity.h"

class Weapon : public Entity
{
public: 

    //functions
    Weapon();
    void attack();
    void loop(sf::Vector2f playerPos, sf::RenderWindow& window, float dt, int Phealth);
    void draw(sf::RenderWindow& window);

    //communicate weapon position
    sf::FloatRect weaponRect;

    //initiate weapon damage
    int Wdam = 0;

private:

    //initiate weapon
    sf::Sprite weaponSP;
    sf::Texture weaponT;

    //initiate clocks
    sf::Clock clock;
    sf::Time elapsed;
    float sec = 0;

    //weapon rank
    int rank = 1;
};