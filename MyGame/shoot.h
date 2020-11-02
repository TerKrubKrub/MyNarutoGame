#ifndef SHOOT
#define SHOOT

#include "entity.h"

class shoot : public entity
{
public:
	float movementSpeed = 2;
	int attackDamage = 5;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right

	shoot();
	void update();
	//void updateMovement();

};

#endif