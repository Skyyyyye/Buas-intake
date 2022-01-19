#pragma once
#include "Health.h"
#include "Player.h"

class Enemy :
    public Health
{
public:
    Enemy();
    void drawEnemys(sf::RenderWindow& window, float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect);
    void death(int i);
    int enemyCount = 0;
    int wave = 0;
    void initialize(int desiredEnemy);
    void nextWave();
private:
    sf::Texture enemy;
    sf::Sprite enemySP[50];
    sf::Clock clock;
    sf::Time elapsed;
    float sec = 0;
};

