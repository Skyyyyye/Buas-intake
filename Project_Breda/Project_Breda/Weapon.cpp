#include "Weapon.h"

//upon initiate, load textures and sprites
Weapon::Weapon() {
	if (weaponT.loadFromFile("recources/weapon.png"))
	{
		// error...
	}
	weaponSP.setTexture(weaponT);
}

//initiate attack function
void Weapon::attack()
{
	clock.restart();
}

//main loop function
void Weapon::loop(sf::Vector2f playerPos, sf::RenderWindow& window, float dt, int Phealth) {

	//set damage amount
	Wdam = rank * 20;

	//communicate location 
	weaponRect = weaponSP.getGlobalBounds();

	//if player alive
	if (Phealth > 1) {

		//get timers
		elapsed = clock.getElapsedTime();
		sec = elapsed.asSeconds();

		//if attack was initiated
		if (sec < 0.5) {

			//get direction
			sf::Vector2f direction = sf::getNormalized((sf::Vector2f(sf::Mouse::getPosition(window))) - playerPos);

			//set position relative to the player
			weaponSP.setPosition(playerPos);
			weaponSP.move(sf::Vector2f((40 * direction.x), (40 * direction.y)));
		}
		//otherwise set position outside window
		else {

			weaponSP.setPosition(sf::Vector2f(-100.f, -100.f));
		}
	}
	//otherwise set position outside window
	else {

		weaponSP.setPosition(sf::Vector2f(-100.f, -100.f));
	}
}

//draw function
void Weapon::draw(sf::RenderWindow& window) {

	window.draw(weaponSP);
}
