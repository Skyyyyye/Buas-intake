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
    if (playerPos.x > 400 && playerPos.y > 500) {
        std::cout << moveSec;
        moveElapsed = moveClock.getElapsedTime();
        moveSec = moveElapsed.asSeconds();

        sf::Vector2f velocity;
        float vel = 100 * dt;
        if (moveSec < 1) {
            vel2 = vel * moveSec;
        }
        else if (moveSec > 1) {
            vel2 = vel * 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            velocity.x++;
            playerSP.move(sf::Vector2f((vel2), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            playerSP.move(sf::Vector2f((0), vel2));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            playerSP.move(sf::Vector2f((-vel2), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            playerSP.move(sf::Vector2f((0), -vel2));
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            moveClock.restart();
        }

    }
    else {
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
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        death(100);
    }

    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::E)
            {
                Weapon.attack();
            }
        }
    }
    giveDElapsed = giveDClock.getElapsedTime();
    giveDSec = giveDElapsed.asSeconds();
}

void Player::death(int dam) {
    Phealth = Phealth - dam;
    giveDClock.restart();
}

