#ifndef BOSSMOVE_H
#define BOSSMOVE_H
#include "MoveSet.h"
using namespace std;

class BossMove : public Move {
	private:
		bool isCurse;
		double Base_AttackValue;
		
	public:
		BossMove();
		~BossMove();
		BossMove(const string&, const string&, double, bool);
		//****
		double getBaseDmg();
		bool getisCurse();
		void inRage();
		bool rageBoosted();
		void displayBossATKed();
		BossMove& operator=(const BossMove& right) {
			if (this != &right) {
				MoveName = right.MoveName;
				Description = right.Description;
				this->Base_AttackValue = right.Base_AttackValue;
				this->AttackValue = right.AttackValue; \
					this->isCurse = right.isCurse;
			}
			return *this;
		}
};

#endif