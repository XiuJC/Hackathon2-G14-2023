#include "Moveset.h"
#include <iostream>
#include <iomanip>
using namespace std;

// define all the member variables of a move

Move::Move() {
	MoveName = " ";
	Description = " ";
	AttackValue = 10;
	AccuracyRate = 1;
	isAOE = false;
	isConcentrate = false;
}

Move::~Move() {
	MoveName = " ";
	Description = " ";
	AttackValue = 10;
	AccuracyRate = 1;
	isAOE = false;
	isConcentrate = false;
}

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
	AttackValue += 5;
}

void Move :: UpgradeAcc(){
	AccuracyRate += 0.05;
}

void Move::displayMoveDesc(){
	cout << Description << endl;
}

void Move::displayMoveHorizontally() {
	cout << MoveName << "      " << setw(6);
	if (!isConcentrate) {
		cout << "DMG: " << AttackValue << " Accuracy: " << AccuracyRate << " ";
		if (isAOE)
			cout << "      " << "Special: Area Damage" << endl;
		else
			cout << endl;
	}
	if (isConcentrate)
		cout << "Special: Boosts you next round." << endl;
		
}

void Move::loadAttack(double val) {
	AttackValue = val;
}

void Move::loadAccuracy(double val) {
	AccuracyRate = val;
}

void Move::loadAaA(double val1, double val2) {
	loadAttack(val1);
	loadAccuracy(val2);
}
