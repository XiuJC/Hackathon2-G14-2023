#ifndef ENEMY_H
#define ENEMY_H
#include "Dice.h"
#include <string>
using namespace std;

/*	attacking function might not be included in this class...  
	still thinking what it can do in combat  
	maybe just move it to combat class if it interacts with player*/

class Enemy{
	private:
		string EnemyType;		// define the monster type of each enemy object
		string ATKdescription;	// the description telling how the enemy attacks player
		double Attack;			// enemy doesn't have move, so they own a fixed attack value
		
	protected:
		double EHealth;			// enemy's HP
		double EmaxHealth;		// starting HP of the enemies and bosses
		double DamageTaken;		// calculates how much actual damage taken from player's attack
		
	public:
		Enemy();
		~Enemy();
		Enemy(const string&, const string&, double, double);
		Enemy(const Enemy&);							// Copy constructor
		const Enemy operator=(const Enemy&);
		Enemy(double);										// overloading constructor passing
														// protected member (EHealth)
														// to Boss class
		bool isDead();
		void setisDead();
		void EnemyAttacked(double, double);
		void setEnemyType(string);
		void setATKdescription(string);
		void setAttack(double);
		void setEmaxHealth(double);
		void setEHealth(double);
		string getEnemyType() const;
		string getATKdescription() const;
		double getAttack();
		double getEmaxHealth() const;
		double getEHealth() const;
		void displayEHp();
		void displayEnemyInfo();		// member function to display enemy info in battle
		void displayATKdesc();
};

#endif