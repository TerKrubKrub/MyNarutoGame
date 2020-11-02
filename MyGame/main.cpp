#include <iostream>
using namespace std;
#include "SFML/Graphics.hpp"
#include "player.h"
#include "entity.h"
#include "shoot.h"
#include "enemy.h"
#include "random.h"
int main()
{
    // Variables
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;


    sf::RenderWindow window(sf::VideoMode(1000, 800), "MY GAME");
    sf::Texture textureCat;
    if (!textureCat.loadFromFile("cat.jpg"))
    {
        cout << "Failed" << endl;
    }
    sf::Sprite spriteCat(textureCat);
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("Sprite.png")) return 0;
    sf::Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    spritePlayer.setTextureRect(sf::IntRect(0, 0, 32, 32));

    sf::Texture textureEnemy;
    if (!textureEnemy.loadFromFile("enemySpriteSheet.png")) return 0;

    // Set the Icon
    sf::Image icon;
    icon.loadFromFile("cat.jpg");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Font font;
    if (!font.loadFromFile("font.otf"))
    {
        cout << "Failed" << endl;
    }

    sf::Text text("Hello World", font, 50);
    text.setPosition(500, 500);

    // Class Object
    class player Player1;
    Player1.sprite.setTexture(texturePlayer);

    // Shoot Vector
    vector<shoot>::const_iterator iter;
    vector<shoot> shootArray;

    // Shoot Object
    class shoot shoot1;

    // Enemy Vector
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray;

    // Enemy Object
    class enemy enemy1;
    enemy1.sprite.setTexture(textureEnemy);

    enemy1.rect.setPosition(600, 200);
    enemyArray.push_back(enemy1);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
            enemyArray.push_back(enemy1);
        }

        // Fires Missle
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            cout << "Spacebar Pressed" << endl;
            shoot1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - shoot1.rect.getSize().x/2,
                Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - shoot1.rect.getSize().y/2);
            shoot1.direction = Player1.direction;
            shootArray.push_back(shoot1);
        }

        //Draw Shoot
        counter = 0;
        for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
        {
            shootArray[counter].update(); // Update Shoot
            window.draw(shootArray[counter].rect);
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

        // Draw Sprite Cat
        //window.draw(spriteCat);

        // Draw Sprite Player
        //.draw(spritePlayer);

        // Draw Player
        window.draw(Player1.sprite);
        // Draw Text
        //window.draw(text);

        window.display();
    }
    return 0;
}