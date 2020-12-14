#include "Ladders.h"

Ladders::Ladders(sf::Vector2f size, sf::Vector2f position)
{
	rect.setSize(size);
	rect.setPosition(position);
}

void Ladders::SetTexture(sf::Texture* texture)
{
	rect.setTexture(texture);
}

void Ladders::SetFillColor(sf::Color color)
{
	rect.setFillColor(color);
}

void Ladders::Draw(sf::RenderWindow& window)
{
	window.draw(rect);
}
