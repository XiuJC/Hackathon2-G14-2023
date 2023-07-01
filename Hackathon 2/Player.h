#ifndef PLAYER_H
#define PLAYER_H
#include "Dice.h"

using namespace std;

class Player{
	private:
		double Health;			// record the player's current HP
		double MAX_Health;		// player's starting HP, can be increased
		double ShieldDura;		// Shield durability. A shield can help to reduce the
								// incoming damage from enemies and bosses.
		double DamageTaken;		// the actual damage taken from attacks
		bool Concentrated;		// status of player affected by his own move
		
	public:
		Player();
		void loadPlayerInfo(double, double, double);
		void PlayerAttacked(double, double);	// function to calculate actual damage taken and 
									// changes in HP

		void Cursed();				// function to update HP when cursed
		void Heal();
		void HealHalf();
		void plusMAXHealth();
		bool isDead();

		void repairShield();
		bool hasShield();

		void setConcentrated(bool);
		bool getConcentrated();

		double getHealth();
		double getMAX_Health();

		double getShieldDura();
		double getDamageTaken();

		void displayHP();
		void displayPlayerInfo();
}; 

#endif