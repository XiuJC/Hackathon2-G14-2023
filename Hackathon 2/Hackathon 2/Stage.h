#pragma once
#include "Boss.h"
using namespace std;

//Stage class for saving the info of the stage.
class Stage
{
private:
	int index;
	string Stage_title;	//Stage title
	string Stage_desc;	//The description of cuurent Stage
	string Stage_ending;
	struct Wave {		//The wave state the monster info as a linked list in each stage.
		int WaveIndex{};
		int hasBoss{};
		int MonsterCount{};
		Enemy enemy[3];	//Maximum count of monster per wave = 3
		Boss boss;		//Maximum count of boss is one
		struct Wave* next = nullptr;
		Wave(){}
	};
	struct Wave* head;

public:
	Stage();
	Stage(int);
	~Stage();
	void loadStage(int);
	void loadStageAndWave(int, int);
	void displayStageDesc();
	void displayStageEnding();
	void appendWave(string);
	void searchWave(int);
	void displayAllWave();
	int getStageIndex();

	void TraverseWave(int&, Wave*&);
	bool WaveExist(int);
	bool WavehasBoss(int);
	void getMonsterCount(int,int& count);
	void copyWaveEnemy(int,Enemy[]);
	void copyWaveBoss(int, Boss&);

	void deleteWave(int);
	void destroyWave();
};
