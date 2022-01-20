#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Trail.h"
#include "Background.h"

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
            Background.loop();
            Player.move(dt, window,Weapon);

            // clear the window with black color
            window.clear(sf::Color::Black);

            //background drawing
            Background.draw(window);

            //foreground drawing
            Player.drawPlayer(window);
            Enemy.drawEnemys(window, dt, Player.playerPos, Player.playerRect, Player, Weapon.weaponRect, Weapon);
            Weapon.draw(Player.playerPos, window, dt, Player.Phealth);
            Trail.loop(Player.playerPos, window);




            // end the current frame
            window.display();
        }

        return 0;
    }