#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
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

	void TraverseWave(int&, Wave*&);
	bool WavehasBoss(int);
	void getMonsterCount(int,int& count);
	void copyWaveEnemy(int,Enemy[]);
	void copyWaveBoss(int, Boss&);

	void deleteWave(int);
	void destroyWave();
};

Stage::Stage()
{
	head = nullptr;
	ifstream readStage;
	index = 1;
	readStage.open("Stage 1_desc.txt");
	readStage >> index;
	readStage.ignore();
	getline(readStage, Stage_title);
	getline(readStage, Stage_desc);
	getline(readStage, Stage_ending);
	readStage.close();


}
Stage::Stage(int ind) {
	loadStage(ind);
}

void Stage::loadStage(int ind)
{
	ifstream readStage;
	index = ind;
	string WaveFile;
	switch (index) {
	case 1:
		readStage.open("Stage 1_desc.txt");
		readStage >> index;
		readStage.ignore();
		getline(readStage, Stage_title);
		getline(readStage, Stage_desc);
		getline(readStage, Stage_ending);
		while (getline(readStage, WaveFile)) {
			appendWave(WaveFile);
		}
		readStage.close();
		break;
	case 2:
		readStage.open("Stage 2_desc.txt");
		readStage >> index;
		readStage.ignore();
		getline(readStage, Stage_title);
		getline(readStage, Stage_desc);
		getline(readStage, Stage_ending);
		while (getline(readStage, WaveFile)) {
			appendWave(WaveFile);
		}
		readStage.close();
		break;
	case 3:
		readStage.open("Stage 3_desc.txt");
		readStage >> index;
		readStage.ignore();
		getline(readStage, Stage_title);
		getline(readStage, Stage_desc);
		getline(readStage, Stage_ending);
		while (getline(readStage, WaveFile)) {
			appendWave(WaveFile);
		}
		readStage.close();
		break;
	case 4:
		readStage.open("Stage 4_desc.txt");
		readStage >> index;
		readStage.ignore();
		getline(readStage, Stage_title);
		getline(readStage, Stage_desc);
		getline(readStage, Stage_ending);
		while (getline(readStage, WaveFile)) {
			appendWave(WaveFile);
		}
		readStage.close();
		break;
	case 5:		//Boss Stage: Only 1 wave, 1 boss object.
		readStage.open("Stage 5_desc.txt");
		readStage >> index;
		readStage.ignore();
		getline(readStage, Stage_title);
		getline(readStage, Stage_desc);
		while (getline(readStage, WaveFile)) {
			appendWave(WaveFile);
		}
		readStage.close();
		break;
	default:
		cout << "No stage " << index << endl;
	}
}

void Stage::loadStageAndWave(int ind, int waveInd) {
	loadStage(ind);
	searchWave(waveInd);
}

void Stage::displayStageDesc() {
	cout << "Stage " << index << ": " << Stage_title << endl;;
	cout << Stage_desc << endl;
}

void Stage::displayStageEnding() {
	cout << Stage_ending << endl;
}


