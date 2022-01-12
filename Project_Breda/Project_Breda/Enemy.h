#pragma once
#include "Health.h"
class Enemy :
    public Health
{
public:
    Enemy();
    void drawEnemys(sf::RenderWindow& window);

private:
    sf::Texture enemy;
    sf::Sprite enemySP[11];
    int desiredEnemy = 10;

};

