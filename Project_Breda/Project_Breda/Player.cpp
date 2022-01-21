#include "player.h"

//use pickup as damage animation


//upon initiate, load textures and sprites
Player::Player() {
    if (!downWalk.loadFromFile("downwalk.png"))
    {
        std::cout << "downwalk load failed";
    }
    if (!upWalk.loadFromFile("upwalk.png"))
    {
        std::cout << "upwak load failed";
    }
    if (!leftWalk.loadFromFile("leftwalk.png"))
    {
        std::cout << "leftwalk load failed";
    }
    if (!rightWalk.loadFromFile("rightwalk.png"))
    {
        std::cout << "rightwalk load failed";
    }
    if (!downIdle.loadFromFile("downidle.png"))
    {
        std::cout << "idle load failed";
    }
    if (!rightattack.loadFromFile("rightattack.png"))
    {
        std::cout << "right attack load failed";
    }
    if (!leftattack.loadFromFile("leftattack.png"))
    {
        std::cout << "left attack load failed";
    }
    if (!downattack.loadFromFile("downattack.png"))
    {
        std::cout << "downattack load failed";
    }
    if (!upattack.loadFromFile("upattack.png"))
    {
        std::cout << "upattack load failed";
    }
    if (!pickUp.loadFromFile("pickup.png"))
    {
         std::cout << " pickup load failed";
    }
    start();
}

void Player::start() {
    
    playerSP.setOrigin(27, 27);
    playerSP.setTexture(downIdle);
    playerSP.setPosition(sf::Vector2f((327.f), 327.f));
    playerSP.setScale(sf::Vector2f(1.5, 1.5));
    Phealth = 100;
}

//main loop function
void Player::loop(float dt, sf::RenderWindow& window, Weapon& Weapon, sf::FloatRect iceRect) {

    //if alive
    if (Phealth > 0) {
        
        //ice sliding movement
        if (playerRect.intersects(iceRect)) {

            //for not pressed
            bool xKeyPressed = false;
            bool yKeyPressed = false;

            //movement speed
            float speed = 0.25;

            //check for keys
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                velx += speed;
                xKeyPressed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                velx -= speed;
                xKeyPressed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                vely += speed;
                yKeyPressed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                vely -= speed;
                yKeyPressed = true;
            }
            //if a key is pressed, update the sprite for animation
            //if attacking ignore walk animation
            if (xKeyPressed && !isAttacking) {
                if (velx > 0) {
                    playerSP.setTexture(rightWalk);
                }
                else
                {
                    playerSP.setTexture(leftWalk);
                }
            }
            //if a key is pressed, update the sprite for animation
            //if attacking ignore walk animation
            if (yKeyPressed && !xKeyPressed && !isAttacking) {
                if (vely > 0) {
                    playerSP.setTexture(downWalk);
                }
                else
                {
                    playerSP.setTexture(upWalk);
                }
            }



            //if no key is pressed change to idle
            if (!yKeyPressed && !xKeyPressed) {
                playerSP.setTexture(downIdle);
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
                //stop at bounds
                if (playerPos.x < 760) {
                    velx = constSpeed;
                    xKeyPressed = true;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                //stop at bounds
                if (playerPos.x > 40) {
                    velx = -constSpeed;
                    xKeyPressed = true;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                //stop at bounds
                if (playerPos.y < 540) {
                    vely = constSpeed;
                    yKeyPressed = true;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                //stop at bounds
                if (playerPos.y > 100) {
                    vely = -constSpeed;
                    yKeyPressed = true;
                }
            }
            //if theyre not being pressed set the vel to 0
            if (!xKeyPressed) {
                velx = 0;
            }
            //if attacking ignore walk animation
            else if (!isAttacking) {
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
            //if attacking ignore walk animation
            else if (!xKeyPressed && !isAttacking) {
                if (vely > 0) {
                    playerSP.setTexture(downWalk);
                }
                else
                {
                    playerSP.setTexture(upWalk);
                }
            }
            //if no key is pressed, change to idle animation
            if (!yKeyPressed && !xKeyPressed && !isAttacking) {
                playerSP.setTexture(downIdle);
            }

            //actually move and get the place to move too
            sf::Vector2f direction = sf::getNormalized(sf::Vector2f(velx, vely));
            playerSP.move(sf::Vector2f(direction.x * constSpeed * dt, direction.y * constSpeed * dt));
        }

        //determine the direction of the attack for animation
        if (isAttacking) {

            //set origin to attacking sprite middle
            playerSP.setOrigin(27, 27);

            //set animation depending on mouse position
            //define constants
            float direction = 0;
            float pi = 3.14159265359;
            //calculate direction of mouse
            float deltax = playerPos.x - sf::Mouse::getPosition(window).x;
            float deltay = playerPos.y - sf::Mouse::getPosition(window).y;
            float deg = atan2(deltay, deltax) * 180 / pi;
            deg *= -1;
            if (deg < 0) {
                deg = deg + 359;
            }
            direction = deg;

            //actually set the texture
            if (direction > 45 && direction < 125) {
                playerSP.setTexture(downattack);
            }
            if (direction > 135 && direction < 225) {
                playerSP.setTexture(rightattack);
            }
            if (direction > 225 && direction < 315) {
                playerSP.setTexture(upattack);
            }
            if (direction > 315 || direction < 45) {
                playerSP.setTexture(leftattack);
            }
        }

        //instantly die for testing
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
            takeDamage(100);
        }

        //set immunity frames timers
        takeDElapsed = takeDClock.getElapsedTime();
        takeDSec = takeDElapsed.asSeconds();

        //communication of position
        playerPos = playerSP.getPosition();
        playerRect = playerSP.getGlobalBounds();

        //animation clock timers
        animationElapsed = animationClock.getElapsedTime();
        animationSec = animationElapsed.asSeconds();

        //see if player is able to take damage
        if (takeDSec > 1) {
            ableToTakeDam = true;
        }
        else {
            ableToTakeDam = false;
        }
    }
}

//attacking function
void Player::attack(sf::Event &event, Weapon &Weapon) {
    //check for key
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::E)
        {
            //make weapon appear
            Weapon.attack();

            //initiate attack animation
            isAttacking = true;
            playerSP.setTexture(downattack);
            animationClock.restart();
        }
    }
}

