#pragma once
#include "entity.h"

class Collider
{
public:
	Collider(sf::Sprite& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	float getWidth();
	float getHeight();

	bool CheckCollision(Collider other, sf::Vector2f& direction1, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() 
	{ 
		return { body.getGlobalBounds().width / 2.0f, body.getGlobalBounds().height / 2.0f };
	}	
	sf::Vector2f GetSize()
	{ 
		return  { body.getGlobalBounds().width, body.getGlobalBounds().height };
	}

private:
	sf::Sprite& body;

};

