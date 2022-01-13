#include "player.h"
#include "Enemy.h"
#include <iostream>


//create player
Player::Player() {
    if (!character.loadFromFile("player.png"))
    {
        // error...
    }
    playerSP.setTexture(character);

}

//draw player on screen
void Player::drawPlayer(sf::RenderWindow& window) {
    if (health > 50) {
        window.draw(playerSP);
        playerPos = playerSP.getPosition();
    }
}

//movement
void Player::move(float dt) {
    float vel = 100 * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        playerSP.move(sf::Vector2f((vel), 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        playerSP.move(sf::Vector2f((0), vel));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        playerSP.move(sf::Vector2f((-vel), 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        playerSP.move(sf::Vector2f((0), -vel));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        health = 40;
    }
}
