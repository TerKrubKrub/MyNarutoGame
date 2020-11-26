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

    sf::RenderWindow window(sf::VideoMode(1000, 600), "MY GAME");
    window.setFramerateLimit(60);

    sf::View view1;
    view1.setSize(window.getSize().x, window.getSize().y);
    view1.setCenter(window.getSize().x / 2, window.getSize().y / 2);

    sf::Texture textureEnemy;
    if(!textureEnemy.loadFromFile("Resources/enemySpriteSheet.png")) EXIT_FAILURE;

    sf::Texture texturePlayer;
    if(!texturePlayer.loadFromFile("Resources/Sprite1.png")) EXIT_FAILURE;

    sf::Font font;
    if(!font.loadFromFile("Resources/font.otf")) EXIT_FAILURE;

    sf::Texture textureCoin;
    if(!textureCoin.loadFromFile("Resources/coinSprite.png")) EXIT_FAILURE;

    sf::Texture textureRasengan;
    if(!textureRasengan.loadFromFile("Resources/rasengan.png")) EXIT_FAILURE;

    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("Resources/background.png")) EXIT_FAILURE;

    sf::Texture platform1;
    if (!platform1.loadFromFile("Resources/platform1.png")) EXIT_FAILURE;

    sf::RectangleShape backGround;
    backGround.setTexture(&textureBackground);
    backGround.setSize(sf::Vector2f(textureBackground.getSize().x * 1000 / 560, window.getSize().y));

    vector<Platform> platforms;
    platforms.push_back(Platform(&platform1, sf::Vector2f(0.0f, 565.0f)));

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

    enemy1.sprite.setPosition(600, 260);
    enemyArray.push_back(enemy1);
    enemy1.sprite.setPosition(500, 370);
    enemyArray.push_back(enemy1);

    // Text Vector Array
    vector<textDisplay>::const_iterator iter8;
    vector<textDisplay> textDisplayArray;

    // Text Display Object
    class textDisplay textDisplay1;
    textDisplay1.text.setFont(font);

    // Text Coins
    sf::Text coinsCount("Coins : ", font, 25);
    coinsCount.setFillColor(sf::Color::Blue);
    coinsCount.setPosition(view1.getCenter().x + window.getSize().x / 2 - 200, 20);

    // Coin Vector Array
    vector<pickup>::const_iterator iter11;
    vector<pickup> pickupArray;

    // Pickup Object
    class pickup pickup1;
    pickup1.sprite.setTexture(textureCoin);
    //pickupArray.push_back(pickup1);
    
    float dt = 0.0f;

    //Start the game loop
    while (window.isOpen())
    {
        dt = clock3.restart().asSeconds();
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

        sf::Vector2f direction1;


        // Player collides Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (Player1.sprite.getGlobalBounds().intersects(pickupArray[counter].sprite.getGlobalBounds()))
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
                if (Player1.sprite.getGlobalBounds().intersects(enemyArray[counter].sprite.getGlobalBounds()))
                {
                    // Text Display
                    textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                    textDisplay1.text.setPosition(Player1.sprite.getPosition().x + Player1.sprite.getGlobalBounds().width / 2,
                        Player1.sprite.getPosition().y - Player1.sprite.getGlobalBounds().height / 2);
                    textDisplayArray.push_back(textDisplay1);

                    Player1.hp -= enemyArray[counter].attackDamage;
                    cout << Player1.hp << endl;
                }

                counter++;
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            enemy1.sprite.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
            enemyArray.push_back(enemy1);
        }

        // Projectile Collides with Enemy
        counter = 0;
        for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
        {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (shootArray[counter].sprite.getGlobalBounds().intersects(enemyArray[counter2].sprite.getGlobalBounds()))
                {
                    //cout << "Collision" << endl;
                    shootArray[counter].destroy = true;

                    // Text Display
                    textDisplay1.text.setString(to_string(shootArray[counter].attackDamage));
                    textDisplay1.text.setPosition(enemyArray[counter2].sprite.getPosition().x + enemyArray[counter2].sprite.getGlobalBounds().width/2,
                        enemyArray[counter2].sprite.getPosition().y - enemyArray[counter2].sprite.getGlobalBounds().height/2.0f);
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
                    pickup1.sprite.setPosition(enemyArray[counter].sprite.getPosition());
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
            {
                if (Player1.direction == 3)
                {
                    shoot1.sprite.setPosition(Player1.sprite.getPosition().x,
                        Player1.sprite.getPosition().y + Player1.sprite.getGlobalBounds().height / 2);
                    shoot1.direction = Player1.direction;
                    shootArray.push_back(shoot1);
                }
                if (Player1.direction == 4)
                {
                    shoot1.sprite.setPosition(Player1.sprite.getPosition().x + Player1.sprite.getGlobalBounds().width,
                        Player1.sprite.getPosition().y + Player1.sprite.getGlobalBounds().height / 2);
                    shoot1.direction = Player1.direction;
                    shootArray.push_back(shoot1);
                }
            }
        }


        //Draw Shoot
        counter = 0;
        for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
        {
            shootArray[counter].update(); // Update Shoot
            counter++;
        }

        if (Player1.GetPosition().x >= window.getSize().x/2)
        {
            view1.setCenter(Player1.GetPosition().x, window.getSize().y/2);
            coinsCount.setPosition(view1.getCenter().x + window.getSize().x / 2 - 200, 20);
        }
        window.setView(view1);

        for (Platform& platform : platforms)
        {
            if (platform.GetCollider().CheckCollision(Player1.GetCollider(), direction1, 1.0f))
                Player1.OnCollision(direction1);
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (platform.GetCollider().CheckCollision(enemyArray[counter].GetCollider(), direction1, 1.0f))
                    enemyArray[counter].OnCollision(direction1);
                counter++;
            }
        }

        //Update Enemy
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            enemyArray[counter].update(dt); // Update Enemy
            //window.draw(enemyArray[counter].rect);
            //window.draw(enemyArray[counter].sprite);
            counter++;
        }
      

        //Update Player
        Player1.update(dt);

        for (Platform& platform : platforms)
            platform.Draw(window);
        window.draw(backGround);
        // Draw Player
        window.draw(Player1.sprite);

        // Draw Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            window.draw(pickupArray[counter].sprite);
            counter++;
        }

        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            window.draw(enemyArray[counter].sprite);
            counter++;
        }

        counter = 0;
        for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
        {
            window.draw(shootArray[counter].sprite);
            counter++;
        }

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
        window.display();
    }
    return 0;
}