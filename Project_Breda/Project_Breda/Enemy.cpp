#include "Enemy.h"

Enemy::Enemy() {
    if (!enemy.loadFromFile("player.png"))
    {
        // error...
    }
    for (int i = 0; i < desiredEnemy; i++) {
        enemySP[i].setTexture(enemy);
        enemySP[i].move(sf::Vector2f((5.f * i), (10.f * i)));
        EHealth[i] = 100;
    }
}

void Enemy::drawEnemys(sf::RenderWindow& window) {
    for (int i = 0; i < desiredEnemy; i++) {
        if (EHealth[i] > 50) {
            window.draw(enemySP[i]);
        }

    }
}
