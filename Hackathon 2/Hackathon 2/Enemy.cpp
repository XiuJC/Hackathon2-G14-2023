#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy() {
	EnemyType = " ";
	ATKdescription = " ";
	EmaxHealth = 0;
	EHealth = 0;
	Attack = 0;
	DamageTaken = 0;
}

Enemy::~Enemy() {
	EnemyType = " ";
	ATKdescription = " ";
	EmaxHealth = 0;
	EHealth = 0;
	Attack = 0;
	DamageTaken = 0;
}

Enemy :: Enemy(const string &type, const string &atkD, double MAXhealth, double atk){
	EnemyType = type;
	ATKdescription = atkD;
	EmaxHealth = MAXhealth;
	EHealth = MAXhealth;
	Attack = atk;
	DamageTaken = 0;
}

// copy constructor
Enemy :: Enemy(const Enemy &mon){
	EnemyType = mon.EnemyType;
	ATKdescription = mon.ATKdescription;
	EmaxHealth = mon.EmaxHealth;
	EHealth = mon.EHealth;
	Attack = mon.Attack;
}

const Enemy Enemy::operator=(const Enemy &right){
	if (this != &right) {
		EnemyType = right.EnemyType;
		ATKdescription = right.ATKdescription;
		EmaxHealth = right.EmaxHealth;
		EHealth = right.EHealth;
		Attack = right.Attack;
	}
	return *this;
}

// constructor called when defining Boss object
Enemy :: Enemy(double hp){
	EmaxHealth = hp;
	EHealth = hp;
	Attack = 0;
	DamageTaken = 0;
}

bool Enemy :: isDead(){
	if (EHealth <= 0) return true;
	else return false;
}

void Enemy :: Attacked(double damage, Dice &d){
	double BASE_DamageTakenratio = 0.0, ratio, BonusRatio=0;
	
	// non-boss enemies does not have damage resistance like player and bosses
	// instead it use a D6 dice to see if the damage is reduced of increased
	// there are each 6 out of 1 chance every single hit
	// for enemies to either have 50% damage reduction or 50% extra damage taken

	d.roll();
	switch (d.getValue()) {
		case 1:	BonusRatio = 0.5;
				break;
		case 2: case 3: case 4: case 5 : BonusRatio = 0;
										break;
		case 6: BonusRatio = -0.5;
	}
	
	ratio = BASE_DamageTakenratio + BonusRatio;
	
	DamageTaken = damage - (damage * ratio);
	
	EHealth -= DamageTaken;
}

void Enemy :: setEnemyType(string n){
	EnemyType = n;
}

void Enemy :: setATKdescription(string d){
	ATKdescription = d;
}

void Enemy :: setAttack(double atk){
	Attack = atk;
}

void Enemy :: setEmaxHealth(double maxHP){
	EmaxHealth = maxHP;
}

void Enemy :: setEHealth(double hp){
	EHealth = hp;
}

string Enemy :: getEnemyType() const{
	return EnemyType;
}

string Enemy :: getATKdescription() const{
	return ATKdescription;
}

double Enemy :: getAttack() {
	return Attack;
}

double Enemy :: getEmaxHealth() const{
	return EmaxHealth;
}

double Enemy :: getEHealth() const{
	return EHealth;
}

void Enemy::displayEnemyInfo() {
	cout << EnemyType << endl;
	cout << "HP: " << EHealth << "/" << EmaxHealth << endl;
}