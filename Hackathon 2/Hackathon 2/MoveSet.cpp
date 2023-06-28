#include "Moveset.h"

using namespace std;

// define all the member variables of a move

Move :: Move(const string &name, const string &d, double attack, double accRate, bool tf, bool c){
	MoveName = name;
	Description = d;
	AttackValue = attack;
	AccuracyRate = accRate;
	isAOE = tf;
	isConcentrate = c;
}

//	only the protected variables will be inherited to BossMove class 

Move :: Move(const string &name, const string &d, double attack){
	MoveName = name;
	Description = d;
	AttackValue = attack;
}

string Move :: getName() const{
	return MoveName;
}

string Move :: getDescription() const{
	return Description;
}

double Move :: getAttack(){
	return AttackValue;
}

double Move :: getAccuracy(){
	return AccuracyRate;
}

bool Move :: getisAOE(){
	return isAOE;
}

bool Move :: getisConcentrate(){
	return isConcentrate;
}

// player can power up the damaging moves in the end of a stage as a leveling up feature.

void Move :: UpgradeMoveAttack(){
	AttackValue += 15;
}

void Move :: UpgradeAcc(){
	AccuracyRate += 0.1;
}
/*
MoveSet :: MoveSet(){
	first = nullptr;
	last = nullptr;
}

bool MoveSet :: isFull(){
	int MoveCount = 0;
	moveNode* movePtr;
	
	MovePtr = first;
	
	while (MoveCount < 4 && MovePtr){
		MovePtr = MovePtr->next;
		MoveCount++;
	}
	
	if (MoveCount == 4) return true;
	else return false;
}

void MoveSet :: addMove(Move m){
	moveNode* newMove;
	moveNode* movePtr;
	
	newMove = new moveNode;
	newMove->move = m;
	newMove->next = nullptr;
	
	if (!first) {
		first = newMove;
		last = newMove;
	}
	if else (first && !isFull()) {
		movePtr = last;
		
		movePtr->next = newMove;
		last = newMove;
		newMove->back = movePtr;
	}
}
*/