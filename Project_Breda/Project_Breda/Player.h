#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Health.h"
#include "weapon.h"
class Player: 
	public Health
{
public:
	Player();
	void drawPlayer(sf::RenderWindow& window);
	void move(float dt,sf::RenderWindow &window, Weapon &Weapon);
	void death(int dam);
	sf::Vector2f playerPos;
	sf::FloatRect playerRect;
	int Phealth = 100;
	float giveDSec;
private: 
	sf::Texture character;
	sf::Sprite playerSP;
	Health Health;
	sf::Clock giveDClock;
	sf::Time giveDElapsed;
	sf::Clock moveClock;
	sf::Time moveElapsed;
	float moveSec;
	float vel2;
protected:

};
