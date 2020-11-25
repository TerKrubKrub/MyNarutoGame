#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "Collider.h"

class player : public entity
{
public:
	float movementSpeed = 5;
	int attackDamage = 1;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int hp = 10;
	int coins = 0;

	player();
	void update(float dt);
	void updateMovement(float dt);
	void OnCollision(sf::Vector2f direction1);
	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	Collider GetCollider() { return Collider(sprite); }

private:
	sf::Clock clock;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight = 130.0f;
};

#endif