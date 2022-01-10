#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

    //initialize variables

    //time
    sf::Clock dtCLock;
    float dt;

    //sprites
    sf::Texture character;
    sf::Sprite player;


    void move() //movement
    {
        float vel = 100 * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            player.move(sf::Vector2f((vel), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            player.move(sf::Vector2f((0), vel));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            player.move(sf::Vector2f((-vel), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            player.move(sf::Vector2f((0), -vel));
        }
    }

int main()
{

    // create the window
    sf::RenderWindow window(sf::VideoMode(900, 700), "My window");

    //initiate sprites
    if (!character.loadFromFile("player.png"))
    {
        // error...
    }
    character.setSmooth(true);
    player.setTexture(character);





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

        move();


        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        window.draw(player);

        // end the current frame
        window.display();
    }

    return 0;
}