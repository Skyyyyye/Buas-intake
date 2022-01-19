#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"

    //initialize variables

    //time
    sf::Clock dtCLock;
    float dt;

    //sprites
    sf::Texture backGroundT;
    sf::Sprite backGround;

    void texture() {
        if (!backGroundT.loadFromFile("test.png"))
        {
                // error...
        }
        backGround.setTexture(backGroundT);
    }

    int main()
    {

        // create the window
        sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

        //initiate sprites and textures
        texture();


        Player Player;
        Enemy Enemy;
        Weapon Weapon;

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            //DeltaTime
            dt = dtCLock.restart().asSeconds();

            //movement
            Player.move(dt, window,Weapon);

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            // 
            //background drawing
            window.draw(backGround);

            //foreground drawing
            Player.drawPlayer(window);
            Enemy.drawEnemys(window, dt, Player.playerPos, Player.playerRect, Player, Weapon.weaponRect);
            Weapon.draw(Player.playerPos, window, dt, Player.Phealth);



            // end the current frame
            window.display();
        }

        return 0;
    }