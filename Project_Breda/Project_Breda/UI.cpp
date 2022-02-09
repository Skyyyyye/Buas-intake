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
    if (!snowTex.loadFromFile("recources/snoww.png"))
    {
        std::cout << "snow load failed";
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
    restartText.setString("Want to restart?");
    restartText.setCharacterSize(50);
    restartText.setFillColor(sf::Color::Black);

    waveText.setFont(mainFont);
    waveText.setCharacterSize(50);
    waveText.setString("wave");
    waveText.setFillColor(waveColor);
    waveText.setPosition(sf::Vector2f(600, 537));

    restartText2.setFont(mainFont);
    restartText2.setString("Restart");
    restartText2.setCharacterSize(50);
    restartText2.setFillColor(sf::Color::Black);

    nextWaveText.setFont(mainFont);
    nextWaveText.setCharacterSize(100);
    nextWaveText.setFillColor(sf::Color::Black);

    //snow properties
    for (int i = 0; i < 2; i++) {
        snowSP[i].setTexture(snowTex);
        snowSP[i].setScale((float)1.2, (float)1.2);
        left[i] = false;
        right[i] = false;
    }
    sf::Vector2f snow0 = sf::Vector2f(snowSP[0].getPosition().x, snowSP[0].getPosition().y - 720);
    snowSP[1].setPosition(sf::Vector2f(snow0));
}

//main loop function
void UI::loop(float health, sf::RenderWindow &window, int wave, float dt, float waveSec) {

    //check health to see what heart to switch to
    if (health == 100) {
        healthSP.setTextureRect(sf::IntRect(0, 0, 17, 17));
    }
    if (health >= 75 && health != 100) {
        healthSP.setTextureRect(sf::IntRect(17, 0, 17, 17));
    }
    if (health >= 50 && health <= 75) {
        healthSP.setTextureRect(sf::IntRect(34, 0, 17, 17));
    }
    if (health >= 25 && health <= 50) {
        healthSP.setTextureRect(sf::IntRect(50, 0, 17, 17));
    }
    if (health <= 25) {
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
        restartText2.setPosition(sf::Vector2f(restartButtonSP.getPosition().x + 46, restartButtonSP.getPosition().y - 10));

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
        restartText2.setPosition(sf::Vector2f(-100.f, -100.f));
    }

    //wave text update
    std::string waveCount = std::to_string(wave);
    waveText.setString("wave " + waveCount);

    //animate
    animationTime = animationClock.getElapsedTime();
    animationSec = animationTime.asSeconds();

    for (int i = 0; i < 2; i++) {
        if (animationSec < 0.5 && !right[i]) {
            right[i] = true;
            left[i] = false;
            snowSP[i].move(sf::Vector2f(5, 0));
        }
        if (animationSec > 0.5 && !left[i]) {
            left[i] = true;
            right[i] = false;
            snowSP[i].move(sf::Vector2f(-5, 0));
        }
    }
    if (animationSec > 1) {

        animationClock.restart();
    }
    for (int i = 0; i < 2; i++) {
        snowSP[i].move(sf::Vector2f(0, 30 * dt));
        if (snowSP[i].getPosition().y > 600) {
            snowSP[i].setPosition(0, -700);
        }
    }

    //update the wave indicator after a new wave is summoned
    if (waveSec < 2) {
        waveSecSmall = true;
        std::string waveCountPlus1 = std::to_string(wave + 1);
        nextWaveText.setString("wave " + waveCountPlus1);
        nextWaveText.setPosition(sf::Vector2f(290, 200));
    }
    else {
        waveSecSmall = false;
        nextWaveText.setPosition(sf::Vector2f(-100, -100));
    }

}

//check if the button is being pressed
void UI::checkButtonNeeded(sf::Event &event) {

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
        for (int i = 0; i < 2; i++) {
            window.draw(snowSP[i]);
        }
        window.draw(restartButtonSP);
        window.draw(restartText);
        window.draw(restartText2);
    }
    for (int i = 0; i < 2; i++) {
        window.draw(snowSP[i]);
    }
    if (waveSecSmall) {
            window.draw(nextWaveText);
    }
    window.draw(waveText);
    window.draw(healthSP);
}