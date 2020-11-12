#include "enemy.h"
#include "random.h"

enemy::enemy()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(400, 200);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(200 + (50 * 0), 0, 18, 25));
}

void enemy::update()
{
    sprite.setPosition(rect.getPosition());
}


void enemy::updateMovement()
{
    if (direction == 1)
    {
        rect.move(0, -movementSpeed); //Up
    }
    else if (direction == 2)
    {
        rect.move(0, movementSpeed); //Down
    }
    else if (direction == 3) //Left
    {
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(200 + (50 * 0) + (50 * counterWalking), 0, 18, 25));
    }
    else if (direction == 4) //Right
    {
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(200 + (50 * 2) + (50 * counterWalking), 0, 18, 25));
    }
    else
    {
        // No Movement

    }
    counterWalking++;
    if (counterWalking == 1) counterWalking = 0;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        cout << "Mouse Left Click" << endl;
    }
    counter++;
    if (counter >= movementLength)
    {
        direction = generateRandom(10);
        counter = 0;
    }
}