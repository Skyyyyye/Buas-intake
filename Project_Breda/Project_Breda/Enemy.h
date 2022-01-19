#pragma once
#include "Health.h"
#include "Player.h"
#include "Weapon.h"

class Enemy :
    public Health
{
public:
    Enemy();
    void drawEnemys(sf::RenderWindow& window, float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect, Weapon &Weapon);
    void death(int i, int Wdam);
    int enemyCount = 0;
    int wave = 0;
    void initialize(int desiredEnemy);
    void nextWave();
private:
    sf::Texture enemy;
    sf::Sprite enemySP[50];
    
    sf::Clock waveClock;
    sf::Time waveElapsed;
    float waveSec = 0;

    sf::Clock takeDClock[50];
    sf::Time takeDElapsed[50];
    float takeDSec[50];


};

