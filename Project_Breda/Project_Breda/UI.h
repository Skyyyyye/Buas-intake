#pragma once
#include "Entity.h"
class UI :
    public Entity
{
public:

    //functions
    UI();
    void loop(float health, sf::RenderWindow &window, int wave, float dt, float waveSec);
    void draw(sf::RenderWindow &window);
    void checkButtonNeeded(sf::Event& event);

    //for restarting the game
    bool restart = false;

private:

    //texts
    sf::Font mainFont;
    sf::Text restartText;
    sf::Text waveText;
    sf::Color waveColor = sf::Color(41, 41, 41, 255);
    sf::Text restartText2;
    sf::Text nextWaveText;

    //health sprite
    sf::Texture healthTex;
    sf::Sprite healthSP;

    //restart button sprite
    sf::Texture restartButtonTex;
    sf::Sprite restartButtonSP;
    bool buttonNeeded = false;
    bool hovering = false;

    //snow sprite
    sf::Texture snowTex;
    sf::Sprite snowSP[2];

    //snow animation
    sf::Clock animationClock;
    sf::Time animationTime;
    float animationSec = 0;

    bool left[2];
    bool right[2];

    bool waveSecSmall = false;

protected:

};

