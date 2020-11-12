#include "shoot.h"

shoot::shoot()
{
	rect.setSize(sf::Vector2f(25, 25));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Green);
	sprite.setTextureRect(sf::IntRect(0, 0, 373, 373));
	sprite.setScale(1/14.8f, 1/15.12f);
}
void shoot::update()
{
	if (direction == 1) // Up
	{
		rect.move(0, -movementSpeed);
	}
	if (direction == 2) // Down
	{
		rect.move(0, movementSpeed);
	}
	if (direction == 3) // Left
	{
		rect.move(-movementSpeed, 0);
	}
	if (direction == 4) // Right
	{
		rect.move(movementSpeed, 0);
	}

	couterLifetime++;
	if (couterLifetime >= lifeTime)
	{
		destroy = true;
	}
	
	counterAnimation++;
	if (counterAnimation >= 2)
	{
		counterAnimation = 0;
	}

	sprite.setPosition(rect.getPosition());
}
