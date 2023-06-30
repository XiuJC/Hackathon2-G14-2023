#include "Dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
	unsigned seed = time(0);
	srand(seed);
	sides = 6;					// creating a 6-sided dice
	roll();						// generate a random value 
}

Dice :: Dice(int numSides){
	unsigned seed = time(0);
	srand(seed);
	sides = numSides;
	roll();
}

void Dice :: roll(){
	const int MIN_VALUE = 1;
	value = (rand() % (sides - MIN_VALUE +1)) + MIN_VALUE;
}

int Dice :: getSides(){
	return sides;
}

int Dice :: getValue(){
	return value;
}

Dice::~Dice() {

}
