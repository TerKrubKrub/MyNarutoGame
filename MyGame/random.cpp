#include "random.h"
int generateRandom(int max)
{
	int randomNumber = rand();
	float random = (randomNumber % max) + 1;
	int myRandom = random;
	return myRandom;
}

int generateRandom0(int max)
{
	int randomNumber = rand();
	float random = (randomNumber % max);
	int myRandom = random;
	return myRandom;
}

bool generateRandomBool()
{
	int randomNumber = rand();
	float random = (randomNumber % 2) + 1;
	int myRandom = random;
	if (myRandom == 1) return true;
	else return false;
}

int generateRandomin(int min, int max)
{
	//int randomNumber = rand();
	int random = (rand() % max) + 1;
	while (random < min)
	{
		random = (rand() % max) + 1;
	}
	int myRandom = random;
	return myRandom;
}
