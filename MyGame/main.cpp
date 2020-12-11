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
#include "MainMenu.h"
#include "Ladders.h"

int main()
{
    // Variables
    sf::Clock clockdt;
    sf::Clock clock;
    sf::Clock clockCollideEnemy;
    sf::Clock clockmana;

    float dt = 0.0f;
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 600), "MY GAME");
    window.setFramerateLimit(60);

    class MainMenu mainmenu(window.getSize().x, window.getSize().y);
    int State = -1;

    sf::View view1;
    view1.setSize(window.getSize().x, window.getSize().y);
    view1.setCenter(window.getSize().x / 2, window.getSize().y / 2);

    sf::Texture textureEnemy;
    if (!textureEnemy.loadFromFile("Resources/enemySpriteSheet.png")) EXIT_FAILURE;

    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("Resources/Sprite1.png")) EXIT_FAILURE;

    sf::Font font;
    if (!font.loadFromFile("Resources/font.otf")) EXIT_FAILURE;

    sf::Texture textureCoin;
    if (!textureCoin.loadFromFile("Resources/coinSprite.png")) EXIT_FAILURE;

    sf::Texture textureRasengan;
    if (!textureRasengan.loadFromFile("Resources/rasengan.png")) EXIT_FAILURE;

    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("Resources/backGroundmap1.png")) EXIT_FAILURE;

    sf::Texture platform1;
    if (!platform1.loadFromFile("Resources/Platforms/1.png")) EXIT_FAILURE;

    sf::Texture platform2;
    if (!platform2.loadFromFile("Resources/Platforms/2.png")) EXIT_FAILURE;

    sf::Texture platform3;
    if (!platform3.loadFromFile("Resources/Platforms/3.png")) EXIT_FAILURE;

    sf::Texture platform4;
    if (!platform4.loadFromFile("Resources/Platforms/4.png")) EXIT_FAILURE;

    sf::Texture platform5;
    if (!platform5.loadFromFile("Resources/Platforms/5.png")) EXIT_FAILURE;

    sf::Texture platform6;
    if (!platform6.loadFromFile("Resources/Platforms/6.png")) EXIT_FAILURE;

    sf::Texture platform7;
    if (!platform7.loadFromFile("Resources/Platforms/7.png")) EXIT_FAILURE;

    sf::Texture platform8;
    if (!platform8.loadFromFile("Resources/Platforms/8.png")) EXIT_FAILURE;

    sf::Texture platform9;
    if (!platform9.loadFromFile("Resources/Platforms/9.png")) EXIT_FAILURE;

    sf::Texture platform10;
    if (!platform10.loadFromFile("Resources/Platforms/10.png")) EXIT_FAILURE;

    sf::Texture platform11;
    if (!platform11.loadFromFile("Resources/Platforms/11.png")) EXIT_FAILURE;

    sf::Texture platform12;
    if (!platform12.loadFromFile("Resources/Platforms/12.png")) EXIT_FAILURE;

    sf::Texture platform13;
    if (!platform13.loadFromFile("Resources/Platforms/13.png")) EXIT_FAILURE;

    sf::Texture platform14;
    if (!platform14.loadFromFile("Resources/Platforms/14.png")) EXIT_FAILURE;

    sf::Texture platform15;
    if (!platform15.loadFromFile("Resources/Platforms/15.png")) EXIT_FAILURE;

    sf::Texture platform16;
    if (!platform16.loadFromFile("Resources/Platforms/16.png")) EXIT_FAILURE;

    sf::Texture platform17;
    if (!platform17.loadFromFile("Resources/Platforms/17.png")) EXIT_FAILURE;

    sf::Texture platform18;
    if (!platform18.loadFromFile("Resources/Platforms/18.png")) EXIT_FAILURE;

    sf::Texture platform19;
    if (!platform19.loadFromFile("Resources/Platforms/19.png")) EXIT_FAILURE;

    sf::Texture platform20;
    if (!platform20.loadFromFile("Resources/Platforms/20.png")) EXIT_FAILURE;

    sf::RectangleShape backGround;
    backGround.setTexture(&textureBackground);
    backGround.setSize(sf::Vector2f(textureBackground.getSize().x * 2.5, textureBackground.getSize().y * 600 / 223));

    vector<Platform> platforms;
    platforms.push_back(Platform(&platform1, sf::Vector2f(0.0f, 495.0f)));
    platforms.push_back(Platform(&platform2, sf::Vector2f(640.0f, 450.0f)));
    platforms.push_back(Platform(&platform3, sf::Vector2f(998.0f, 450.0f)));
    platforms.push_back(Platform(&platform4, sf::Vector2f(1200.0f, 410.0f)));
    platforms.push_back(Platform(&platform5, sf::Vector2f(2957.0f, 495.0f)));
    platforms.push_back(Platform(&platform6, sf::Vector2f(3012.5f, 0.0f)));
    platforms.push_back(Platform(&platform7, sf::Vector2f(2920.0f, 839.46f)));
    platforms.push_back(Platform(&platform8, sf::Vector2f(3120.0f, 750.0f)));
    platforms.push_back(Platform(&platform9, sf::Vector2f(2720.0f, 1140.8f)));
    platforms.push_back(Platform(&platform10, sf::Vector2f(2960.0f, 1097.75f)));
    platforms.push_back(Platform(&platform10, sf::Vector2f(2800.0f, 1097.75f)));
    platforms.push_back(Platform(&platform10, sf::Vector2f(2760.0f, 922.87f)));
    platforms.push_back(Platform(&platform11, sf::Vector2f(2560.0f, 914.79f)));
    platforms.push_back(Platform(&platform12, sf::Vector2f(2640.0f, 1528.25f)));
    platforms.push_back(Platform(&platform13, sf::Vector2f(2715.0f, 1700.44f)));
    platforms.push_back(Platform(&platform14, sf::Vector2f(2760.0f, 1786.54f)));
    platforms.push_back(Platform(&platform15, sf::Vector2f(2960.0f, 1700.44f)));
    platforms.push_back(Platform(&platform16, sf::Vector2f(3600.0f, 1614.34f)));
    platforms.push_back(Platform(&platform17, sf::Vector2f(3920.0f, 1700.0f)));
    platforms.push_back(Platform(&platform18, sf::Vector2f(4000.0f, 1614.0f)));
    platforms.push_back(Platform(&platform19, sf::Vector2f(4320.0f, 1528.25f)));
    platforms.push_back(Platform(&platform20, sf::Vector2f(5020.0f, 949.77f)));

    // Ladders
    vector<Ladders> ladders;
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 387.44f), sf::Vector2f(4960, 1140.80)));

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

    sf::RectangleShape playerHp;
    playerHp.setFillColor(sf::Color::Red);
    playerHp.setPosition(20, 30);

    sf::RectangleShape playerHpSlot;
    playerHpSlot.setSize(sf::Vector2f(Player1.hp * 2, 20));
    playerHpSlot.setPosition(20, 30);
    playerHpSlot.setOutlineColor(sf::Color::Black);
    playerHpSlot.setOutlineThickness(1);

    sf::RectangleShape playerMana;
    playerMana.setFillColor(sf::Color::Cyan);
    playerMana.setPosition(250, 30);

    sf::RectangleShape playerManaSlot;
    playerManaSlot.setSize(sf::Vector2f(200, 20));
    playerManaSlot.setPosition(250, 30);
    playerManaSlot.setOutlineColor(sf::Color::Black);
    playerManaSlot.setOutlineThickness(1);

    //Main Menu State
    while (window.isOpen() && State == -1)
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up or event.key.code == sf::Keyboard::W)
                {
                    mainmenu.moveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down or event.key.code == sf::Keyboard::S)
                {
                    mainmenu.moveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return)
                {
                    State = mainmenu.mainMenuPressed();
                    break;
                }
            }
        }
        window.clear();
        printf("%d", State);
        mainmenu.Draw(window);
        window.display();
    }

    // Start the game loop
    if (State == 0)
    {
        while (window.isOpen())
        {
            dt = clockdt.restart().asSeconds();
            // Process events
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Close window : exit
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();

            if (Player1.hp <= 0)
            {
                //State = 3;
                //window.close();
                break;
            }
            // Clock
            sf::Time elapsed = clock.getElapsedTime();

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

            if (clockCollideEnemy.getElapsedTime().asSeconds() >= 0.5)
            {
                clockCollideEnemy.restart();

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
                        textDisplay1.text.setPosition(enemyArray[counter2].sprite.getPosition().x + enemyArray[counter2].sprite.getGlobalBounds().width / 2,
                            enemyArray[counter2].sprite.getPosition().y - enemyArray[counter2].sprite.getGlobalBounds().height / 2.0f);
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

            if (clockmana.getElapsedTime().asSeconds() >= 1)
            {
                clockmana.restart();
                if (Player1.mana < 100) Player1.mana += 5;
            }

            // Fires Missle
            if (elapsed.asSeconds() >= 0.1)
            {
                clock.restart();
                if (Player1.mana >= 10)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
                    {
                        Player1.mana -= 10;
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
            }


            // Update Shoot
            counter = 0;
            for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
            {
                shootArray[counter].update(); // Update Shoot
                counter++;
            }

            //Update Player
            Player1.update(dt);

            // Update UI
            //if (Player1.GetPosition().x >= window.getSize().x / 2)
            //{
                view1.setCenter(Player1.GetPosition().x, Player1.GetPosition().y - window.getSize().y / 6);
                coinsCount.setPosition(view1.getCenter().x + window.getSize().x / 2 - 200, 20);
                playerHp.setPosition(view1.getCenter().x - window.getSize().x / 2 + 20, 30);
                playerHpSlot.setPosition(view1.getCenter().x - window.getSize().x / 2 + 20, 30);
                playerMana.setPosition(view1.getCenter().x - window.getSize().x / 2 + 250, 30);
                playerManaSlot.setPosition(view1.getCenter().x - window.getSize().x / 2 + 250, 30);
            //}
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

            for (Ladders& ladder : ladders)
            {
                if (Player1.sprite.getGlobalBounds().intersects(ladder.rect.getGlobalBounds()))
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        Player1.velocity.y = 0;
                        Player1.sprite.move(0, -Player1.movementSpeed);
                    }
                }
            }

            //Update Enemy
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                enemyArray[counter].update(dt);
                counter++;
            }

            // Update UI
            playerHp.setSize(sf::Vector2f(Player1.hp * 2, 20));
            playerMana.setSize(sf::Vector2f(Player1.mana * 2, 20));
            coinsCount.setString("Coins : " + to_string(Player1.coins));

            ////////////////////////////////////////////////////////********* DRAW EVERYTHING *******/////////////////////////////////////////////////////////////////////

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

            // Draw UI
            /*window.draw(coinsCount);
            window.draw(playerHpSlot);
            window.draw(playerHp);
            window.draw(playerManaSlot);
            window.draw(playerMana);*/

            // Draw Text
            counter = 0;
            for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
            {
                textDisplayArray[counter].update();
                window.draw(textDisplayArray[counter].text);

                counter++;
            }
            cout << "Player.y = " << Player1.GetPosition().y << endl;
            cout << "x = " << window.mapPixelToCoords(sf::Mouse::getPosition(window)).x << " y = " << window.mapPixelToCoords(sf::Mouse::getPosition(window)).y << endl;
            window.display();
        }
    }

    // End Game
    if (State == 3)
    {
        main();
    }
    return 0;
}
