#include "Weapon.h"

Weapon::Weapon() {
	if (weaponT.loadFromFile("player.png"))
	{
		// error...
	}
	weaponSP.setTexture(weaponT);
}

void Weapon::attack()
{
	clock.restart();
}

void Weapon::draw(sf::Vector2f playerPos, sf::RenderWindow& window, float dt, int Phealth) {
	if (Phealth > 1) {
		elapsed = clock.getElapsedTime();
		sec = elapsed.asSeconds();
		if (sec < 2) {

			sf::Vector2f direction = sf::getNormalized((sf::Vector2f(sf::Mouse::getPosition(window))) - playerPos);
			weaponSP.setPosition(playerPos);
			weaponSP.move(sf::Vector2f((20 * direction.x), (20 * direction.y)));
			window.draw(weaponSP);
		}
		weaponRect = weaponSP.getGlobalBounds();
	}
	else {
		weaponSP.setPosition(sf::Vector2f(-10.f,-10.f));
	}
}

