#ifndef ENEMY
#define ENEMY

#include "entity.h"
#include "Collider.h"

class enemy : public entity
{
public:
	float movementSpeed = 1;
	float movementLength = 50;
	int attackDamage = 2;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int counter = 0;
	int hp = 3;
	bool alive = true;

	enemy();
	void update(float deltaTime);
	void updateMovement(float deltaTime);
	void OnCollision(sf::Vector2f direction1);
	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	Collider GetCollider() { return Collider(sprite); }

private:
	sf::Vector2f velocity;
};

#endif