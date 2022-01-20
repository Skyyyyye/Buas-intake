#pragma once
#include "Health.h"
#include "Player.h"
#include "Weapon.h"

class Enemy :
    public Health
{
public:

    //functions
    Enemy();
    void loop(float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect, Weapon &Weapon);
    void takeDamage(int i, int Wdam);
    void initialize(int desiredEnemy);
    void nextWave();
    void draw(sf::RenderWindow &window);

private:
    //enemy sprite variables
    sf::Texture enemy;
    sf::Sprite enemySP[50];
    
    //wave timers and counters
    sf::Clock waveClock;
    sf::Time waveElapsed;
    float waveSec = 0;
    int enemyCount = 0;
    int wave = 0;

    //immunity frame timers and damage amount to player
    sf::Clock takeDClock[50];
    sf::Time takeDElapsed[50];
    float takeDSec[50];
    int damage = 20;
};