//damage function
void Player::takeDamage(int dam) {
    if (ableToTakeDam) {

        takeDClock.restart();
        Phealth = Phealth - dam;
        isTakingDamage = true;
        std::cout << Phealth;
    }
}

//draw player on screen
void Player::draw(sf::RenderWindow& window) {

    if (Phealth > 0) {
        animate();
        window.draw(playerSP);
    }
}

//animation function
void Player::animate() {
    if (animationSec < 0.16) {

        //check if were attacking
        if (playerSP.getTexture() == &downattack || &upattack || &leftattack || &rightattack) {
            playerSP.setTextureRect(sf::IntRect(4, 5, 55, 54));
        }
        else {
            playerSP.setTextureRect(sf::IntRect(25, 17, 14, 32));
        }

    }
    if (animationSec > 0.16) {

        //check if were attacking
        if (playerSP.getTexture() == &downattack || &upattack || &leftattack || &rightattack) {
            playerSP.setTextureRect(sf::IntRect(69, 5, 55, 54));
        }
        else {
            playerSP.setTextureRect(sf::IntRect(89, 17, 14, 32));
        }
        
    }
    if (animationSec > 0.33) {

        //check if were attacking
        if (playerSP.getTexture() == &downattack || &upattack || &leftattack || &rightattack) {

            playerSP.setTextureRect(sf::IntRect(4, 69, 55, 54));
        }
        else {
            playerSP.setTextureRect(sf::IntRect(153, 17, 14, 32));
        }
        
    }
    if (animationSec > 0.5) {

        //check if were attacking
        if (playerSP.getTexture() == &downattack || &upattack || &leftattack || &rightattack) {
            animationClock.restart();
            isAttacking = false;
        }

        else {
            playerSP.setTextureRect(sf::IntRect(217, 17, 14, 32));
        }
    }
    if (animationSec > 0.66) {

       playerSP.setTextureRect(sf::IntRect(25, 81, 14, 32));
    }
    if (animationSec > 0.83) {

       playerSP.setTextureRect(sf::IntRect(89, 81, 14, 32));
    }
    if (animationSec >= 1) {

            animationClock.restart();
    }
}