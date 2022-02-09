#pragma once
#include "Health.h"
#include "weapon.h"
class Player: 
	public Health
{
public:
	//functions
	Player();
	void start();
	void draw(sf::RenderWindow& window);
	void loop(float dt,sf::RenderWindow &window, Weapon &Weapon, sf::FloatRect iceRect);
	void attack(sf::Event& event, Weapon &Weapon);
	void takeDamage(float dam);
	void animate();
	void intro();
	void resetHealth();

	//communicate positions
	sf::Vector2f playerPos;
	sf::FloatRect playerRect;

	//health
	float Phealth = 100;

	//communicate damage immunity frames
	float takeDSec;
	bool isTakingDamage = false;
	bool ableToTakeDam = false;

	//attack state
	bool isAttacking = false;

private: 
	//initiate player 
	sf::Sprite playerSP;

	//initiate textures
	sf::Texture rightWalk;
	sf::Texture leftWalk;
	sf::Texture upWalk;
	sf::Texture downWalk;
	sf::Texture downIdle;

	sf::Texture downattack;
	sf::Texture upattack;
	sf::Texture leftattack;
	sf::Texture rightattack;

	sf::Texture pickUp;


	//initiate immunity frame clocks
	sf::Clock takeDClock;
	sf::Time takeDElapsed;

	//movement variables
	float velx = 0;
	float vely = 0;

	//animation variables
	sf::Clock animationClock;
	sf::Time animationElapsed;
	float animationSec;



protected:

};
