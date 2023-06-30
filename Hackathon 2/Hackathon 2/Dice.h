#ifndef DICE_H
#define DICE_H

using namespace std;

// Dice class manages the RNG feature in this game.

class Dice{
	private:
		int sides;
		int value;
		
	public:
		Dice();			// The default constructor will create a 6-sided dice
		Dice(int);		// An overloading constructor to create different dices
						// e.g. a D20 with 20 sides.

		void roll();	// A function call that randomize 'value' variable for each call.
		int getSides();
		int getValue();
		~Dice();
};

#endif
