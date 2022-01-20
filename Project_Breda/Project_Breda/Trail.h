#pragma once
#include "Entity.h"
#include "Player.h"

class Trail :
    public Entity
{
public:
    //functions
    Trail();
    void loop(sf::Vector2f playerPos);
    void appear(sf::Vector2f playerPos, int i);
    void draw(sf::RenderWindow& window);

private:
    //dissapear timers
    sf::Clock trailClock[50];
    sf::Time trailElapsed[50];
    float trailSec[50];

    //initiate trails
    sf::Sprite trailSP[50];
    sf::Texture trailTex;

    //distance calculation variables
    float distance = 0;
    sf::Vector2f prevPos;

    //if trail active
    bool spawn[50];
    int b = 0;

protected:

};

