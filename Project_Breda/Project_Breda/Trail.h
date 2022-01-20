#pragma once
#include "Entity.h"
#include "Player.h"

class Trail :
    public Entity
{
public:
    Trail();
    void loop(sf::Vector2f playerPos, sf::RenderWindow &window);
    void dissapear();
    void appear(sf::Vector2f playerPos, int i);
    int b = 0;
private:
    sf::Clock trailClock[50];
    sf::Time trailElapsed[50];
    float trailSec[50];

    sf::Sprite trailSP[50];
    sf::Texture trailTex;

    float distance = 0;
    sf::Vector2f prevPos;

    bool spawn[50];
protected:

};

