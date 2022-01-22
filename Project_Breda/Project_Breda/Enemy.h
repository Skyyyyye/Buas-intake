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
    void start();
    void loop(float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect, Weapon &Weapon);
    void takeDamage(int i, int Wdam);
    void initialize(int desiredEnemy);
    void nextWave();
    void draw(sf::RenderWindow &window);

    //communicate wave to the UI
    int wave = 0;

private:

    //enemy sprite variables
    sf::Texture enemy;
    sf::Sprite enemySP[200];
    
    //wave timers and counters
    sf::Clock waveClock;
    sf::Time waveElapsed;
    float waveSec = 0;
    int enemyCount = 0;

    //immunity frame timers and damage amount to player
    sf::Clock takeDClock[200];
    sf::Time takeDElapsed[200];
    float takeDSec[200];
    int damage = 12.5;

    //for seeing is able to give damage
    sf::Clock giveDamClock;
    sf::Time giveDamElapsed;
    float giveDamSec;
    bool firstGive = true;

    //for random number gen
    bool firstRandom = true;

protected:

};

