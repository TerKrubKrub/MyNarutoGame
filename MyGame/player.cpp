#include "player.h"

player::player()
{
    sprite.setPosition(10, 30);
    sprite.setTextureRect(sf::IntRect(6, 147, 37, 67));
    direction = 4;
}
void player::update(float dt)
{
    if (sprite.getPosition().x < 0) sprite.setPosition(0, sprite.getPosition().y);
    if (sprite.getPosition().x >= 5120 && sprite.getPosition().x <= 6900)
    {
        if (sprite.getPosition().y >= 600) hp = 0;
    }
    sprite.move(velocity * dt);
    this->updateMovement(dt);
}

void player::updateMovement(float dt)
{
    if (direction == 3)
        sprite.setTextureRect(sf::IntRect(260 + (counterWalking * 41), 147, 35, 67));
    if (direction == 4)
        sprite.setTextureRect(sf::IntRect(6 + (counterWalking * 41), 147, 35, 67));

    velocity.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (counterWalking >= 2) counterWalking = 0;
        sprite.setTextureRect(sf::IntRect(540 + (counterWalking * 61), 261, 57, 67));
        velocity.x -= movementSpeed;
        sprite.move(-movementSpeed, 0);
        direction = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (counterWalking >= 2) counterWalking = 0;
        sprite.setTextureRect(sf::IntRect(272 + (counterWalking * 61), 261, 57, 67));
        velocity.x += movementSpeed;
        sprite.move(movementSpeed, 0);
        direction = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        canJump = false;

        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
        //square root ( 2.0f * gravity * jumpHeight );
    }

    velocity.y += 981.0f * dt;

    if (clock.getElapsedTime().asSeconds() >= 0.2)
    {
        clock.restart();
        counterWalking++;
        if (counterWalking == 5) counterWalking = 0;
    }
}

void player::OnCollision(sf::Vector2f direction1)
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
        canJump = true;
    }
    else if (direction1.y > 0.0f)
    {
        //Collision on the top
        velocity.y = 0.0f;
    }
}
