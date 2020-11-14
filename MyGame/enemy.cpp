#include "enemy.h"
#include "random.h"

enemy::enemy()
{
    sprite.setTextureRect(sf::IntRect(200 + (50 * 0), 0, 18, 25));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, sprite.getGlobalBounds().height / 2.0f);
}

void enemy::update(float deltaTime)
{
    sprite.move(velocity * deltaTime);
    this->updateMovement(deltaTime);
}

void enemy::updateMovement(float deltaTime)
{
    velocity.x = 0.0f;

    if (direction == 1)
    {
        //rect.move(0, -movementSpeed); //Up
    }
    else if (direction == 2)
    {
        //rect.move(0, movementSpeed); //Down
    }
    else if (direction == 3) //Left
    {
        velocity.x -= movementSpeed;
        sprite.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(200 + (50 * 0) + (50 * counterWalking), 0, 18, 25));
    }
    else if (direction == 4) //Right
    {
        velocity.x += movementSpeed;
        sprite.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(200 + (50 * 2) + (50 * counterWalking), 0, 18, 25));
    }
    else
    {
        // No Movement
    }


    velocity.y += 981.0f * deltaTime;

    
    if (counterWalking == 1) counterWalking = 0;
    counterWalking++;

    counter++;
    if (counter >= movementLength)
    {
        direction = generateRandom(10);
        counter = 0;
    }
}
void enemy::OnCollision(sf::Vector2f direction1)
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