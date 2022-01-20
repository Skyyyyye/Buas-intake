#include "player.h"


//create player
Player::Player() {
    if (!character.loadFromFile("player.png"))
    {
        // error...
    }
    playerSP.setTexture(character);
    playerSP.move(sf::Vector2f((300.f), 300.f));
}



//draw player on screen
void Player::drawPlayer(sf::RenderWindow& window) {
    
    playerPos = playerSP.getPosition();
    playerRect = playerSP.getGlobalBounds();

    if (Phealth > 1) {
        window.draw(playerSP);
    }
}

//movement
void Player::move(float dt,sf::RenderWindow &window,Weapon &Weapon) {
    if (playerPos.x > 400 && playerPos.y > 400) {

        float speed = 0.4;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            velx += speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            velx -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            vely += speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            vely -= speed;
        }
        float drag = 0.999;
        velx *= drag;
        vely *= drag;
        playerSP.move(sf::Vector2f(velx * dt, vely * dt));
    }
    else {
        bool xKeyPressed = false;
        bool yKeyPressed = false;
        float constSpeed = 100;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            velx = constSpeed;
            xKeyPressed = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            velx = -constSpeed;
            xKeyPressed = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            vely = constSpeed;
            yKeyPressed = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            vely = -constSpeed;
            yKeyPressed = true;
        }
        if (!xKeyPressed) {
            velx = 0;
        }
        if (!yKeyPressed) {
            vely = 0;
        }
        sf::Vector2f direction = sf::getNormalized(sf::Vector2f(velx, vely));
        playerSP.move(sf::Vector2f(direction.x * constSpeed * dt, direction.y * constSpeed * dt));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        death(100);
    }

    giveDElapsed = giveDClock.getElapsedTime();
    giveDSec = giveDElapsed.asSeconds();
}

void Player::death(int dam) {
    Phealth = Phealth - dam;
    giveDClock.restart();
}

