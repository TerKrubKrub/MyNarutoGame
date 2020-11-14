#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f position)
{
	body.setScale(1.0f, 1.0f);
	body.setTexture(*texture);
	body.setPosition(position);
	body.setOrigin(body.getGlobalBounds().width / 2.0f, body.getGlobalBounds().height / 2.0f);
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
