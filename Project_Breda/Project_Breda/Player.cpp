#include "player.h"
#include <iostream>


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

    if (Phealth > 50) {
        window.draw(playerSP);
    }
}

//movement
void Player::move(float dt,sf::RenderWindow &window,Weapon &Weapon) {
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        death();
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
    

}

void Player::death() {
    Phealth = 40;
}

