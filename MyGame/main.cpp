#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
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
#include "enemy2.h"

int main()
{
    srand(time(NULL));
    // Variables
    sf::Clock clockdt;
    sf::Clock clock;
    sf::Clock clockCollideEnemy;
    sf::Clock clockmana;
    sf::Clock clockEnemy;
    sf::Clock itemFire;
    sf::Clock itemFirerate;

    float dt = 0.0f;
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 600), "JIRAKAN KOOLLASING 63010136");
    window.setFramerateLimit(60);

    sf::View view1;
    view1.setSize(window.getSize().x, window.getSize().y);
    view1.setCenter(window.getSize().x / 2, window.getSize().y / 2);

    class MainMenu mainmenu(window.getSize().x, window.getSize().y, view1);
    int State = -1;

    sf::String input;
    sf::Text playerName;
    sf::String name[5];
    sf::Text PlayerName[5];
    sf::Text PlayerScore[5];

    sf::Texture textureEnemy;
    if (!textureEnemy.loadFromFile("Resources/enemySpriteSheet.png")) EXIT_FAILURE;

    sf::Texture textureEnemy2;
    if (!textureEnemy2.loadFromFile("Resources/enemySprite.png")) EXIT_FAILURE;

    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("Resources/Sprite1.png")) EXIT_FAILURE;

    sf::Font font;
    if (!font.loadFromFile("Resources/font.otf")) EXIT_FAILURE;

    sf::Texture textureMedkit;
    if (!textureMedkit.loadFromFile("Resources/medkit.png")) EXIT_FAILURE;

    sf::Texture textureRasengan;
    if (!textureRasengan.loadFromFile("Resources/rasengan.png")) EXIT_FAILURE;

    sf::Texture textureFireball;
    if (!textureFireball.loadFromFile("Resources/fireBall.png")) EXIT_FAILURE;

    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("Resources/backGroundmap1.png")) EXIT_FAILURE;

    sf::Texture texturePricker;
    if (!texturePricker.loadFromFile("Resources/pricker.png")) EXIT_FAILURE;

    sf::Texture texturePricker2;
    if (!texturePricker2.loadFromFile("Resources/pricker40.png")) EXIT_FAILURE;

    sf::Texture textureItems;
    if (!textureItems.loadFromFile("Resources/pickupItem.png")) EXIT_FAILURE;

    sf::Texture textureDoor;
    if (!textureDoor.loadFromFile("Resources/Door.png")) EXIT_FAILURE;

    sf::RectangleShape backGround;
    backGround.setTexture(&textureBackground);
    backGround.setSize(sf::Vector2f(textureBackground.getSize().x * 2.5, textureBackground.getSize().y * 600 / 223));

    sf::RectangleShape door1;
    door1.setSize(sf::Vector2f(80, 80));
    door1.setTexture(&textureDoor);
    door1.setTextureRect(sf::IntRect(0, 0, 160, 160));
    door1.setPosition(9700, 2998);

    sf::RectangleShape door2;
    door2.setSize(sf::Vector2f(80, 80));
    door2.setTexture(&textureDoor);
    door2.setTextureRect(sf::IntRect(0, 0, 160, 160));
    door2.setPosition(9860, 2998);

    sf::RectangleShape door3;
    door3.setSize(sf::Vector2f(80, 80));
    door3.setTexture(&textureDoor);
    door3.setTextureRect(sf::IntRect(0, 0, 160, 160));
    door3.setPosition(10020, 2998);

    sf::Music backgroundSound;
    if (!backgroundSound.openFromFile("Resources/Sounds/backgroundSound.wav")) EXIT_FAILURE;
    backgroundSound.setVolume(15.f);

    sf::SoundBuffer bufferShootRasengan;
    if (!bufferShootRasengan.loadFromFile("Resources/Sounds/Shoot.wav")) EXIT_FAILURE;

    sf::SoundBuffer bufferShootFireball;
    if (!bufferShootFireball.loadFromFile("Resources/Sounds/Fireball.wav")) EXIT_FAILURE;

    sf::Sound shootSound;
    shootSound.setBuffer(bufferShootRasengan);
    shootSound.setVolume(15.f);

    sf::Sound enemyshootSound;
    enemyshootSound.setBuffer(bufferShootRasengan);
    enemyshootSound.setVolume(15.f);

    sf::SoundBuffer bufferPickuphp;
    if (!bufferPickuphp.loadFromFile("Resources/Sounds/Pickuphp.wav")) EXIT_FAILURE;

    sf::Sound pickupSoundhp;
    pickupSoundhp.setBuffer(bufferPickuphp);
    pickupSoundhp.setVolume(15.f);

    sf::SoundBuffer bufferHit;
    if (!bufferHit.loadFromFile("Resources/Sounds/Hit.wav")) EXIT_FAILURE;

    sf::Sound hitSound;
    hitSound.setBuffer(bufferHit);
    hitSound.setVolume(10.f);

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

    sf::Texture platform21;
    if (!platform21.loadFromFile("Resources/Platforms/21.png")) EXIT_FAILURE;

    sf::Texture platform22;
    if (!platform22.loadFromFile("Resources/Platforms/22.png")) EXIT_FAILURE;

    sf::Texture platform23;
    if (!platform23.loadFromFile("Resources/Platforms/23.png")) EXIT_FAILURE;

    sf::Texture platform24;
    if (!platform24.loadFromFile("Resources/Platforms/24.png")) EXIT_FAILURE;

    sf::Texture platform25;
    if (!platform25.loadFromFile("Resources/Platforms/25.png")) EXIT_FAILURE;

    sf::Texture platform26;
    if (!platform26.loadFromFile("Resources/Platforms/26.png")) EXIT_FAILURE;

    sf::Texture platform27;
    if (!platform27.loadFromFile("Resources/Platforms/27.png")) EXIT_FAILURE;

    sf::Texture platform28;
    if (!platform28.loadFromFile("Resources/Platforms/28.png")) EXIT_FAILURE;

    sf::Texture platform29;
    if (!platform29.loadFromFile("Resources/Platforms/29.png")) EXIT_FAILURE;

    sf::Texture platform30;
    if (!platform30.loadFromFile("Resources/Platforms/30.png")) EXIT_FAILURE;

    sf::Texture platform31;
    if (!platform31.loadFromFile("Resources/Platforms/31.png")) EXIT_FAILURE;

    sf::Texture platform32;
    if (!platform32.loadFromFile("Resources/Platforms/32.png")) EXIT_FAILURE;

    sf::Texture platform33;
    if (!platform33.loadFromFile("Resources/Platforms/33.png")) EXIT_FAILURE;

    sf::Texture platform34;
    if (!platform34.loadFromFile("Resources/Platforms/34.png")) EXIT_FAILURE;

    sf::Texture platform35;
    if (!platform35.loadFromFile("Resources/Platforms/35.png")) EXIT_FAILURE;

    sf::Texture platform36;
    if (!platform36.loadFromFile("Resources/Platforms/36.png")) EXIT_FAILURE;

    sf::Texture platform37;
    if (!platform37.loadFromFile("Resources/Platforms/37.png")) EXIT_FAILURE;

    sf::Texture platform38;
    if (!platform38.loadFromFile("Resources/Platforms/38.png")) EXIT_FAILURE;

    sf::Texture platform39;
    if (!platform39.loadFromFile("Resources/Platforms/39.png")) EXIT_FAILURE;

    sf::Texture platform40;
    if (!platform40.loadFromFile("Resources/Platforms/40.png")) EXIT_FAILURE;

    sf::Texture platform41;
    if (!platform41.loadFromFile("Resources/Platforms/41.png")) EXIT_FAILURE;

    sf::Texture platform42;
    if (!platform42.loadFromFile("Resources/Platforms/42.png")) EXIT_FAILURE;

    sf::Texture platform43;
    if (!platform43.loadFromFile("Resources/Platforms/43.png")) EXIT_FAILURE;

    sf::Texture platform44;
    if (!platform44.loadFromFile("Resources/Platforms/44.png")) EXIT_FAILURE;

    sf::Texture platform45;
    if (!platform45.loadFromFile("Resources/Platforms/45.png")) EXIT_FAILURE;

    sf::Texture platform46;
    if (!platform46.loadFromFile("Resources/Platforms/46.png")) EXIT_FAILURE;

    sf::Texture platform47;
    if (!platform47.loadFromFile("Resources/Platforms/47.png")) EXIT_FAILURE;

    sf::Texture platform48;
    if (!platform48.loadFromFile("Resources/Platforms/48.png")) EXIT_FAILURE;

    sf::Texture platform49;
    if (!platform49.loadFromFile("Resources/Platforms/49.png")) EXIT_FAILURE;

    sf::Texture platform50;
    if (!platform50.loadFromFile("Resources/Platforms/50.png")) EXIT_FAILURE;

    sf::Texture platform51;
    if (!platform51.loadFromFile("Resources/Platforms/51.png")) EXIT_FAILURE;

    sf::Texture platform52;
    if (!platform52.loadFromFile("Resources/Platforms/52.png")) EXIT_FAILURE;

    sf::Texture platform53;
    if (!platform53.loadFromFile("Resources/Platforms/53.png")) EXIT_FAILURE;

    sf::Texture platform54;
    if (!platform54.loadFromFile("Resources/Platforms/54.png")) EXIT_FAILURE;

    sf::Texture platform55;
    if (!platform55.loadFromFile("Resources/Platforms/55.png")) EXIT_FAILURE;

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
    platforms.push_back(Platform(&platform21, sf::Vector2f(4360.0f, 1140.80f)));
    platforms.push_back(Platform(&platform22, sf::Vector2f(4600.0f, 1097.75f)));
    platforms.push_back(Platform(&platform23, sf::Vector2f(4587.5f, 304.03f)));
    platforms.push_back(Platform(&platform24, sf::Vector2f(4640.0f, 495.06f)));
    platforms.push_back(Platform(&platform25, sf::Vector2f(4800.0f, 408.96f)));
    platforms.push_back(Platform(&platform25, sf::Vector2f(4960.0f, 322.87f)));
    platforms.push_back(Platform(&platform26, sf::Vector2f(5120.0f, 322.87f)));
    platforms.push_back(Platform(&platform27, sf::Vector2f(5520.0f, 236.77f)));
    platforms.push_back(Platform(&platform28, sf::Vector2f(5920.0f, 408.96f)));
    platforms.push_back(Platform(&platform29, sf::Vector2f(6480.0f, 322.87f)));
    platforms.push_back(Platform(&platform30, sf::Vector2f(6720.0f, 193.72f)));
    platforms.push_back(Platform(&platform31, sf::Vector2f(6880.0f, 150.67f)));
    platforms.push_back(Platform(&platform32, sf::Vector2f(7620.0f, 45.74f)));
    platforms.push_back(Platform(&platform33, sf::Vector2f(7040.0f, 0.0f)));
    platforms.push_back(Platform(&platform34, sf::Vector2f(7160.0f, 1140.8f)));
    platforms.push_back(Platform(&platform35, sf::Vector2f(7040.0f, 791.03f)));
    platforms.push_back(Platform(&platform36, sf::Vector2f(7120.0f, 1442.15f)));
    platforms.push_back(Platform(&platform37, sf::Vector2f(7200.0f, 1485.20f)));
    platforms.push_back(Platform(&platform38, sf::Vector2f(7240.0f, 1528.25f)));
    platforms.push_back(Platform(&platform39, sf::Vector2f(7280.0f, 1571.3f)));
    platforms.push_back(Platform(&platform39, sf::Vector2f(7320.0f, 1614.35f)));
    platforms.push_back(Platform(&platform39, sf::Vector2f(7360.0f, 1657.4f)));
    platforms.push_back(Platform(&platform39, sf::Vector2f(7400.0f, 1700.44f)));
    platforms.push_back(Platform(&platform39, sf::Vector2f(7440.0f, 1743.50f)));
    platforms.push_back(Platform(&platform39, sf::Vector2f(7480.0f, 1786.55f)));
    platforms.push_back(Platform(&platform40, sf::Vector2f(7580.0f, 1345.29f)));
    platforms.push_back(Platform(&platform41, sf::Vector2f(7520.0f, 2087.89f)));
    platforms.push_back(Platform(&platform42, sf::Vector2f(7240.0f, 2346.19f)));
    platforms.push_back(Platform(&platform42, sf::Vector2f(7400.0f, 2260.09f)));
    platforms.push_back(Platform(&platform43, sf::Vector2f(7120.0f, 1826.9f)));
    platforms.push_back(Platform(&platform44, sf::Vector2f(7175.0f, 2432.29f)));
    platforms.push_back(Platform(&platform45, sf::Vector2f(7080.0f, 1991.03f)));
    platforms.push_back(Platform(&platform46, sf::Vector2f(7120.0f, 3078.027f)));
    platforms.push_back(Platform(&platform47, sf::Vector2f(7680.0f, 2991.93f)));
    platforms.push_back(Platform(&platform48, sf::Vector2f(8000.0f, 2905.83f)));
    platforms.push_back(Platform(&platform49, sf::Vector2f(9640.0f, 3078.027f)));
    platforms.push_back(Platform(&platform50, sf::Vector2f(10200.0f, 2771.30f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(2800.f, 1311.83f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(2880.f, 1374.88f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(2960.f, 1417.93f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3160.f, 1461.f)));
    platforms.push_back(Platform(&platform52, sf::Vector2f(3200.f, 1568.6f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3400.f, 1420.62f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3520.f, 1374.88f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3560.f, 1311.83f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3600.f, 1311.83f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3840.f, 1504.035f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3800.f, 1417.94f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(3880.f, 1417.94f)));
    platforms.push_back(Platform(&platform53, sf::Vector2f(3920.f, 1374.88f)));
    platforms.push_back(Platform(&platform54, sf::Vector2f(4000.f, 1417.93f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(4200.f, 1331.84f)));
    platforms.push_back(Platform(&platform53, sf::Vector2f(4720.f, 772.197f)));
    platforms.push_back(Platform(&platform53, sf::Vector2f(4800.f, 772.197f)));
    platforms.push_back(Platform(&platform54, sf::Vector2f(4880.f, 858.3f)));
    platforms.push_back(Platform(&platform54, sf::Vector2f(4600.f, 212.556f)));
    platforms.push_back(Platform(&platform53, sf::Vector2f(4720.f, 212.556f)));
    platforms.push_back(Platform(&platform55, sf::Vector2f(4800.f, 126.46f)));
    platforms.push_back(Platform(&platform55, sf::Vector2f(4960.f, 126.46f)));
    platforms.push_back(Platform(&platform51, sf::Vector2f(5120.f, 86.1f)));
    platforms.push_back(Platform(&platform53, sf::Vector2f(5160.f, 40.34f)));
    platforms.push_back(Platform(&platform50, sf::Vector2f(5120.f, 339.f)));


    sf::Texture enemyplatform1;
    if (!enemyplatform1.loadFromFile("Resources/Platforms/enemy1.png")) EXIT_FAILURE;
    vector<Platform> enemyplatforms;
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(2960.f, 495.067f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(2930.f, 1603.58f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(3965.f, 1533.63f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(4960.f, 1140.8f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(4600.f, 495.067f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(5437.5f, 252.9f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(2960.f, 495.067f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(5422.f, 148.f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(5920.f, 131.84f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(5845.f, 341.7f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(6400.f, 352.46f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(6382.5f, 234.08f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(6720.f, 242.15f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(7120.f, 1140.8f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(7120.f, 2432.28f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(6435.f, 231.4f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(7360.f, 2230.58f)));
    enemyplatforms.push_back(Platform(&enemyplatform1, sf::Vector2f(7200.f, 2776.23)));

    // Ladders
    vector<Ladders> ladders;
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 387.44f), sf::Vector2f(4960.0f, 1140.80f)));
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 344.40f), sf::Vector2f(2960.0f, 495.06f)));
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 285.29f), sf::Vector2f(2680.0f, 1143.49f)));
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 473.54f), sf::Vector2f(4600.0f, 495.06f)));
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 301.345f), sf::Vector2f(7120.0f, 1140.8f)));
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 301.345f), sf::Vector2f(7520.0f, 1786.54f)));
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 726.457f), sf::Vector2f(7560.0f, 150.67f)));
    ladders.push_back(Ladders(sf::Vector2f(40.0f, 301.345f), sf::Vector2f(7120.0f, 2432.28f)));

    // Pricker
    vector<Ladders> prickers;
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(2880.0f, 1113.9f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(3040.0f, 1113.9f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(2720.0f, 1113.9f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(3760.0f, 1759.64f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(7520.0f, 1113.9f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(7440.0f, 1113.9f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(2760.0f, 1759.64f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(2840.0f, 1759.64f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(7120.f, 3051.12f)));
    prickers.push_back(Ladders(sf::Vector2f(80.0f, 26.9f), sf::Vector2f(7220.f, 3051.12f)));

    for (Ladders& pricker : prickers)
    {
        pricker.SetTexture(&texturePricker);
    }

    vector<Ladders> prickers2;
    prickers2.push_back(Ladders(sf::Vector2f(40.0f, 26.9f), sf::Vector2f(2920.0f, 1759.64f)));
    prickers2.push_back(Ladders(sf::Vector2f(40.0f, 40.0f), sf::Vector2f(7240.f, 1485.20f)));
    prickers2.push_back(Ladders(sf::Vector2f(40.0f, 40.0f), sf::Vector2f(7440.f, 1700.45f)));
    prickers2.push_back(Ladders(sf::Vector2f(40.0f, 40.0f), sf::Vector2f(7400.f, 1657.4f)));
    prickers2.push_back(Ladders(sf::Vector2f(40.0f, 40.0f), sf::Vector2f(7320.f, 1571.3f)));

    for (Ladders& pricker : prickers2)
    {
        pricker.SetTexture(&texturePricker2);
    }

    // Class Object
    class player Player1;
    Player1.sprite.setTexture(texturePlayer);

    // Shoot Vector Array
    vector<shoot>::const_iterator iter;
    vector<shoot> shootArray;
    vector<shoot> enemyshootArray;

    // Shoot Object
    class shoot shoot1;
    shoot1.sprite.setTexture(textureRasengan);

    class shoot shootEnemy;
    shootEnemy.sprite.setTexture(textureRasengan);

    // Enemy Vector Array
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray;

    vector<enemy2>::const_iterator iter44;
    vector<enemy2> enemyArray2;

    // Enemy Object
    class enemy enemy1;
    enemy1.sprite.setTexture(textureEnemy);
    
    class enemy2 enemy0(0, 0);
    enemy0.sprite.setTexture(textureEnemy2);

    class enemy2 enemy01(0, 230);
    enemy01.sprite.setTexture(textureEnemy2);
    enemy01.attackDamage = 10;
    enemy01.hp = 40;
    enemy01.movementSpeed = 2;
    enemy01.check = 2;

    // Text Vector Array
    vector<textDisplay>::const_iterator iter8;
    vector<textDisplay> textDisplayArray;

    // Text Display Object
    class textDisplay textDisplay1;
    textDisplay1.text.setFont(font);

    // Text Coins
    sf::Text Score("Scores : ", font, 25);
    Score.setFillColor(sf::Color::Blue);
    Score.setPosition(view1.getCenter().x + window.getSize().x / 2 - 200, 20);

    // Coin Vector Array
    vector<pickup>::const_iterator iter11;
    vector<pickup> pickupArray;
    vector<pickup> pickupFireArray;
    vector<pickup> pickupFirerateArray;

    // Pickup Object
    class pickup pickup1;
    pickup1.sprite.setTexture(textureMedkit);
    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));

    pickup pickupFire;
    pickupFire.sprite.setTexture(textureItems);
    pickupFire.sprite.setTextureRect(sf::IntRect(0, 0, 106, 106));

    pickup pickupFirerate;
    pickupFirerate.sprite.setTexture(textureItems);
    pickupFirerate.sprite.setTextureRect(sf::IntRect(107, 0, 106, 106));

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
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        // Start the game loop
        if (State == 3)
        {
            for (int i = 0; i < 6; i++)
            {
                enemy1.sprite.setPosition(generateRandomin(400, 2875), 100);
                enemyArray.push_back(enemy1);
            }
            cout << "HELLO" << endl;
            for (int i = 0; i < 3; i++)
            {
                enemy1.sprite.setPosition(generateRandomin(3125, 3575), 1627);
                enemyArray.push_back(enemy1);
            }

            for (int i = 0; i < 4; i++)
            {
                enemy1.sprite.setPosition(generateRandomin(4125, 4952), 1442);
                enemyArray.push_back(enemy1);
                enemy0.sprite.setPosition(generateRandomin(8400, 8780), 2700);
                enemyArray2.push_back(enemy0);
                enemy1.sprite.setPosition(generateRandomin(7550, 7900), 2700);
                enemyArray.push_back(enemy1);
            }

            for (int i = 0; i < 2; i++)
            {
                enemy0.sprite.setPosition(generateRandomin(4657, 4937), 995);
                enemyArray2.push_back(enemy0);
                enemy0.sprite.setPosition(generateRandomin(7000, 7500), 80);
                enemyArray2.push_back(enemy0);
                enemy0.sprite.setPosition(generateRandomin(8400, 8780), 2700);
                enemyArray2.push_back(enemy0);
                enemy1.sprite.setPosition(generateRandomin(8400, 8700), 2700);
                enemyArray.push_back(enemy1);
                enemy01.sprite.setPosition(generateRandomin(8875, 9250), 2658);
                enemyArray2.push_back(enemy01);
            }

            enemy0.sprite.setPosition(generateRandomin(7250, 7400), 860);
            enemyArray2.push_back(enemy0);
            enemy1.sprite.setPosition(generateRandomin(7250, 7400), 860);
            enemyArray.push_back(enemy1);
            enemy1.sprite.setPosition(5100, 240);
            enemyArray.push_back(enemy1);
            enemyArray.push_back(enemy1);
            enemy1.sprite.setPosition(6127, 250);
            enemyArray.push_back(enemy1);
            enemyArray.push_back(enemy1);

            enemy0.sprite.setPosition(5725, 135);
            enemyArray2.push_back(enemy0);
            enemy0.sprite.setPosition(7475, 2098);
            enemyArray2.push_back(enemy0);
            enemy0.sprite.setPosition(7290, 2180);
            enemyArray2.push_back(enemy0);
            enemy0.sprite.setPosition(6587, 220);
            enemyArray2.push_back(enemy0);

            backgroundSound.play();
            backgroundSound.setLoop(true);
            while (window.isOpen())
            {
                dt = clockdt.restart().asSeconds();
                if (dt > 1 / 40.f)
                {
                    dt = 1 / 40.f;
                }
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
                    FILE* fp;
                    vector <pair<int, string>> userScore;
                    char temp[255];
                    int scoreH[6];
                    string name[6];
                    fp = fopen("./Score.txt", "r");
                    for (int i = 0; i < 5; i++)
                    {
                        fscanf(fp, "%s", &temp);
                        name[i] = temp;
                        fscanf(fp, "%d", &scoreH[i]);
                        userScore.push_back(make_pair(scoreH[i], name[i]));
                        //cout << temp << " " << score;
                    }
                    scoreH[5] = Player1.score;
                    name[5] = input;
                    userScore.push_back(make_pair(scoreH[5], name[5]));
                    sort(userScore.begin(), userScore.end());
                    fclose(fp);
                    fopen("./Score.txt", "w");
                    for (int i = 5; i >= 1; i--)
                    {
                        strcpy(temp, userScore[i].second.c_str());
                        fprintf(fp, "%s %d\n", temp, userScore[i].first);
                    }
                    fclose(fp);

                    State = -1;
                    Player1.hp = 100;  
                    Player1.score = 0;
                    Player1.sprite.setPosition(20, -500);
                    enemyArray.clear();
                    enemyArray2.clear();
                    break;
                }
                // Clock
                sf::Time elapsed = clock.getElapsedTime();

                sf::Vector2f direction1;

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

                    counter = 0;
                    for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                    {
                        if (platform.GetCollider().CheckCollision(enemyArray2[counter].GetCollider(), direction1, 1.0f))
                            enemyArray2[counter].OnCollision(direction1);
                        counter++;
                    }

                    counter = 0;
                    for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
                    {
                        if (shootArray[counter].sprite.getGlobalBounds().intersects(platform.body.getGlobalBounds()))
                        {
                            shootArray[counter].destroy = true;
                        }
                        counter++;
                    }

                    counter = 0;
                    for (iter = enemyshootArray.begin(); iter != enemyshootArray.end(); iter++)
                    {
                        if (enemyshootArray[counter].sprite.getGlobalBounds().intersects(platform.body.getGlobalBounds()))
                        {
                            enemyshootArray[counter].destroy = true;
                        }
                        counter++;
                    }
                }

                for (Platform& platform : enemyplatforms)
                {
                    counter = 0;
                    for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
                    {
                        if (platform.GetCollider().CheckCollision(enemyArray[counter].GetCollider(), direction1, 1.0f))
                            enemyArray[counter].OnCollision(direction1);
                        counter++;
                    }

                    counter = 0;
                    for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                    {
                        if (platform.GetCollider().CheckCollision(enemyArray2[counter].GetCollider(), direction1, 1.0f))
                            enemyArray2[counter].OnCollision(direction1);
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

                for (Ladders& pricker : prickers)
                {
                    if (Player1.sprite.getGlobalBounds().intersects(pricker.rect.getGlobalBounds()))
                    {
                        Player1.hp -= 100;
                    }
                }

                for (Ladders& pricker : prickers2)
                {
                    if (Player1.sprite.getGlobalBounds().intersects(pricker.rect.getGlobalBounds()))
                    {
                        Player1.hp -= 100;
                    }
                }

                // Player collides Pickuphp Items
                counter = 0;
                for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
                {
                    if (Player1.sprite.getGlobalBounds().intersects(pickupArray[counter].sprite.getGlobalBounds()))
                    {
                        pickupSoundhp.play();
                        if (pickupArray[counter].isCol == true)
                        {
                            Player1.hp += pickupArray[counter].hp;
                            if (Player1.hp >= 100)
                                Player1.hp = 100;
                        }
                        pickupArray[counter].destroy = true;
                    }
                    counter++;
                }

                counter = 0;
                for (iter11 = pickupFireArray.begin(); iter11 != pickupFireArray.end(); iter11++)
                {
                    if (Player1.sprite.getGlobalBounds().intersects(pickupFireArray[counter].sprite.getGlobalBounds()))
                    {
                        itemFire.restart();
                        pickupSoundhp.play();
                        if (pickupFireArray[counter].isCol == true)
                        {
                            shootSound.setBuffer(bufferShootFireball);
                            Player1.attackDamage = pickupFire.powerupDamage;
                            Player1.powerupFire = true;
                            shoot1.sprite.setTexture(textureFireball);
                        }
                        pickupFireArray[counter].destroy = true;
                    }
                    counter++;
                }

                counter = 0;
                for (iter11 = pickupFirerateArray.begin(); iter11 != pickupFirerateArray.end(); iter11++)
                {
                    if (Player1.sprite.getGlobalBounds().intersects(pickupFirerateArray[counter].sprite.getGlobalBounds()))
                    {
                        itemFirerate.restart();
                        pickupSoundhp.play();
                        if (pickupFirerateArray[counter].isCol == true)
                        {
                            Player1.fireRate = pickupFirerate.fireRate;
                            Player1.powerupFirerate = true;
                        }
                        pickupFirerateArray[counter].destroy = true;
                    }
                    counter++;
                }

                if (Player1.powerupFire == true)
                {
                    if (itemFire.getElapsedTime().asSeconds() >= 10)
                    {
                        shootSound.setBuffer(bufferShootRasengan);
                        Player1.powerupFire = false;
                        Player1.attackDamage = 5;
                        shoot1.sprite.setTexture(textureRasengan);
                    }
                }

                if (Player1.powerupFirerate == true)
                {
                    if (itemFirerate.getElapsedTime().asSeconds() >= 5)
                    {
                        Player1.powerupFirerate = false;
                        Player1.fireRate = 0.5;
                    }
                }
                ///////////////////////////////////////////////////////////////////////////////////////

                if (clockCollideEnemy.getElapsedTime().asSeconds() >= 0.2)
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

                    counter = 0;
                    for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                    {
                        if (Player1.sprite.getGlobalBounds().intersects(enemyArray2[counter].sprite.getGlobalBounds()))
                        {
                            // Text Display
                            textDisplay1.text.setString(to_string(enemyArray2[counter].attackDamage));
                            textDisplay1.text.setPosition(Player1.sprite.getPosition().x + Player1.sprite.getGlobalBounds().width / 2,
                                Player1.sprite.getPosition().y - Player1.sprite.getGlobalBounds().height / 2);
                            textDisplayArray.push_back(textDisplay1);

                            Player1.hp -= enemyArray2[counter].attackDamage;
                            cout << Player1.hp << endl;
                        }
                        counter++;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
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
                            hitSound.play();

                            // Text Display
                            textDisplay1.text.setString(to_string(Player1.attackDamage));
                            textDisplay1.text.setPosition(enemyArray[counter2].sprite.getPosition().x + enemyArray[counter2].sprite.getGlobalBounds().width / 2,
                                enemyArray[counter2].sprite.getPosition().y - enemyArray[counter2].sprite.getGlobalBounds().height / 2.0f);
                            textDisplayArray.push_back(textDisplay1);

                            enemyArray[counter2].hp -= Player1.attackDamage;
                            if (enemyArray[counter2].hp <= 0)
                            {
                                enemyArray[counter2].alive = false;
                            }
                        }
                        counter2++;
                    }
                    counter++;
                }

                counter = 0;
                for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
                {
                    counter2 = 0;
                    for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                    {
                        if (shootArray[counter].sprite.getGlobalBounds().intersects(enemyArray2[counter2].sprite.getGlobalBounds()))
                        {
                            //cout << "Collision" << endl;
                            shootArray[counter].destroy = true;
                            hitSound.play();

                            // Text Display
                            textDisplay1.text.setString(to_string(Player1.attackDamage));
                            textDisplay1.text.setPosition(enemyArray2[counter2].sprite.getPosition().x + enemyArray2[counter2].sprite.getGlobalBounds().width / 2,
                                enemyArray2[counter2].sprite.getPosition().y - enemyArray2[counter2].sprite.getGlobalBounds().height / 2.0f);
                            textDisplayArray.push_back(textDisplay1);

                            enemyArray2[counter2].hp -= Player1.attackDamage;
                            if (enemyArray2[counter2].hp <= 0)
                            {
                                enemyArray2[counter2].alive = false;
                            }
                        }
                        counter2++;
                    }
                    counter++;
                }

                // Projectile Collides with Player
                counter = 0;
                for (iter = enemyshootArray.begin(); iter != enemyshootArray.end(); iter++)
                {
                    if (enemyshootArray[counter].sprite.getGlobalBounds().intersects(Player1.sprite.getGlobalBounds()))
                    {
                        hitSound.play();
                        Player1.score -= 1;
                        enemyshootArray[counter].destroy = true;
                        Player1.hp -= enemyshootArray[counter].attackDamage;
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

                counter = 0;
                for (iter11 = pickupFireArray.begin(); iter11 != pickupFireArray.end(); iter11++)
                {
                    if (pickupFireArray[counter].destroy == true)
                    {
                        pickupFireArray.erase(iter11);
                        break;
                    }
                    counter++;
                }

                counter = 0;
                for (iter11 = pickupFirerateArray.begin(); iter11 != pickupFirerateArray.end(); iter11++)
                {
                    if (pickupFirerateArray[counter].destroy == true)
                    {
                        pickupFirerateArray.erase(iter11);
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
                        Player1.score += 10;
                        if (generateRandom(2) == 1)
                        {
                            pickup1.sprite.setPosition(enemyArray[counter].sprite.getPosition());
                            pickupArray.push_back(pickup1);
                        }
                        if (generateRandom(4) == 1)
                        {
                            pickupFire.sprite.setPosition(enemyArray[counter].sprite.getPosition().x - 10, enemyArray[counter].sprite.getPosition().y);
                            pickupFireArray.push_back(pickupFire);
                        }
                        if (generateRandom(4) == 1)
                        {
                            pickupFirerate.sprite.setPosition(enemyArray[counter].sprite.getPosition().x + 10, enemyArray[counter].sprite.getPosition().y);
                            pickupFirerateArray.push_back(pickupFirerate);
                        }
                        enemyArray.erase(iter4);
                        break;
                    }
                    counter++;
                }

                counter = 0;
                for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                {
                    if (enemyArray2[counter].alive == false)
                    {
                        cout << "Enemy has been dead" << endl;
                        Player1.score += 20;
                        if (generateRandom(2) == 1)
                        {
                            pickup1.sprite.setPosition(enemyArray2[counter].sprite.getPosition());
                            pickupArray.push_back(pickup1);
                        }
                        if (generateRandom(4) == 1)
                        {
                            pickupFire.sprite.setPosition(enemyArray2[counter].sprite.getPosition().x - 10, enemyArray2[counter].sprite.getPosition().y);
                            pickupFireArray.push_back(pickupFire);
                        }
                        if (generateRandom(4) == 1)
                        {
                            pickupFirerate.sprite.setPosition(enemyArray2[counter].sprite.getPosition().x + 10, enemyArray2[counter].sprite.getPosition().y);
                            pickupFirerateArray.push_back(pickupFirerate);
                        }
                        enemyArray2.erase(iter44);
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

                // Shoot                   
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
                {
                    if (clock.getElapsedTime().asSeconds() >= Player1.fireRate)
                    {
                        clock.restart();
                        shootSound.play();
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

                if (clockEnemy.getElapsedTime().asSeconds() >= 0.1)
                {
                    clockEnemy.restart();
                    counter = 0;
                    for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
                    {
                        // Player from left
                        if (enemyArray[counter].sprite.getPosition().x - Player1.GetPosition().x >= 0 && enemyArray[counter].sprite.getPosition().x - Player1.GetPosition().x < 550 && abs(enemyArray[counter].sprite.getPosition().y - Player1.GetPosition().y) <= 100)
                        {
                            enemyArray[counter].direction = 3;
                            enemyArray[counter].counter = 0;
                            if (enemyArray[counter].sprite.getPosition().x - Player1.GetPosition().x < 350)
                                enemyArray[counter].direction = 1;
                            if (generateRandom(10) == 1)
                            {
                                shootEnemy.sprite.setPosition(enemyArray[counter].GetPosition().x + enemyArray[counter].sprite.getGlobalBounds().width / 2,
                                    enemyArray[counter].GetPosition().y + 10);
                                shootEnemy.direction = 3;
                                enemyshootArray.push_back(shootEnemy);
                                enemyshootSound.play();
                            }
                        }

                        // Player from right
                        if (Player1.GetPosition().x - enemyArray[counter].sprite.getPosition().x >= 0 && Player1.GetPosition().x - enemyArray[counter].sprite.getPosition().x < 550 && abs(enemyArray[counter].sprite.getPosition().y - Player1.GetPosition().y) <= 100)
                        {
                            enemyArray[counter].direction = 4;
                            enemyArray[counter].counter = 0;
                            if (Player1.GetPosition().x - enemyArray[counter].sprite.getPosition().x < 350)
                            {
                                enemyArray[counter].direction = 2;
                            }
                            if (generateRandom(10) == 1)
                            {
                                shootEnemy.sprite.setPosition(enemyArray[counter].GetPosition().x + enemyArray[counter].sprite.getGlobalBounds().width / 2,
                                    enemyArray[counter].GetPosition().y + 10);
                                shootEnemy.direction = 4;
                                enemyshootArray.push_back(shootEnemy);
                                enemyshootSound.play();
                            }
                        }
                        counter++;
                    }

                    counter = 0;
                    for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                    {
                        // Player from left
                        if (enemyArray2[counter].sprite.getPosition().x - Player1.GetPosition().x >= 0 && enemyArray2[counter].sprite.getPosition().x - Player1.GetPosition().x < 550 && abs(enemyArray2[counter].sprite.getPosition().y - Player1.GetPosition().y) <= 100)
                        {
                            enemyArray2[counter].direction = 3;
                            enemyArray2[counter].counter = 0;
                            if (enemyArray2[counter].sprite.getPosition().x - Player1.GetPosition().x < 350)
                                enemyArray2[counter].direction = 1;
                            if (generateRandom(10) == 1)
                            {
                                shootEnemy.sprite.setPosition(enemyArray2[counter].GetPosition().x + enemyArray2[counter].sprite.getGlobalBounds().width / 2,
                                    enemyArray2[counter].GetPosition().y + 10);
                                shootEnemy.direction = 3;
                                enemyshootArray.push_back(shootEnemy);
                                enemyshootSound.play();
                            }
                        }

                        // Player from right
                        if (Player1.GetPosition().x - enemyArray2[counter].sprite.getPosition().x >= 0 && Player1.GetPosition().x - enemyArray2[counter].sprite.getPosition().x < 550 && abs(enemyArray2[counter].sprite.getPosition().y - Player1.GetPosition().y) <= 100)
                        {
                            enemyArray2[counter].direction = 4;
                            enemyArray2[counter].counter = 0;
                            if (Player1.GetPosition().x - enemyArray2[counter].sprite.getPosition().x < 350)
                            {
                                enemyArray2[counter].direction = 2;
                            }
                            if (generateRandom(10) == 1)
                            {
                                shootEnemy.sprite.setPosition(enemyArray2[counter].GetPosition().x + enemyArray2[counter].sprite.getGlobalBounds().width / 2,
                                    enemyArray2[counter].GetPosition().y + 10);
                                shootEnemy.direction = 4;
                                enemyshootArray.push_back(shootEnemy);
                                enemyshootSound.play();
                            }
                        }
                        counter++;
                    }
                }

                // Update Shoot
                counter = 0;
                for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
                {
                    shootArray[counter].update(); // Update Shoot
                    counter++;
                }

                counter = 0;
                for (iter = enemyshootArray.begin(); iter != enemyshootArray.end(); iter++)
                {
                    enemyshootArray[counter].update(); // Update Shoot
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

                counter = 0;
                for (iter = enemyshootArray.begin(); iter != enemyshootArray.end(); iter++)
                {
                    if (enemyshootArray[counter].destroy == true)
                    {
                        enemyshootArray.erase(iter);
                        break;
                    }
                    counter++;
                }

                //Update Player
                Player1.update(dt);
                //cout << Player1.movementSpeed << endl;

                // Update UI
                view1.setCenter(Player1.GetPosition().x, Player1.GetPosition().y - window.getSize().y / 7);
                Score.setPosition(view1.getCenter().x + 300, view1.getCenter().y - 280);
                playerHp.setPosition(view1.getCenter().x - 350, view1.getCenter().y - 270);
                playerHpSlot.setPosition(view1.getCenter().x - 350, view1.getCenter().y - 270);

                window.setView(view1);

                //Update Enemy
                counter = 0;
                for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
                {
                    enemyArray[counter].update(dt);
                    counter++;
                }

                counter = 0;
                for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                {
                    if (enemyArray2[counter].check == 1)
                        enemyArray2[counter].update(0, 0, dt);
                    if (enemyArray2[counter].check == 2)
                        enemyArray2[counter].update(0, 230, dt);
                    counter++;
                }

                // Update UI
                playerHp.setSize(sf::Vector2f(Player1.hp * 2, 20));
                playerMana.setSize(sf::Vector2f(Player1.mana * 2, 20));
                Score.setString("Scores : " + to_string(Player1.score));

                ////////////////////////////////////////////////////////********* DRAW EVERYTHING *******/////////////////////////////////////////////////////////////////////

                for (Platform& platform : platforms)
                    platform.Draw(window);

                window.draw(backGround);
                window.draw(door1);
                window.draw(door2);
                window.draw(door3);

                for (Ladders& pricker : prickers)
                    pricker.Draw(window);

                for (Ladders& pricker : prickers2)
                    pricker.Draw(window);

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
                for (iter11 = pickupFireArray.begin(); iter11 != pickupFireArray.end(); iter11++)
                {
                    window.draw(pickupFireArray[counter].sprite);
                    counter++;
                }

                counter = 0;
                for (iter11 = pickupFirerateArray.begin(); iter11 != pickupFirerateArray.end(); iter11++)
                {
                    window.draw(pickupFirerateArray[counter].sprite);
                    counter++;
                }

                // Draw Enemy
                counter = 0;
                for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
                {
                    window.draw(enemyArray[counter].sprite);
                    counter++;
                }

                counter = 0;
                for (iter44 = enemyArray2.begin(); iter44 != enemyArray2.end(); iter44++)
                {
                    window.draw(enemyArray2[counter].sprite);
                    counter++;
                }

                // Draw shoot
                counter = 0;
                for (iter = shootArray.begin(); iter != shootArray.end(); iter++)
                {
                    window.draw(shootArray[counter].sprite);
                    counter++;
                }

                counter = 0;
                for (iter = enemyshootArray.begin(); iter != enemyshootArray.end(); iter++)
                {
                    window.draw(enemyshootArray[counter].sprite);
                    counter++;
                }

                // Draw UI
                window.draw(Score);
                window.draw(playerHpSlot);
                window.draw(playerHp);

                // Draw Text
                counter = 0;
                for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
                {
                    textDisplayArray[counter].update();
                    window.draw(textDisplayArray[counter].text);

                    counter++;
                }
                //cout <<"Player.x = " << Player1.GetPosition().x << " Player.y = " << Player1.GetPosition().y << endl;
                //cout << "x = " << window.mapPixelToCoords(sf::Mouse::getPosition(window)).x << " y = " << window.mapPixelToCoords(sf::Mouse::getPosition(window)).y << endl;
                window.display();
            }
        }

        if (State == -1)
        {
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
            mainmenu.update(view1);
            mainmenu.Draw(window);
            window.display();
        }
        
        if (State == 0)
        {
            playerName.setFillColor(sf::Color::White);
            playerName.setFont(font);
            playerName.setCharacterSize(25);
            playerName.setPosition(window.getSize().x / 2, window.getSize().y / 2);

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode < 128)
                    {
                        std::cout << "Text entered: " << (event.text.unicode) << std::endl;
                        if (event.text.unicode == static_cast<sf::Uint32>(8) && input.getSize() > 0)
                        {
                            input.erase(input.getSize() - 1);
                        }
                        else
                        {
                            if (input.getSize() < 12 && event.text.unicode != 13)
                            {
                                if (event.text.unicode >= 97 && event.text.unicode <= 122)
                                {
                                    event.text.unicode -= 32;
                                }
                                if (event.text.unicode == 32)
                                {
                                    event.text.unicode = 95;
                                }
                                input += event.text.unicode;
                            }
                        }
                    }
                }
            }
            window.clear();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                State = 3;
            playerName.setString(input);
            window.draw(playerName);
            window.display();
        }

        if (State == 1)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                FILE* fp = fopen("./score.txt", "r");
                char temp[255];
                int score[5];
                vector <pair<int, string>> userScore;

                for (int i = 0; i < 5; i++)
                {
                    fscanf(fp, "%s", &temp);
                    name[i] = temp;
                    PlayerName[i].setString(name[i]);
                    fscanf(fp, "%d", &score[i]);
                    PlayerScore[i].setString(std::to_string(score[i]));
                    userScore.push_back(std::make_pair(score[i], name[i]));
                }

                for (int i = 0; i < 5; i++)
                {
                    PlayerName[i].setFont(font);
                    PlayerName[i].setCharacterSize(22.f);
                    PlayerName[i].setFillColor(sf::Color::White);
                    PlayerName[i].setPosition(view1.getCenter().x - 140, view1.getCenter().y - window.getSize().y / 2.f + 100.f + (100 * i));
                    PlayerScore[i].setFont(font);
                    PlayerScore[i].setCharacterSize(22.f);
                    PlayerScore[i].setFillColor(sf::Color::White);
                    PlayerScore[i].setPosition(view1.getCenter().x + 100, view1.getCenter().y - window.getSize().y / 2.f + 100.f + (100 * i));
                }
            }
            window.clear();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                State = -1;
            for (int i = 0; i < 5; i++)
            {
                window.draw(PlayerName[i]);
                window.draw(PlayerScore[i]);
            }
            window.display();
        }
    }

    // End Game
    return 0;
}