void Stage::appendWave(string WaveFile)
{
	ifstream readWave, readEnemy;

	Wave* newWave; // To point to a new wave
	Wave* wavePtr = nullptr; // To move through the stage

	// Allocate a new wave and store newWave there. 
	newWave = new Wave;
	readWave.open(WaveFile);
	if (!readWave.is_open()) {
		cout << WaveFile << ": Open failed" << endl;
		return;
	}
	readWave >> newWave->WaveIndex;
	//	cout << "newWave->WaveIndex: " << newWave->WaveIndex << endl;
	readWave >> newWave->hasBoss;
	//	cout << "newWave->hasBoss: " << newWave->hasBoss << endl;
	if (newWave->hasBoss == 0) {	//Normal wave
		readWave >> newWave->MonsterCount;
		//		cout << "newWave->MonsterCount: " << newWave->MonsterCount << endl;
		string EnemyFile;
		for (int i = 0; i < newWave->MonsterCount; i++) {
			readWave >> EnemyFile;
			//			cout << i << " " << EnemyFile << endl;
			readEnemy.open(EnemyFile);
			string type;
			int attack, health;	//Created variable for reading and saving into terminal.
			readEnemy >> type;	//***************NOT REAL FUNCTION FOR EMENY, RMB TO CHANGE
			newWave->enemy[i].setEnemyType(type);
			readEnemy >> attack;
			newWave->enemy[i].setAttack (attack);
			readEnemy >> health;
			newWave->enemy[i].setEmaxHealth(health);
			newWave->enemy[i].setEHealth(health);
			readEnemy.close();
		}
		readWave.close(); 		//Close the Wave file and move on to enemy file.
	}
	else if (newWave->hasBoss == 1) {
		string name;
		string desc; //Encounter different boss is the differnet storyline.
		double hp;
		string ending;
		if (index == 4) {
			readEnemy.open("Wyvern.txt");
			readEnemy >> name;//newWave->boss.BossName = name; 
			readEnemy.ignore();
			getline(readEnemy, desc); //newWave->boss.BossDescription = desc;
			readEnemy >> hp;
			newWave->boss.setBoss(name, desc, hp);
		//	cout << "Recorded Wyvern info\n" << endl;
			newWave->boss.displayBossInfo();
			readEnemy.close();
			return;
		}
	//	cout << "Appending wave: Index= 5.\n" << endl;
		Dice d20(20);
		d20.roll();
		int roll_result = d20.getValue(); 		//Killing differnet boss gives differnet ending
	//	cout << "roll_result = " << roll_result << endl;
		switch (roll_result) {
		case 16 : case 17: case 18: case 19: case 20:	//Faust
			cout << "IN FAUST\n" << endl;
			readEnemy.open("Faust.txt");
			readEnemy >> name;//newWave->boss.BossName = name; 
			readEnemy.ignore();
			getline(readEnemy, desc); //newWave->boss.BossDescription = desc;
			readEnemy >> hp;
			newWave->boss.setBoss(name, desc, hp);
			readEnemy >> ending;
			break;
		case 9 : case 10: case 11: case 12: case 13: case 14: case 15: 		//Baryard
		//	cout << "IN Baryard\n" << endl;
			readEnemy.open("Baryard.txt");
			readEnemy >> name;//newWave->boss.BossName = name; 
			readEnemy.ignore();
			getline(readEnemy, desc); //newWave->boss.BossDescription = desc;
			readEnemy >> hp;
			newWave->boss.setBoss(name, desc, hp);
			readEnemy >> ending;
			break;
		case 1 : case 2: case 3: case 4: case 5: case 6: case 7: case 8: 		//Lyanna
		//	cout << "IN Lyanna\n" << endl;
			readEnemy.open("Lyanna.txt");//**Later put the real boss function here.
			readEnemy >> name;//newWave->boss.BossName = name; 
			//cout << name << endl;
			readEnemy.ignore();
			getline(readEnemy, desc); //newWave->boss.BossDescription = desc;
			//cout << desc << endl;
			readEnemy >> hp;
			//cout << hp << endl;
			newWave->boss.setBoss(name, desc, hp);
			readEnemy >> ending;
			break;
		default:
			cout << "Dice error." << roll_result << endl;
		}
		readEnemy.close();
	}
	newWave->next = nullptr;

	// If there are no nodes in the list,make newNode the first node.
	if (!head)
		head = newWave;
	else // Otherwise, insert newNode at end. 
	{
		wavePtr = head;
		// Find the last node in the list. 
		while (wavePtr->next != nullptr) {
			wavePtr = wavePtr->next;
		}
		// Insert newNode as the last node.
		wavePtr->next = newWave;
	}
	
}

