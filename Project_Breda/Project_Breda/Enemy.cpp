#include "Enemy.h"

//upon initiate, load textures and sprites
Enemy::Enemy() {

    //load textures
    if (!enemy.loadFromFile("enemy.png"))
    {
        std::cout << "enemy texture load failed";
    }

    //initiate the first wave
    nextWave();
}

//function for when the game needs to be restarted
void Enemy::start() {

    //reset the wave
    wave = 0;
    float waveSec = 0;
    int enemyCount = 0;
    int wave = 0;
    nextWave();
}

//main loop function
void Enemy::loop(float dt, sf::Vector2f playerPos, sf::FloatRect playerRect, Player &Player, sf::FloatRect weaponRect, Weapon &Weapon) {

    //update wave timers
    waveElapsed = waveClock.getElapsedTime();
    waveSec = waveElapsed.asSeconds();

    //update damage giving timers
    giveDamElapsed = giveDamClock.getElapsedTime();
    giveDamSec = giveDamElapsed.asSeconds();

    //for the need amount of enemies
    for (int i = 0; i < (wave * 3); i++) {

        //update immunity frame timers
        takeDElapsed[i] = takeDClock[i].getElapsedTime();
        takeDSec[i] = takeDElapsed[i].asSeconds();

        //if the enemy is alive
        if (EHealth[i] > 1) {

            //check if intersecting with player or weapon
            sf::FloatRect EboundingBox = enemySP[i].getGlobalBounds();
            if (EboundingBox.intersects(playerRect)) {

                //if the player is attacking make him immune due to sprite being bigger
                if (!Player.isAttacking) {

                    //give the player some time to flee from the enemy
                    if (firstGive) {

                        giveDamClock.restart();
                        firstGive = false;
                    }
                    //time is over ;)
                    if (giveDamSec > 0.5) {

                        Player.takeDamage(damage);
                        firstGive = true;
                    }
                        
                }
            }
            //check if the enemy is being attacked
            if (takeDSec[i] > 0.5) {

                if (EboundingBox.intersects(weaponRect)) {
                    
                    takeDamage(i, Weapon.Wdam);
                }
            }

            //move the enemy towards the player
            int speed = 15;
            sf::Vector2f direction = sf::getNormalized(playerPos - enemySP[i].getPosition());
            enemySP[i].move(sf::Vector2f((speed * dt * direction.x), (speed * dt * direction.y)));   
        }

        //if the enemy is dead set to dead texture
        if (EHealth[i] <= 0) {

            enemySP[i].setTextureRect(sf::IntRect(0, 114, 46, 29));
        }
    }

    //check if all the enemy's are dead. if yes, start the new wave
    if (enemyCount <= 0) {

        nextWave();
    }
}

//take damage function
void Enemy::takeDamage(int i, int WeaponDam) {

   //take the damage
   EHealth[i] = EHealth[i] - WeaponDam;

   //reset immunity frames
   takeDClock[i].restart();

   //if the enemy dies by the attack
   if (EHealth[i] < 1) {
       enemyCount--;
       waveClock.restart();
   }
}

//initiate the next wave
void Enemy::nextWave() {

    if (waveSec >= 1) {

        //increase the wave
        wave++;

        //calculate the amount of enemy's to spawn
        int DE = wave * 3;

        //initiate the wave
        initialize(DE);
    }
}

//initiate a wave (called by nextWave)
void Enemy::initialize(int desiredEnemy) {

    //repeat for the needed enemies
    for (int i = 0; i < desiredEnemy; i++) {

        //generate random numbers for spawns
        if (firstRandom)
        {
            srand(time(NULL)); //seeding for the first time only
            firstRandom = false;
        }
        float randx = 2 + rand() % ((100 + 1) - 2);
        float randy = 100 + rand() % ((600 + 1) - 100);

        //set textures
        for (int i = 0; i < desiredEnemy; i++) {
            enemySP[i].setTexture(enemy);
        }

        //random number for texture
        float randTex = 48 *(1 + rand() % ((6 + 1) - 1));
        enemySP[i].setTextureRect(sf::IntRect(randTex, 53, 45, 51));

        //set position
        enemySP[i].setPosition(sf::Vector2f(randx, randy));

        //set enemy active
        EHealth[i] = 100;
        enemyCount++;
    }
}

//draw function
void Enemy::draw(sf::RenderWindow &window) {

    for (int i = 0; i < (wave * 3); i++) {

            window.draw(enemySP[i]);
    }
}
