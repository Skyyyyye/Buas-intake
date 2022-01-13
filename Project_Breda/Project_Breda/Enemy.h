#pragma once
#include "Health.h"
class Enemy :
    public Health
{
public:
    Enemy();
    void drawEnemys(sf::RenderWindow& window, float dt, sf::Vector2f playerPos);
    void Emove(float dt,sf::Vector2f playerPos);
    
private:
    sf::Texture enemy;
    sf::Sprite enemySP[11];
    int desiredEnemy = 10;

};

