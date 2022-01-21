#pragma once
#include "Entity.h"
class UI :
    public Entity
{
public:

    //functions
    UI();
    void loop(int health, sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void checkButtonNeeded(int health, sf::Event& event);

    //for restarting the game
    bool restart = false;

private:

    sf::Font mainFont;
    sf::Text restartText;

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

