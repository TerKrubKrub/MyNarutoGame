#ifndef TEXTDISPLAY
#define TEXTDISPLAY

#include "entity.h"

class textDisplay : public entity
{
public:
	float movementSpeed = 2;
	string myString = "Default";
	int counter = 0;
	int lifeTime = 100;
	bool destroy = false;

	textDisplay();
	void update();
	//void textDisplay();

};

#endif