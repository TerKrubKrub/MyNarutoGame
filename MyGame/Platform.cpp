#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f position)
{
	body.setScale(1.0f, 1.0f);
	body.setTexture(*texture);
	body.setPosition(position);
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
