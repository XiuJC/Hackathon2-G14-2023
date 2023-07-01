#ifndef MOVESET_H
#define MOVESET_H
#include <string>
using namespace std;

/* 	(may store moves from Ozen and Bosses)  
	MoveSet class can be deleted I guess...  
	Ozen's moves don't need to be stored in list.  
	For Bosses's, I want to make their combat actions in a pattern.  
	So a circular linked list is needed but maybe can declare in other part.  */

// a class to manage player's moves
// has a derived class to manage bosses' moves

class Move{
	private:	
		double AccuracyRate;
		bool isAOE;				// Boolean variable to see if the move has AOE
		bool isConcentrate;		// Boolean variable to see if the move is 'Concentrate'
		
	protected:
		string MoveName;
		string Description;
		double AttackValue;		
		
	public:
		// constructor to define a player's move
		Move();
		~Move();
		Move(const string&, const string&, double, double, bool, bool);

		// overloading constructor to define a Boss' move that 
		// will be inherited to BossMove class
		Move(const string&, const string&, double);

		string getName() const;
		string getDescription() const;

		double getAttack();
		double getAccuracy();

		bool getisAOE();
		bool getisConcentrate();

		void UpgradeMoveAttack();	// funtions to manage the player to
		void UpgradeAcc();			// power up the moves
		
		void loadAttack(double);
		void loadAccuracy(double);
		void loadAaA(double, double);
		void displayMoveDesc();
		void displayMoveHorizontally();
		
};
/*
class MoveSet{
	private:
		struct moveNode{
			Move move;
			moveNode *next;
			moveNode *back;
		};
		moveNode *first;
		moveNode *last;
	
	public:
		MoveSet();
		bool isFull();
		void addMove(Move);
};
*/
#endif