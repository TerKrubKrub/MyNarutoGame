#include <iostream>
using namespace std;
#include "SFML/Graphics.hpp"
#include "player.h"
#include "entity.h"
#include "shoot.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickup.h"
#include "Platform.h"
#include "Collider.h"

int main()
{
    // Variables
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "MY GAME");
    window.setFramerateLimit(60);

    sf::Texture textureEnemy;
    if(!textureEnemy.loadFromFile("Resources/enemySpriteSheet.png")); EXIT_FAILURE;

    sf::Texture texturePlayer;
    if(!texturePlayer.loadFromFile("Resources/Sprite.png")); EXIT_FAILURE;

    sf::Font font;
    if(!font.loadFromFile("Resources/font.otf")); EXIT_FAILURE;

    sf::Texture textureCoin;
    if(!textureCoin.loadFromFile("Resources/coinSprite.png")); EXIT_FAILURE;

    sf::Texture textureRasengan;
    if(!textureRasengan.loadFromFile("Resources/rasengan.png")) EXIT_FAILURE;

    Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));
    Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

    // Class Object
    class player Player1;
    Player1.sprite.setTexture(texturePlayer);

    // Shoot Vector Array
    vector<shoot>::const_iterator iter;
    vector<shoot> shootArray;

    // Shoot Object
    class shoot shoot1;
    shoot1.sprite.setTexture(textureRasengan);

    // Enemy Vector Array
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray;

    // Enemy Object
    class enemy enemy1;
    enemy1.sprite.setTexture(textureEnemy);

    enemy1.rect.setPosition(600, 200);
    enemyArray.push_back(enemy1);

    // Text Vector Array
    vector<textDisplay>::const_iterator iter8;
    vector<textDisplay> textDisplayArray;

    // Text Display Object
    class textDisplay textDisplay1;
    textDisplay1.text.setFont(font);

    // Text Coins
    sf::Text coinsCount("Coins : ", font, 25);
    coinsCount.setFillColor(sf::Color::White);
    coinsCount.setPosition(800, 30);

    // Coin Vector Array
    vector<pickup>::const_iterator iter11;
    vector<pickup> pickupArray;

    // Pickup Object
    class pickup pickup1;
    pickup1.sprite.setTexture(textureCoin);
    pickupArray.push_back(pickup1);
    


    //Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Clock
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();


        // Player collides Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
            {
                if (pickupArray[counter].isCoin == true)
                {
                    Player1.coins += pickupArray[counter].coinValue;
                }

                pickupArray[counter].destroy = true;
            }

            counter++;
        }


        if (elapsed2.asSeconds() >= 0.5)
        {
            clock2.restart();

            // Enemy Collides with Player
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (Player1.sprite.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
                {
                    // Text Display
                    textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                    textDisplay1.text.setPosition(Player1.sprite.getPosition().x + Player1.rect.getSize().x / 2,
                        Player1.sprite.getPosition().y - Player1.rect.getSize().y / 2);
                    textDisplayArray.push_back(textDisplay1);

                    Player1.hp -= enemyArray[counter].attackDamage;
                    cout << Player1.hp << endl;
                }

                counter++;
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
            enemyArray.push_back(enemy1);
        }

        // Projectile Collides with Enemy
        counter = 0;
        for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
        {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (shootArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    //cout << "Collision" << endl;
                    shootArray[counter].destroy = true;

                    // Text Display
                    textDisplay1.text.setString(to_string(shootArray[counter].attackDamage));
                    textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x/2, 
                        enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y/2);
                    textDisplayArray.push_back(textDisplay1);

                    enemyArray[counter2].hp -= shootArray[counter].attackDamage;
                    if (enemyArray[counter2].hp <= 0)
                    {
                        enemyArray[counter2].alive = false;
                    }
                }
                counter2++;
            }
            counter++;
        }

        // Draw Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            pickupArray[counter].update(); // Update Shoot
            //window.draw(pickupArray[counter].rect);
            window.draw(pickupArray[counter].sprite);
            counter++;
        }

        // Delete Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (pickupArray[counter].destroy == true)
            {
                pickupArray.erase(iter11);
                break;
            }
            counter++;
        }

        // Delete Dead Enemy
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if (enemyArray[counter].alive == false)
            {
                cout << "Enemy has been dead" << endl;

                if (generateRandom(2) == 1)
                {
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }

                enemyArray.erase(iter4);
                break;
            }
            counter++;
        }

        // Delete Shoot
        counter = 0;
        for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
        {
            if (shootArray[counter].destroy == true)
            {
                //cout << "worked" << endl;
                shootArray.erase(iter);
                break;
            }
            counter++;
        }

        // Delete Text Display
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            if (textDisplayArray[counter].destroy == true)
            {
                textDisplayArray.erase(iter8);
                break;
            }
            counter++;
        }

        // Fires Missle
        if (elapsed.asSeconds() >= 0.1)
        {
            clock.restart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                cout << "Left Clicked" << endl;
                shoot1.rect.setPosition(Player1.sprite.getPosition().x + 16 - shoot1.rect.getSize().x/2,
                    Player1.sprite.getPosition().y + 16 - shoot1.rect.getSize().y/2);
                shoot1.direction = Player1.direction;
                shootArray.push_back(shoot1);

            }
        }

        //Draw Shoot
        counter = 0;
        for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
        {
            shootArray[counter].update(); // Update Shoot
            //window.draw(shootArray[counter].rect);
            window.draw(shootArray[counter].sprite);
            counter++;
        }

        //Draw Enemy
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            enemyArray[counter].update(); // Update Shoot
            enemyArray[counter].updateMovement();
            //window.draw(enemyArray[counter].rect);
            window.draw(enemyArray[counter].sprite);
            counter++;
        }

        //Update Player
        Player1.update();
        Player1.updateMovement();

        // Draw Player
        window.draw(Player1.sprite);

        // Draw Coins
        coinsCount.setString("Coins : " + to_string(Player1.coins));
        window.draw(coinsCount);

        // Draw Text
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            textDisplayArray[counter].update();
            window.draw(textDisplayArray[counter].text);

            counter++;
        }

        platform1.GetCollider().CheckCollision(Player1.GetCollider(), 0.0f);
        platform2.GetCollider().CheckCollision(Player1.GetCollider(), 1.0f);

        platform1.Draw(window);
        platform2.Draw(window);
        window.display();
    }
    return 0;
}