void Stage::searchWave(int waveindex)
{
	Wave* wavePtr; // To traverse 
	// If the list is empty, do nothing. 
	if (!head) {
		cout << "Stage is Empty\n";
		return;
	}
	// Determine if the first wave is the one.
	wavePtr = head;
	if (wavePtr->WaveIndex == waveindex){
		cout << "Wave " << wavePtr->WaveIndex << endl;
			if(!WavehasBoss(waveindex)){
				for (int i = 0; i < wavePtr->MonsterCount; i++) {
					head->enemy[i].displayEnemyInfo();
					this_thread::sleep_for(std::chrono::seconds(1));
					cout << endl;
				} 
			}
			else if(WavehasBoss(waveindex)) {
				head->boss.displayBossDescription();
				head->boss.displayBossInfo();
			}	//system("pause");
		return;
	}
	// Skip all waves whose index member is not equal to waveindex.
	while (wavePtr != NULL && wavePtr->WaveIndex != waveindex)
	{
		wavePtr = wavePtr->next;
	}
	if (wavePtr)
	{
		if (!WavehasBoss(waveindex)) {
			cout << "Wave " << wavePtr->WaveIndex << endl;
			for (int i = 0; i < head->MonsterCount; i++) {
				head->enemy[i].displayEnemyInfo();
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
		else if (WavehasBoss(waveindex)) {
			head->boss.displayBossDescription();
			head->boss.displayBossInfo();
		}
		return;
	}
	else
	{
		cout << "\nNot found\n";
		return;// system("pause");
	}
}

void Stage::displayAllWave() {
	Wave* waveptr;
	if (!head)
		cout << "The stage is empty." << endl;
	else {
		waveptr = head;

		while (waveptr != nullptr) {
			cout << "Wave " << waveptr->WaveIndex << endl;
			if (waveptr->hasBoss == 0) {
				for (int i = 0; i < waveptr->MonsterCount; i++) {
					waveptr->enemy[i].displayEnemyInfo();
					this_thread::sleep_for(std::chrono::seconds(2));
					cout << endl;
				}
			}
			else{
				waveptr->boss.displayEnemyInfo();
			}
			waveptr = waveptr->next;
		}

	}
}
void Stage::TraverseWave(int& windex, Wave*& wavePtr) {
	if (!head)
		cout << "No wave in stage." << endl;
	wavePtr = head;
	while (wavePtr != nullptr && wavePtr->WaveIndex != windex) {
		wavePtr = wavePtr->next;
	}
	if (wavePtr == nullptr) {
		cout << "No index of wave." << endl;
		return;
	}
}
//*****WARNING, THE FUNCTION BELOW MUST USE CURWAVE, THAT MEANS AFTER SEARCHWAVE(WAVEINDEX)
bool Stage::WavehasBoss(int windex) {
	bool status = false;
	Wave* wavePtr;
	TraverseWave(windex, wavePtr);
	if (wavePtr == nullptr) {
		cout << "No index" << endl;
	}
	else if (wavePtr != nullptr) {
		if (wavePtr->hasBoss == 0)
			status = false;
		else if(wavePtr->hasBoss == 1)
			status = true;
	}
	return status;
}

void Stage::getMonsterCount(int windex, int& count) {
	Wave* wavePtr;
	TraverseWave(windex, wavePtr);
	if (wavePtr == nullptr) {
		cout << "No index" << endl;
	}
	else if (wavePtr != nullptr) {
		count = wavePtr->MonsterCount;
	}
}

void Stage::copyWaveEnemy(int waveindex, Enemy copyEnemy[3]) {
	Wave* wavePtr;
	TraverseWave(waveindex, wavePtr);
	if (wavePtr == nullptr) {
		cout << "No index" << endl;
	}
	else if (wavePtr != nullptr) {
		if (!WavehasBoss(waveindex) ){
			for (int i = 0; i < wavePtr->MonsterCount; i++) {
				copyEnemy[i] = wavePtr->enemy[i];
			}
		}
	}
}

void Stage::copyWaveBoss(int waveindex,Boss & copyBoss) {
	Wave* wavePtr;
	TraverseWave(waveindex, wavePtr);
	if (wavePtr == nullptr) {
		cout << "No index" << endl;
	}
	else if (wavePtr != nullptr) {
		if (WavehasBoss(waveindex)) {
			copyBoss = wavePtr->boss;
		}
	}
}
//**********DESTROY
/*void Stage::deleteWave(int waveindex) {
	Wave* wavePtr = nullptr;
	Wave* prevWave = nullptr;

	if (!head)
		cout << "deleteWave: The stage is empty. " << endl;
	else {
		wavePtr = head;
		if (head->WaveIndex == waveindex) {
			head = wavePtr->next;
			delete wavePtr;
			return;
		}
		while(wavePtr->WaveIndex != waveindex) {
			prevWave = wavePtr;
			wavePtr =wavePtr->next;
		}
		if (wavePtr->WaveIndex == waveindex) {
			prevWave->next = wavePtr->next;
			delete wavePtr;
		}
		else {
			cout << "deleteWave: No wave index" << waveindex << " in this list." << endl;
		}
	}
}*/

void Stage::destroyWave() {
	if (!head)
		return;
	Wave* wavePtr = head;
	Wave* temp;
	wavePtr = nullptr;
	temp = nullptr;

		while (wavePtr) {
			temp = wavePtr->next;
			delete wavePtr;
			wavePtr = temp;

		}

		delete wavePtr;
}

Stage::~Stage()
{
}

//Stage[5]