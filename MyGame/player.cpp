#include "player.h"

player::player()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, sprite.getGlobalBounds().height / 2.0f);
}
void player::update(float deltaTime)
{
    if (rect.getPosition().x < 0) rect.setPosition(0, rect.getPosition().y);
    if (rect.getPosition().y < 0) rect.setPosition(rect.getPosition().x, 0);
    if (rect.getPosition().y > 767) rect.setPosition(rect.getPosition().x, 767);
    sprite.move(velocity * deltaTime);
    this->updateMovement(deltaTime);
}

void player::updateMovement(float deltaTime)
{
    velocity.x = 0.0f;
    

    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
        direction = 1;
        //cout << "Up Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
        direction = 2;
        //cout << "Down Pressed" << endl;
    }*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x -= movementSpeed;
        sprite.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
        direction = 3;
        //cout << "Left Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x += movementSpeed;
        sprite.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
        direction = 4;
        //cout << "Right Pressed" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        canJump = false;

        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
        //square root ( 2.0f * gravity * jumpHeight );
    }

    velocity.y += 981.0f * deltaTime;


    counterWalking++;
    if (counterWalking == 2) counterWalking = 0;

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
