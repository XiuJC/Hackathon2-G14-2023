#include "BossMove.h"
#include <iostream>
using namespace std;

BossMove::BossMove(): Move() {
	MoveName = " ";
	Description = " ";
	Base_AttackValue = 10;
	AttackValue = 10;
	isCurse = true;
}

BossMove::~BossMove() {
	MoveName = " ";
	Description = " ";
	Base_AttackValue = 10;
	AttackValue = 10;
	isCurse = true;
}
BossMove :: BossMove(const string &name, const string &d, double attack, bool curse) : Move(name, d, attack){
	MoveName = name;
	Description = d;
	Base_AttackValue = attack;
	AttackValue = attack;
	isCurse = curse;
}

bool BossMove :: getisCurse(){
	return isCurse;
}

void BossMove :: inRage(){
	AttackValue = AttackValue * 2;
}

bool BossMove :: rageBoosted(){
	if (AttackValue > Base_AttackValue) return true;
	else return false;
}

void BossMove::displayBossATKed(){
	cout << Description << endl;
}
