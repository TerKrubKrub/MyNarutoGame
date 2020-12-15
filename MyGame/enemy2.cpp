#include "enemy2.h"
#include "random.h"

enemy2::enemy2(int x, int y)
{
    sprite.setTextureRect(sf::IntRect(x, y, 87, 104));
    sprite.setScale(1/2.f, 1/2.f);
}

void enemy2::update(int x, int y, float dt)
{
    sprite.move(velocity * dt);
    this->updateMovement(x, y, dt);
}

void enemy2::updateMovement(int x, int y, float dt)
{
    velocity.x = 0.0f;

    if (direction == 1)
    {
        sprite.setTextureRect(sf::IntRect(x , y, 87, 104));
    }
    if (direction == 2)
    {
        sprite.setTextureRect(sf::IntRect(x , y + 115, 87, 104));
    }
    if (direction == 3) //Left
    {
        velocity.x -= movementSpeed;
        sprite.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(x + (100 * counterWalking), y, 87, 104));
    }
    else
    {

    }
    if (direction == 4) //Right
    {
        velocity.x += movementSpeed;
        sprite.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(x + (100 * counterWalking), y + 115, 87, 104));
    }
    else
    {
        // No Movement
    }


    velocity.y += 981.0f * dt;

    if (clock.getElapsedTime().asSeconds() >= 0.3)
    {
        clock.restart();
        if (counterWalking == 4) 
            counterWalking = 0;
        counterWalking++;
    }

    counter++;
    if (counter >= movementLength)
    {
        direction = generateRandom(5);
        counter = 0;
    }
}
void enemy2::OnCollision(sf::Vector2f direction1)
{

    if (direction1.x < 0.0f)
    {
        //Collision on the Left
        velocity.x = 0.0f;
    }
    else if (direction1.x > 0.0f)
    {
        //Collision on the Right
        velocity.x = 0.0f;
    }
    if (direction1.y < 0.0f)
    {
        //Collision on the bottom
        velocity.y = 0.0f;
    }
    else if (direction1.y > 0.0f)
    {
        //Collision on the top
        velocity.y = 0.0f;
    }
}