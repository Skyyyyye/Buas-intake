#include "Intro.h"

//initialize spites and textures
Intro::Intro() {

	if (!bedTex.loadFromFile("recources/bed.png"))
	{
		std::cout << "bed texture load failed";
	}
	bedSP.setTexture(bedTex);
	if (!fireTex.loadFromFile("recources/fire.png"))
	{
		std::cout << "fire texture load failed";
	}
	fireSP.setTexture(fireTex);
	if (!blackTex.loadFromFile("recources/black.png"))
	{
		std::cout << "black texture load failed";
	}
	blackSP.setTexture(blackTex);
	if (!blackCompleteTex.loadFromFile("recources/blackcomplete.png"))
	{
		std::cout << "black texture load failed";
	}
	blackCompleteSP.setTexture(blackCompleteTex);

	if (!introFont.loadFromFile("recources/m5x7.ttf"))
	{
		std::cout << "font load failed";
	}

	//set bed properties
	bedSP.setPosition(sf::Vector2f(570, 208));
	bedSP.setScale(3,3);

	//set fire properties
	fireSP.setPosition(sf::Vector2f(636, 204));
	fireSP.setScale((float)1.8, (float)1.8);
	fireSP.setTextureRect(sf::IntRect(0,0,13,14));

	//black properties
	blackSP.setPosition(sf::Vector2f(0, 0));
	blackSP.setColor(sf::Color(255, 255, 255, 200));

	//black complete properties
	blackCompleteSP.setPosition(sf::Vector2f(0, 0));
	blackCompleteSP.setColor(sf::Color(255, 255, 255, 40));

	//text properties
	introText.setFont(introFont);
	introText.setString("A traveler, discovering new lands.\nOn their heroic journey they have overcome many threats.\nWhen he wakes up from his slumber.\nA new threat arises\nOne that none have ever seen\n\nTHE RISING SNOWMEN HAVE ARRIVED\n\nPress SPACE or ENTER to continue");
	introText.setCharacterSize(35);
	introText.setFillColor(sf::Color::White);
	introText.setPosition(sf::Vector2f(50,300));
}

//loop during the intro
void Intro::loop() {

	//update timers
	animationElapsed = animationClock.getElapsedTime();
	animationSec = animationElapsed.asSeconds();

	//animation of fire
	if (animationSec < 0.25) {
		fireSP.setTextureRect(sf::IntRect(0, 0, 13, 14));
	}
	if (animationSec > 0.25) {
		fireSP.setTextureRect(sf::IntRect(14, 0, 13, 14));
	}
	if (animationSec > 0.50) {
		fireSP.setTextureRect(sf::IntRect(28, 0, 13, 14));

	}
	if (animationSec > 0.75) {
		fireSP.setTextureRect(sf::IntRect(42, 0, 13, 14));
	}
	if (animationSec > 1) {

		animationClock.restart();
	}

	//for skipping the intro
	float timerSec = timerClock.getElapsedTime().asSeconds();
	if (timerSec > 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
			stillIntro = false;
		}
	}
}

//draw during the intro
void Intro::draw(sf::RenderWindow& window) {

	window.draw(bedSP);
	window.draw(fireSP);
	window.draw(blackSP);
	window.draw(blackCompleteSP);
	window.draw(introText);
}

//draw for during main loop
void Intro::mainDraw(sf::RenderWindow &window) {

	//only draw the bed sprite 
	window.draw(bedSP);
}