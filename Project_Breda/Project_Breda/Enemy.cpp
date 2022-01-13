#include "Enemy.h"
#include "SFMLMath.hpp"
#include <iostream>
#include "Player.h"

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

void Enemy::drawEnemys(sf::RenderWindow& window, float dt, sf::Vector2f playerPos) {
    for (int i = 0; i < desiredEnemy; i++) {
        if (EHealth[i] > 50) {
            sf::Vector2f direction = sf::getNormalized(playerPos - enemySP[i].getPosition());
            enemySP[i].move(sf::Vector2f((5 * dt * direction.x),(5 * dt * direction.y)));


            window.draw(enemySP[i]);
        }
    }


}

void Enemy::Emove(float dt,sf::Vector2f playerPos) {
    //step
    for (int i = 0; i < desiredEnemy; i++) {

        //float xx = direction.x;
        //float xy = direction.y;
    }
}
