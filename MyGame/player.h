#ifndef PLAYER
#define PLAYER

#include "entity.h"

class player : public entity
{
public:
	float movementSpeed = 1.0;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right

	player();
	void update();
	void updateMovement();

};

#endif