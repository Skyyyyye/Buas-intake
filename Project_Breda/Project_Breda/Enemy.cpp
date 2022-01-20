#include "Enemy.h"

//upon initaite, load textures and sprites
Enemy::Enemy() {
    if (!enemy.loadFromFile("player.png"))
    {
        std::cout << "enemy texture load failed";
    }

    //initiate the first wave
    nextWave();
}

//main loop function
void Enemy::loop(float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect, Weapon &Weapon) {

    //update wave timers
    waveElapsed = waveClock.getElapsedTime();
    waveSec = waveElapsed.asSeconds();

    for (int i = 0; i < (wave * 3); i++) {

        //update immunity frame timers
        takeDElapsed[i] = takeDClock[i].getElapsedTime();
        takeDSec[i] = takeDElapsed[i].asSeconds();

        //if the enemy is alive
        if (EHealth[i] > 1) {

            //check if intersecting with player or weapon
            sf::FloatRect EboundingBox = enemySP[i].getGlobalBounds();
            if (Player.giveDSec > 0.5) {
                if (EboundingBox.intersects(playerRect)) {

                    Player.death(damage);
                }
            }
            if (takeDSec[i] > 0.5) {
                if (EboundingBox.intersects(weaponRect)) {

                    takeDamage(i, Weapon.Wdam);
                }
            }

            //move the enemy towards the player
            sf::Vector2f direction = sf::getNormalized(playerPos - enemySP[i].getPosition());
            enemySP[i].move(sf::Vector2f((5 * dt * direction.x), (5 * dt * direction.y)));   
        }
    }

    //check if all the enemy's are dead. if yes, start the new wave
    if (enemyCount <= 0) {

        nextWave();
    }
}

//take damage function
void Enemy::takeDamage(int i, int WeaponDam) {

   //take the damage
   EHealth[i] = EHealth[i] - WeaponDam;

   //reset immunity frames
   takeDClock[i].restart();

   //if the enemy dies by the attack
   if (EHealth[i] < 1) {
       enemyCount--;
       waveClock.restart();
   }
}

//initiate the next wave
void Enemy::nextWave() {
    if (waveSec >= 1) {
        //increase the wave
        wave++;

        //calculate the amount of enemy's to spawn
        int DE = wave * 3;

        //initiate the wave
        initialize(DE);
    }
}

//initiate a wave (called by nextWave)
void Enemy::initialize(int desiredEnemy) {
    for (int i = 0; i < desiredEnemy; i++) {

        //set textures
        enemySP[i].setTexture(enemy);
        //set positions
        enemySP[i].setPosition(sf::Vector2f(-10.f, -10.f));
        enemySP[i].move(sf::Vector2f((5.f * i), (10.f * i)));

        //set enemy active
        EHealth[i] = 100;
        enemyCount++;
    }
}

//draw function
void Enemy::draw(sf::RenderWindow &window) {
    for (int i = 0; i < (wave * 3); i++) {

        if (EHealth[i] > 1) {

            window.draw(enemySP[i]);

        }
    }
}
