#ifndef BOSSMOVE_H
#define BOSSMOVE_H
using namespace std;

class BossMove : public Move {
	private:
		bool isCurse;
		double Base_AttackValue;
		
	public:
		BossMove(const string&, const string&, double, bool);
		bool getisCurse();
		void inRage();
		bool rageBoosted();
		
};

#endif