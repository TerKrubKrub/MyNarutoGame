#include "pickup.h"

pickup::pickup()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(500, 500);
    //rect.setFillColor(sf::Color::Yellow);
    sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    sprite.setScale(1/4.f, 1/4.f);
}
void pickup::update()
{
    sprite.setPosition(rect.getPosition());
}