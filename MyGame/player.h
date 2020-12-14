#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "Collider.h"

class player : public entity
{
public:
	float movementSpeed = 5;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int hp = 100;
	int coins = 0;
	int mana = 0;
	float fireRate = 0.5f;
	bool powerupFirerate = false;
	bool powerupFire = false;
	sf::Vector2f velocity;

	player();
	void update(float dt);
	void updateMovement(float dt);
	void OnCollision(sf::Vector2f direction1);
	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	Collider GetCollider() { return Collider(sprite); }

private:
	sf::Clock clock;
	bool canJump;
	float jumpHeight = 130.0f;
};

#endif