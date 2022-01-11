#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class Player
{
public:
	Player();
	void drawPlayer(sf::RenderWindow& window);
	void move(float dt);

private: 
	sf::Texture character;
	sf::Sprite playerSP;
};

