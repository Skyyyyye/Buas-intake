//functional refrences
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

//class refrencesgiu
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Trail.h"
#include "Background.h"
#include "UI.h"
#include "Intro.h"

/*
* 
library and code sources:
https://github.com/wagnrd/SFMLMath/wiki
https://www.sfml-dev.org/tutorials/2.5/
https://www.sfml-dev.org/download.php

texture and animation sources:
https://route1rodent.itch.io/16x16-rpg-character-sprite-sheet
https://managore.itch.io/m5x7
https://rmw-restaff.itch.io/restaff-december-2021
https://vectorpixelstar.itch.io/textures
https://fliflifly.itch.io/hearts-and-health-bar
https://stealthix.itch.io/rpg-nature-tileset
https://pixellad.itch.io/colorful-text-game-ui-kit
https://lelex-game-and-art-maker.itch.io/fire-animated

*/

    //initialize variables

    //time
    sf::Clock dtCLock;
    float dt;

    int main()
    {

        // create the window
        sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

        //create refrences
        Player Player;
        Enemy Enemy;
        Weapon Weapon;
        Trail Trail;
        Background Background;
        UI UI;
        Intro Intro;

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed){
                    window.close();
                }

                //check for attack
                if (!Intro.stillIntro) {
                    Player.attack(event, Weapon);
                }

                //check for restart button
                if (!Intro.stillIntro) {
                    if (Player.Phealth <= 0) {
                        UI.checkButtonNeeded(Player.Phealth, event);
                    }
                }
            }

            //game normal loop
            if (!Intro.stillIntro) {
                //update DeltaTime
                dt = dtCLock.restart().asSeconds();

                //initate main loops
                Background.loop();
                Player.loop(dt, window, Weapon, Background.iceRect);
                Enemy.loop(dt, Player.playerPos, Player.playerRect, Player, Weapon.weaponRect, Weapon);
                Weapon.loop(Player.playerPos, window, dt, Player.Phealth);
                Trail.loop(Player.playerPos);
                UI.loop(Player.Phealth, window, Enemy.wave);

                // clear the window with black color
                window.clear(sf::Color::Black);


                //draw the background in the main function due to some weird bug i cant seem to find the solution or cause to in any way. this fixes it but still
                window.draw(Background.backgroundSP);

                //background drawing
                Background.draw(window);
                Trail.draw(window);
                Intro.mainDraw(window);

                //foreground drawing
                Enemy.draw(window);
                Player.draw(window);
                Weapon.draw(window);
                UI.draw(window);


                //restart the game if triggered
                if (UI.restart) {

                    Player.start();
                    Enemy.start();
                    UI.restart = false;
                }
            }
            //intro loop for 20 sec
            else {
                
                //main loops
                Intro.loop();
                Player.intro();

                // clear the window with black color
                window.clear(sf::Color::Black);

                //draw the background in the main function due to some weird bug i cant seem to find the solution or cause to in any way. this fixes it but still
                window.draw(Background.backgroundSP);

                //draw
                Background.draw(window);
                Intro.draw(window);
                Player.draw(window);
            }

            // end the current frame
            window.display();
        }

        return 0;
    }