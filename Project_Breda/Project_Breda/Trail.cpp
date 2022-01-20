#include "Trail.h"

Trail::Trail() {
    if (!trailTex.loadFromFile("trail.png"))
    {
        // error...
    }
    for (int i = 0; i < 50; i++) {
        trailSP[i].setTexture(trailTex);
        spawn[i] = false;
    }
    prevPos = sf::Vector2f(300, 300);
}

void Trail::loop(sf::Vector2f playerPos, sf::RenderWindow &window) {

    sf::Vector2f distCalc = playerPos - prevPos;
    distance = abs(sqrt(pow(distCalc.x, 2) + pow(distCalc.y, 2)));
    if (distance > 15) {
        if (b <= 49) {
            b++;
            appear(playerPos, b);
            prevPos = playerPos;
        }
        else {
            b = 1;
            appear(playerPos, b);
            prevPos = playerPos;
            std::cout << "test";
        }
        
    }
    
    //despawn on clock
    for (int i = 0; i < 50; i++) {
        trailElapsed[i] = trailClock[i].getElapsedTime();
        trailSec[i] = trailElapsed[i].asSeconds();
        if (trailSec[i] > 4) {
            spawn[i] = false;
        }
        else {
            spawn[i] = true;
        }
    }

    //draw needed
    for (int i = 0; i < 50; i++) {
        if (spawn[i]) {
            window.draw(trailSP[i]);
        }
    }
}

void Trail::appear(sf::Vector2f playerPos, int i) {
    trailClock[i].restart();
    trailSP[i].setPosition(playerPos);
}

void Trail::dissapear() {

}