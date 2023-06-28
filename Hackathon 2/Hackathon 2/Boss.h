#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include "Dice.h"
using namespace std;
// Boss is a derived class from Enemy

class Boss: public Enemy{
	private:
		string BossName;
		string BossDescription;
		
	public:
		Boss(): Enemy() { BossName = " "; BossDescription = " "; }
		Boss(const string&, const string&, double);
		Boss& operator=(const Boss& right) {
			if (this != &right) {
				BossName = right.BossName;
				BossDescription = right.BossDescription;
				this->setEHealth(right.Enemy::getEHealth());
				this->setEmaxHealth(right.Enemy::getEmaxHealth());
			}
			return *this;
		}//;
		void BossAttacked(double, Dice&);	//
		string getBossName();
		void displayBossDescription();
		void setBoss(string, string, double);
		bool RAGE();					// boss' status, will triggered when HP lower than 
										// half of maximum HP, gaining all moves double attack
		void displayBossInfo();
};

#endif