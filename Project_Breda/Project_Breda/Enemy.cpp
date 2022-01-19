#include "Enemy.h"

Enemy::Enemy() {
    if (!enemy.loadFromFile("player.png"))
    {
        // error...
    }
    nextWave();
}

void Enemy::initialize(int desiredEnemy) {
    for (int i = 0; i < desiredEnemy; i++) {
        enemySP[i].setTexture(enemy);
        enemySP[i].setPosition(sf::Vector2f(-10.f,  - 10.f));
        enemySP[i].move(sf::Vector2f((5.f * i), (10.f * i)));
        EHealth[i] = 100;
        enemyCount++;
    }
}

void Enemy::drawEnemys(sf::RenderWindow& window, float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect, Weapon &Weapon) {

    for (int i = 0; i < (wave * 3); i++) {

        takeDElapsed[i] = takeDClock[i].getElapsedTime();
        takeDSec[i] = takeDElapsed[i].asSeconds();

        int dam = 20;
        if (EHealth[i] > 1) {

            sf::FloatRect EboundingBox = enemySP[i].getGlobalBounds();
            if (Player.giveDSec > 0.5) {
                if (EboundingBox.intersects(playerRect)) {
                    Player.death(dam);
                }
            }
            if (takeDSec[i] > 0.5) {
                if (EboundingBox.intersects(weaponRect)) {
                    death(i, Weapon.Wdam);
                }
            }
            sf::Vector2f direction = sf::getNormalized(playerPos - enemySP[i].getPosition());
            enemySP[i].move(sf::Vector2f((5 * dt * direction.x), (5 * dt * direction.y)));
            if (EHealth[i] > 1) {
                window.draw(enemySP[i]);
            }
        }
    }
    if (enemyCount <= 0) {
        nextWave();
    }
    waveElapsed = waveClock.getElapsedTime();
    waveSec = waveElapsed.asSeconds();
}

void Enemy::death(int i, int Wdam) {
   EHealth[i] = EHealth[i] - Wdam;
   takeDClock[i].restart();
   if (EHealth[i] < 1) {
       enemyCount--;
       waveClock.restart();
   }
}

void Enemy::nextWave() {

    if (waveSec >= 1) {
        wave++;
        int DE = wave * 3;
        initialize(DE);
    }
}
