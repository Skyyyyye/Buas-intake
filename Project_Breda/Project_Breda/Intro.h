#pragma once
#include "Entity.h"
class Intro :
    public Entity
{
public:

    //main functions
    Intro();
    void loop();
    void draw(sf::RenderWindow& window);
    void mainDraw(sf::RenderWindow& window);

    //to see if the intro is still going on
    bool stillIntro = true;

private:

    //fire sprite
    sf::Texture fireTex;
    sf::Sprite fireSP;

    //bed sprite
    sf::Texture bedTex;
    sf::Sprite bedSP;

    //fade sprite
    sf::Texture blackTex;
    sf::Sprite blackSP;

    sf::Texture blackCompleteTex;
    sf::Sprite blackCompleteSP;

    sf::Font introFont;
    sf::Text introText;

    //animation clocks
    sf::Clock animationClock;
    sf::Time animationElapsed;
    float animationSec;

    //timers
    sf::Clock timerClock;

protected:

};

