#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Health.h"
#include "Enemy.h"
class Player: 
	public Health
{
public:
	Player();
	void drawPlayer(sf::RenderWindow& window);
	void move(float dt);
	void death();
	sf::Vector2f playerPos;
	sf::FloatRect playerRect;
private: 
	sf::Texture character;
	sf::Sprite playerSP;
	Health Health;
protected:
	
};
