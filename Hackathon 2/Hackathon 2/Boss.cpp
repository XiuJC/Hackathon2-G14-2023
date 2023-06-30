#include "Boss.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

Boss :: Boss(const string &bossname, const string &d, double hp) : Enemy(hp){
	BossName = bossname;
	BossDescription = d;
}

/*Boss& Boss::operator=(const Boss& right) {
	if (this != &right) {
		BossName = right.BossName;
		BossDescription = right.BossDescription;
		this->setEHealth(right.getEHealth());
		this->setEmaxHealth(right.getEmaxHealth());
	}
	return *this;
}
*/
void Boss :: BossAttacked(double damage, double d){
	double BASE_DamageTakenratio = 0.5, ratio, BonusRatio = 0;
	
	// Damage resistance similar to player's

	int temp = static_cast<int>(d);

	switch (temp) {
		case 20:	BonusRatio = -0.5;
					break;
		case 11: case 12: case 13: case 14: case 15: 
		case 16: case 17: case 18: case 19 : BonusRatio = 0;
											break;
		case 2: case 3: case 4: case 5: case 6:
		case 7: case 8: case 9: case 10: BonusRatio = 0.25;
										break;
		case 1:BonusRatio = 0.5;
				break;
		default:
			break;
	}
	ratio = BASE_DamageTakenratio + BonusRatio;
	
	// bosses will have damage resistance similar to player
	// with the condition HP over half
	if (EHealth >= (EmaxHealth / 2)){
		DamageTaken = damage - (damage * ratio);
	}
	else{
		DamageTaken = damage;
	}
	
	EHealth -= DamageTaken;
	
}

string Boss :: getBossName() {
	return BossName;
}

void Boss::displayBossDescription() {
	cout << BossDescription << endl;
}

void Boss::setBossInfo(string bossname, string d, double hp){
	BossName = bossname;
	BossDescription = d;
	EmaxHealth = hp;
	EHealth = hp;	
}

void Boss::setBossEnding(string filename){ //To read (Boss).txt
	BossEnding = filename;
}
void Boss::setBoss(string bossname, string d, double hp, string filename) {
	setBossInfo(bossname, d, hp);
	setBossEnding(filename);
}

bool Boss :: RAGE() {
	if (EHealth < (EmaxHealth / 2)) return true;	// bosses will enter rage status 
	else return false;								// when HP goes half.
}

void Boss::displayBossInfo(){
	cout << BossName << endl;
	double currentHP = Enemy::getEHealth();
	double totalHP = Enemy::getEmaxHealth();
	cout << "HP: " << currentHP << "/" << totalHP << endl;
}

void Boss::displayBossEnding(){
	ifstream readBE;
	string line;
	readBE.open(BossEnding);
	while (getline(readBE, line)) {
		cout << line << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
	}
	readBE.close();
	
}
void Boss::displayBossInfo(){
	cout << BossName << endl;
	double currentHP = Enemy::getEHealth();
	double totalHP = Enemy::getEmaxHealth();
	cout << "HP: " << currentHP << "/" << totalHP << endl;
}
