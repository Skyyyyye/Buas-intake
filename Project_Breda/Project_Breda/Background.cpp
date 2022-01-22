#include "Background.h"

//upon initaite, load textures and sprites
Background::Background() {

    //load textures
    if (!backgroundTex.loadFromFile("recources/background.png"))
    {
        std::cout << "background texture load failed";
    }
    backgroundSP.setTexture(backgroundTex);

    if (!iceTex.loadFromFile("recources/ice.png"))
    {
        std::cout << "ice texture load failed";
    }
    iceSP.setTexture(iceTex);

    //set background properties
    backgroundSP.setTexture(backgroundTex);
    backgroundSP.setScale(sf::Vector2f(2, 2));
    backgroundSP.setPosition(sf::Vector2f(0, 0));

    //set ice properties
    iceSP.setTextureRect(sf::IntRect(0, 0, 450, 300));
    iceSP.setScale(sf::Vector2f(2, 2));
    iceSP.setPosition(sf::Vector2f(350, 300));
}

//main loop function
void Background::loop() {

    //update rectangle for object interaction
    iceRect = iceSP.getGlobalBounds();
}

//draw function
void Background::draw(sf::RenderWindow& window) {

    window.draw(iceSP);
}
