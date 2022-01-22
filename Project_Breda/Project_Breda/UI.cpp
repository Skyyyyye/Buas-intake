#include "UI.h"

//upon initiate load textures
UI::UI() {
    if (!healthTex.loadFromFile("recources/hearts.png"))
    {
        std::cout << "hearts texture load failed";
    }
    if (!restartButtonTex.loadFromFile("recources/buttons.png"))
    {
        std::cout << "button texture load failed";
    }
    if (!mainFont.loadFromFile("recources/m5x7.ttf"))
    {
        std::cout << "font load failed";
    }

    //set health sprite properties
    healthSP.setTexture(healthTex);
    healthSP.setPosition(sf::Vector2f(742.f ,542.f));
    healthSP.setScale(3, 3);

    //set restartbutton properties
    restartButtonSP.setTexture(restartButtonTex);
    restartButtonSP.setScale(6, 6);

    //text properties
    restartText.setFont(mainFont);
    restartText.setString("want to restart?");
    restartText.setCharacterSize(50);
    restartText.setFillColor(sf::Color::Black);

    waveText.setFont(mainFont);
    waveText.setCharacterSize(50);
    waveText.setString("wave");
    waveText.setFillColor(waveColor);
    waveText.setPosition(sf::Vector2f(600, 537));
}

//main loop function
void UI::loop(int health, sf::RenderWindow &window, int wave) {

    //check health to see what heart to switch to
    if (health == 100) {
        healthSP.setTextureRect(sf::IntRect(0, 0, 17, 17));
    }
    if (health > 75 && health != 100) {
        healthSP.setTextureRect(sf::IntRect(17, 0, 17, 17));
    }
    if (health > 50 && health < 75) {
        healthSP.setTextureRect(sf::IntRect(34, 0, 17, 17));
    }
    if (health > 25 && health < 50) {
        healthSP.setTextureRect(sf::IntRect(50, 0, 17, 17));
    }
    if (health < 25) {
        healthSP.setTextureRect(sf::IntRect(68, 0, 17, 17));
    }


    //if the player is dead
    if (health <= 0) {
        //communicate that it has to be drawn
        buttonNeeded = true;

        //set position
        restartButtonSP.setTextureRect(sf::IntRect(72, 51, 35, 10));
        restartButtonSP.setPosition(sf::Vector2f(280, 300));

        restartText.setPosition(sf::Vector2f(restartButtonSP.getPosition().x - 30, restartButtonSP.getPosition().y - 80));

        //check if the button is being hovered 
        if (restartButtonSP.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {

            //change texture while hovering over it
            restartButtonSP.setTextureRect(sf::IntRect(36, 51, 35, 10));
            hovering = true;
        }
        else {
            hovering = false;
        }
    }
    //otherwise set it to out of bounds
    else {

        restartButtonSP.setPosition(sf::Vector2f(-100.f, -100.f));
        restartText.setPosition(sf::Vector2f(-100.f, -100.f));
    }

    //wave text update
    std::string waveCount = std::to_string(wave);
    waveText.setString("wave " + waveCount);

}

//check if the button is being pressed
void UI::checkButtonNeeded(int health, sf::Event &event) {

    if (hovering) {

        if (event.type == sf::Event::MouseButtonPressed)
        {
            //if clicked
            if (event.mouseButton.button == sf::Mouse::Left) {
                restart = true;
            }
        }
    }

}

//draw the UI
void UI::draw(sf::RenderWindow &window) {

    if (buttonNeeded) {
        window.draw(restartButtonSP);
        window.draw(restartText);
    }
    window.draw(waveText);
    window.draw(healthSP);
}