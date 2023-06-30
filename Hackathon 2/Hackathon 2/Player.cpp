#include "Player.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

Player :: Player(){
	// initializing the base health and shield durability of the player
	MAX_Health = 300; 
	Health = 300;
	ShieldDura = 75;
	DamageTaken = 0;
	Concentrated = false;
}

void Player :: Attacked(double damage, double d){
	double BASE_DamageTakenratio = 0.5, ratio, BonusRatio = 0;
	
	// A shield creates damage resistance automatically whenever player is attacked.
	// A D20 is rolled to see if the player manage to guard the attack.

	int temp = static_cast<int>(d);

	switch (temp) {
		case 1:	BonusRatio = -0.5;			// if the dice rolled 1, player failed to 
				break;						// guard and take the whole damage/
		case 2: case 3: case 4: case 5: case 6:
		case 7: case 8: case 9: case 10: BonusRatio = 0;
										break;		
		case 11: case 12: case 13: case 14: case 15: 
		case 16: case 17: case 18: case 19 : BonusRatio = 0.25;
											break;
		case 20:BonusRatio = 0.5;			// if the dice rolled 20, the player guarded
				break;						// successfully and take no damage.
	}
	// CJX: why dont just if d = 20, damage = 0, then else if hasShield true, do the above without ratio complicating things.
	// Then if no Shield then take damage
	ratio = BASE_DamageTakenratio + BonusRatio;

	if (hasShield() == true){
		DamageTaken = damage - (damage * ratio);
		ShieldDura--;						// Shield durability loses 1 for every defend.
	}
	else if (hasShield() == false && d == 20){
		DamageTaken = 0;					// even if the player lose the shield
											// he can still have a chance to dodge attacks
	}
	else {
		DamageTaken = damage;
	}
	cout << " deals " << DamageTaken << " damage to you." << endl;
	Health = Health - DamageTaken;			// update the player's health
	
}

void Player :: Cursed(){					// a Curse is a boss' move that deals true damage
	Health = Health - (MAX_Health / 10);	// equals to 10% of player's max Health.
}

void Player :: Heal(){						// player will heal himself in certain condition.
	Health += (MAX_Health / 10);
	if (Health > MAX_Health) {
		Health = MAX_Health;
	}
}

void Player :: HealHalf(){					// player will fully recover from damage in
	Health += (MAX_Health / 2);				// certain condition.
	if (Health > MAX_Health) Health = MAX_Health;					
}

void Player :: plusMAXHealth(){
	MAX_Health += 25;						// at the end of every stage, player's max_Health
	Health += 25;							// will increase as a sign of leveling up
}

void Player :: repairShield(){	// in certain condition, player may repair the 
	ShieldDura += 15;		// shield, extend its durability
}

bool Player :: isDead(){					// a Boolean function to determine if the player
	if (Health <= 0) return true;			// is dead
	else return false;
}

bool Player :: hasShield(){					// a Boolean function to determine if the player
	if(ShieldDura >= 1) return true;			// has damage resistance
	else return false;
}

void Player :: setConcentrated(bool c){
	Concentrated = c;
}

bool Player :: getConcentrated(){
	return Concentrated;
}

double Player :: getHealth(){
	return Health;
}

double Player :: getMAX_Health(){
	return MAX_Health;
}

double Player :: getShieldDura(){
	return ShieldDura;
}

double Player :: getDamageTaken(){
	return DamageTaken;
}

void Player::displayHP(){
	cout << "OZEN HP: " << Health << "/" << MAX_Health << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
}

void Player::loadPlayerInfo(double hp, double maxhp, double durability) {
	Health = hp;
	MAX_Health = maxhp;
	ShieldDura = durability;
}

void Player::displayPlayerInfo() {
			cout << "HP: " << Health << "/" << MAX_Health << "\tShield Durability: " << ShieldDura << endl;
}
