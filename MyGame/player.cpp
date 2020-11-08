#include "player.h"

player::player()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(400, 200);
    rect.setSize(sf::Vector2f(32, 32));
}
void player::update()
{
    if (sprite.getPosition().x < 0) sprite.setPosition(0, sprite.getPosition().y);
    if (sprite.getPosition().y < 0) sprite.setPosition(sprite.getPosition().x, 0);
    if (sprite.getPosition().y > 767) sprite.setPosition(sprite.getPosition().x, 767);
	//else sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
        direction = 1;
        //cout << "Up Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
        direction = 2;
        //cout << "Down Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
        direction = 3;
        //cout << "Left Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
        direction = 4;
        //cout << "Right Pressed" << endl;
    }
    counterWalking++;
    if (counterWalking == 2) counterWalking = 0;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        //cout << "Mouse Left Click" << endl;
    }
    //cout << "x = " << sprite.getPosition().x << " y = " << sprite.getPosition().y << endl;
}