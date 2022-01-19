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

void Enemy::drawEnemys(sf::RenderWindow& window, float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect) {
    for (int i = 0; i < (wave * 3); i++) {
        if (EHealth[i] > 50) {

            sf::FloatRect EboundingBox = enemySP[i].getGlobalBounds();
            if (EboundingBox.intersects(playerRect)) {
                Player.death();
            }
            if (EboundingBox.intersects(weaponRect)) {
                death(i);
            }
            sf::Vector2f direction = sf::getNormalized(playerPos - enemySP[i].getPosition());
            enemySP[i].move(sf::Vector2f((5 * dt * direction.x),(5 * dt * direction.y)));
            window.draw(enemySP[i]);
        }
    }
    
    elapsed = clock.getElapsedTime();
    sec = elapsed.asSeconds();

    if (enemyCount <= 0) {
        nextWave();
    }
}

void Enemy::death(int i) {
    EHealth[i] = 1;
    enemyCount--;
    clock.restart();
 
}

void Enemy::nextWave() {

    if (sec >= 1) {
        wave++;
        int DE = wave * 3;
        initialize(DE);
    }
}
