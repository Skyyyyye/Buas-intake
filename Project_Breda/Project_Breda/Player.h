#pragma once
#include "Health.h"
#include "weapon.h"
class Player: 
	public Health
{
public:
	//functions
	Player();
	void draw(sf::RenderWindow& window);
	void loop(float dt,sf::RenderWindow &window, Weapon &Weapon, sf::FloatRect iceRect);
	void takeDamage(int dam);
	void animate();

	//communicate positions
	sf::Vector2f playerPos;
	sf::FloatRect playerRect;

	//health
	int Phealth = 100;

	//communicate damage immunity frames
	float giveDSec;

private: 
	//initiate player 
	sf::Sprite playerSP;

	//initiate textures
	sf::Texture rightWalk;
	sf::Texture leftWalk;
	sf::Texture upWalk;
	sf::Texture downWalk;
	sf::Texture downIdle;


	//initiate immunity frame clocks
	sf::Clock giveDClock;
	sf::Time giveDElapsed;

	//movement variables
	float velx = 0;
	float vely = 0;

	//animation variables
	sf::Clock animationClock;
	sf::Time animationElapsed;
	float animationSec;

protected:

};
