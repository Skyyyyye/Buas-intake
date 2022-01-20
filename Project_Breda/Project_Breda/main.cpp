//functional refrences
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
//class refrences
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Trail.h"
#include "Background.h"

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
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::E)
                    {
                        Weapon.attack();
                    }
                }
            }

            //update DeltaTime
            dt = dtCLock.restart().asSeconds();

            //initate main loops
            Player.loop(dt, window, Weapon, Background.iceRect);
            Background.loop();
            Enemy.loop(dt, Player.playerPos, Player.playerRect, Player, Weapon.weaponRect, Weapon);
            Weapon.loop(Player.playerPos, window, dt, Player.Phealth);
            Trail.loop(Player.playerPos);

            // clear the window with black color
            window.clear(sf::Color::Black);

            //background drawing
            Background.draw(window);

            //foreground drawing
            Enemy.draw(window);
            Player.draw(window);
            Weapon.draw(window);

            // end the current frame
            window.display();
        }

        return 0;
    }