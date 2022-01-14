#pragma once
#include "Health.h"
#include "Player.h"

class Enemy :
    public Health
{
public:
    Enemy();
    void drawEnemys(sf::RenderWindow& window, float dt, sf::Vector2f playerPos, sf::FloatRect playerRect);
    
private:
    sf::Texture enemy;
    sf::Sprite enemySP[11];
    int desiredEnemy = 10;

};

