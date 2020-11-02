#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
void player::update()
{
	sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
        direction = 1;
        cout << "Up Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
        direction = 2;
        cout << "Down Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
        direction = 3;
        cout << "Left Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
        direction = 4;
        cout << "Right Pressed" << endl;
    }
    counterWalking++;
    if (counterWalking == 2) counterWalking = 0;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        cout << "Mouse Left Click" << endl;
    }
}