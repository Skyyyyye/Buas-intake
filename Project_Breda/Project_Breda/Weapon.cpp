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

void Weapon::draw(sf::Vector2f playerPos, sf::RenderWindow& window) {
	elapsed = clock.getElapsedTime();
	sec = elapsed.asSeconds();
	std::cout << sec;
	if (sec < 2) {
		window.draw(weaponSP);
		weaponSP.setPosition((playerPos.x + 5), (playerPos.y + 2));
	}

	weaponRect = weaponSP.getGlobalBounds();
}

