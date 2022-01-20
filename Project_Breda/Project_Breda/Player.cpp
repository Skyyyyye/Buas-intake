#include "player.h"

//use pickup as damage animation


//upon initiate, load textures and sprites
Player::Player() {
    if (!downWalk.loadFromFile("downwalk.png"))
    {
        // error...
    }
    if (!upWalk.loadFromFile("upwalk.png"))

    {
        // error...
    }
    if (!leftWalk.loadFromFile("leftwalk.png"))
    {
        // error...
    }
    if (!rightWalk.loadFromFile("rightwalk.png"))
    {
        // error...
    }
    if (!downIdle.loadFromFile("downidle.png"))
    {
        // error...
    }
    playerSP.setTexture(downIdle);
    playerSP.move(sf::Vector2f((300.f), 300.f));
    playerSP.setScale(sf::Vector2f(1.5, 1.5));
}

//main loop function
void Player::loop(float dt, sf::RenderWindow& window, Weapon& Weapon, sf::FloatRect iceRect) {

    if (Phealth > 0) {
        //ice sliding movement
        if (playerRect.intersects(iceRect)) {

            //movement speed
            float speed = 0.25;

            //check for keys
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                velx += speed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                velx -= speed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                vely += speed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                vely -= speed;
            }

            //to prevent infinite acceleration
            float drag = 0.999;
            velx *= drag;
            vely *= drag;

            //actually move the player
            playerSP.move(sf::Vector2f(velx * dt, vely * dt));
        }
        //normal movement
        else {

            //for not pressed
            bool xKeyPressed = false;
            bool yKeyPressed = false;

            //movement speed
            float constSpeed = 100;

            //check for keys
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                velx = constSpeed;
                xKeyPressed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                velx = -constSpeed;
                xKeyPressed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                vely = constSpeed;
                yKeyPressed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                vely = -constSpeed;
                yKeyPressed = true;
            }
            //if theyre not being pressed set the vel to 0
            if (!xKeyPressed) {
                velx = 0;
            }
            else {
                //if a key is pressed, update the sprite for animation
                if (velx > 0) {
                    playerSP.setTexture(rightWalk);
                }
                else
                {
                    playerSP.setTexture(leftWalk);
                }
            }
            if (!yKeyPressed) {
                vely = 0;
            }
            //if a key is pressed, update the sprite for animation
            else if (!xKeyPressed) {
                if (vely > 0) {
                    playerSP.setTexture(downWalk);
                }
                else
                {
                    playerSP.setTexture(upWalk);
                }
            }
            //if no key is pressed, change to idle animation
            if (!yKeyPressed && !xKeyPressed) {
                playerSP.setTexture(downIdle);
            }

            //actually move and get the place to move too
            sf::Vector2f direction = sf::getNormalized(sf::Vector2f(velx, vely));
            playerSP.move(sf::Vector2f(direction.x * constSpeed * dt, direction.y * constSpeed * dt));
        }

        //instantly die for testing
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            takeDamage(100);
        }

        //set immunity frames timers
        giveDElapsed = giveDClock.getElapsedTime();
        giveDSec = giveDElapsed.asSeconds();

        //communication of position
        playerPos = playerSP.getPosition();
        playerRect = playerSP.getGlobalBounds();

        //animation clock timers
        animationElapsed = animationClock.getElapsedTime();
        animationSec = animationElapsed.asSeconds();
    }
}

void Player::takeDamage(int dam) {
    Phealth = Phealth - dam;
    giveDClock.restart();
}

//draw player on screen
void Player::draw(sf::RenderWindow& window) {

    if (Phealth > 0) {
        animate();
        window.draw(playerSP);
    }
}

void Player::animate() {
    if (animationSec < 0.16) {
        playerSP.setTextureRect(sf::IntRect(25, 17, 14, 32));
    }
    if (animationSec > 0.16) {
        playerSP.setTextureRect(sf::IntRect(89, 17, 14, 32));
    }
    if (animationSec > 0.33) {
        playerSP.setTextureRect(sf::IntRect(153, 17, 14, 32));
    }
    if (animationSec > 0.5) {
        playerSP.setTextureRect(sf::IntRect(217, 17, 14, 32));
    }
    if (animationSec > 0.66) {
        playerSP.setTextureRect(sf::IntRect(25, 81, 14, 32));
    }
    if (animationSec > 0.83) {
        if (playerSP.getTexture() == &downIdle) {
            animationClock.restart();
        }
        else {
            playerSP.setTextureRect(sf::IntRect(89, 81, 14, 32));
        }
    }
    if (animationSec >= 1) {
        animationClock.restart();
    }
}