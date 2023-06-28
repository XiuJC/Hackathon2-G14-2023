#include "MoveSet.h"
#include "BossMove.h"

using namespace std;

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