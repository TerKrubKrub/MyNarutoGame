#include "pickup.h"

pickup::pickup()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    sprite.setScale(1/4.f, 1/4.f);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, sprite.getGlobalBounds().height / 2.0f);
}
void pickup::update()
{

}