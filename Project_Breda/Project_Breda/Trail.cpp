#include "Trail.h"

//initiate trails
Trail::Trail() {
    if (!trailTex.loadFromFile("trail.png"))
    {
        // error...
    }
    for (int i = 0; i < 50; i++) {
        trailSP[i].setTexture(trailTex);
        spawn[i] = false;
    }

    //set default position
    prevPos = sf::Vector2f(300, 300);
}

//main loop
void Trail::loop(sf::Vector2f playerPos) {

    //calculate the distance
    sf::Vector2f distCalc = playerPos - prevPos;
    distance = abs(sqrt(pow(distCalc.x, 2) + pow(distCalc.y, 2)));

    //if the distance is over the limit, activate the trail sprite
    if (distance > 15) {
        if (b <= 49) {
            b++;
            appear(playerPos, b);
            prevPos = playerPos;
        }
        //if the amount of trails is over the array limit start by sprite 1 again
        else {
            b = 1;
            appear(playerPos, b);
            prevPos = playerPos;
        }
        
    }
    
    //despawn on clock
    for (int i = 0; i < 50; i++) {

        //update timers
        trailElapsed[i] = trailClock[i].getElapsedTime();
        trailSec[i] = trailElapsed[i].asSeconds();

        //if the timer is too high deactive the trail sprite
        if (trailSec[i] > 4) {
            spawn[i] = false;
        }
        //set it to active
        else {
            spawn[i] = true;
        }
    }
}

//set the trail active
void Trail::appear(sf::Vector2f playerPos, int i) {

    //start the clock on dissapearing
    trailClock[i].restart();

    //set the position to stay
    trailSP[i].setPosition(playerPos);
}

//draw function
void Trail::draw(sf::RenderWindow &window) {

    //check if draw needed
    for (int i = 0; i < 50; i++) {
        if (spawn[i]) {
            window.draw(trailSP[i]);
        }
    }
}