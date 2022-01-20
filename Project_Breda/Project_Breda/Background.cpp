#include "Background.h"

//upon initaite, load textures and sprites
Background::Background() {
    if (!backgroundTex.loadFromFile("background.png"))
    {
        std::cout << "background texture load failed";
    }
    backgroundSP.setTexture(backgroundTex);

    if (!iceTex.loadFromFile("ice.png"))
    {
        std::cout << "ice texture load failed";
    }
    iceSP.setTexture(iceTex);

    backgroundTex.setRepeated(true);
    backgroundSP.setTextureRect(sf::IntRect(0, 0, 800, 600));

    iceTex.setRepeated(true);
    iceSP.setTextureRect(sf::IntRect(0, 0, 450, 300));
    iceSP.setScale(sf::Vector2f(2, 2));

    //set background position 
    iceSP.setPosition(sf::Vector2f(350, 300));
}

//main loop function
void Background::loop() {

    //update rectangle for object interaction
    iceRect = iceSP.getGlobalBounds();
}

//draw function
void Background::draw(sf::RenderWindow& window) {

    window.draw(backgroundSP);
    window.draw(iceSP);
}
