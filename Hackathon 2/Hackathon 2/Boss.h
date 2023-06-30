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
		string BossEnding;

	public:
		Boss(): Enemy() { BossName = " "; BossDescription = " "; }
		Boss(const string&, const string&, double);
		Boss& operator=(const Boss& right) {
			if (this != &right) {
				BossName = right.BossName;
				BossDescription = right.BossDescription;
				this->setEHealth(right.Enemy::getEHealth());
				this->setEmaxHealth(right.Enemy::getEmaxHealth());
				this->BossEnding = right.BossEnding;
			}
			return *this;
		}
		void BossAttacked(double, double);	//
		string getBossName();
		void displayBossDescription();
		void setBossInfo(string, string, double);
		void setBossEnding(string);
		void setBoss(string, string, double, string);
		bool RAGE();					// boss' status, will triggered when HP lower than 
										// half of maximum HP, gaining all moves double attack
		void displayBossInfo();
		void displayBossEnding();
};

#endif
