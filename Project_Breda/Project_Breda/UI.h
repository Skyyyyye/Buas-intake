#pragma once
#include "Entity.h"
class UI :
    public Entity
{
public:

    //functions
    UI();
    void loop(int health, sf::RenderWindow &window, int wave);
    void draw(sf::RenderWindow &window);
    void checkButtonNeeded(int health, sf::Event& event);

    //for restarting the game
    bool restart = false;

private:

    //texts
    sf::Font mainFont;
    sf::Text restartText;
    sf::Text waveText;
    sf::Color waveColor = sf::Color(41, 41, 41, 255);

    //health sprite
    sf::Texture healthTex;
    sf::Sprite healthSP;

    //restart button sprite
    sf::Texture restartButtonTex;
    sf::Sprite restartButtonSP;
    bool buttonNeeded = false;
    bool hovering = false;

protected:

};

