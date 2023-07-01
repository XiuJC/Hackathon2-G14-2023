#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "Stage.h"
using namespace std;


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
		readStage.open("Stage1.txt");
		break;
	case 2:
		readStage.open("Stage2.txt");
		break;
	case 3:
		readStage.open("Stage3.txt");
		break;
	case 4:
		readStage.open("Stage4.txt");
		break;
	case 5:		//Boss Stage: Only 1 wave, 1 boss object.
		readStage.open("Stage5.txt");
		break;
	default:
		cout << "No stage " << index << endl;
		return;
	}

	readStage >> index;
	readStage.ignore();
	getline(readStage, Stage_title); //cout << "getline(readStage, Stage_title);" << endl;
	getline(readStage, Stage_desc); //cout << "getline(readStage, Stage_desc);" << endl;
	getline(readStage, Stage_ending); //cout << "getline(readStage, Stage_ending)" << endl;
	while (getline(readStage, WaveFile)) {
		appendWave(WaveFile);	//cout << "appendWave(WaveFile);" << endl;
	}
	readStage.close();
}

void Stage::loadStageAndWave(int ind, int waveInd) {
	loadStage(ind);
	searchWave(waveInd);
}

void Stage::displayStageDesc() {
	cout << "                        Stage " << index << ": " << Stage_title << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	ifstream read;
	string line;
	read.open(Stage_desc);
	while (getline(read, line)) {
		cout << line << endl;
		this_thread::sleep_for(std::chrono::seconds(2));
	}
}

void Stage::displayStageEnding() {
	ifstream read;
	string line;
	read.open(Stage_ending);
	while (getline(read, line)) {
		cout << line << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
	}
}


void Stage::appendWave(string WaveFile)
{
	ifstream readWave, readEnemy;

	Wave* newWave; // To point to a new wave
	Wave* wavePtr = nullptr; // To move through the stage

	// Allocate a new wave and store newWave there. 
	newWave = new Wave;
	readWave.open(WaveFile);
	//cout << "readWave.open(" << WaveFile << "); " << endl;//**test
	if (!readWave.is_open()) {
		cout << WaveFile << ": Open failed" << endl;
		return;
	}
	readWave >> newWave->WaveIndex;
	//	cout << "newWave->WaveIndex: " << newWave->WaveIndex << endl; //**
	readWave >> newWave->hasBoss;
	//	cout << "newWave->hasBoss: " << newWave->hasBoss << endl; //**
	if (newWave->hasBoss == 0) {	//Normal wave
		readWave >> newWave->MonsterCount;
		//		cout << "newWave->MonsterCount: " << newWave->MonsterCount << endl;//**test
		string EnemyFile;
		for (int i = 0; i < newWave->MonsterCount; i++) {
			readWave >> EnemyFile;
			//cout << EnemyFile << endl; //**
			readEnemy.open(EnemyFile);
			string type;
			int attack, health;	//Created variable for reading and saving into terminal.
			readEnemy >> type;
			newWave->enemy[i].setEnemyType(type);
			//cout << "newWave->enemy[i].setEnemyType(type); " << type << endl; //**
			readEnemy >> attack;
			newWave->enemy[i].setAttack(attack);
			//cout << "newWave->enemy[i].setAttack (attack);" << attack << endl; //**
			readEnemy >> health;
			newWave->enemy[i].setEmaxHealth(health);
			newWave->enemy[i].setEHealth(health);
			//cout << "Lealth " << health << endl; //**
			readEnemy.close();
		}
		readWave.close();
	}
	//Boss Wave
	else if (newWave->hasBoss == 1) {
		readWave.close();
		string name;
		string desc; //Encounter different boss has the differnet storyline.
		string ending;
		double hp;
		if (index == 4) {
			//	cout << "In Wyvern\n"; //**
			readEnemy.open("Wyvern.txt");
			readEnemy >> name;
			readEnemy.ignore();
			getline(readEnemy, desc);
			readEnemy >> hp;
			readEnemy >> ending;
			newWave->boss.setBoss(name, desc, hp, ending);
		}
		else {
			Dice d20(20);
			d20.roll();
			int roll_result = d20.getValue(); 		//Killing differnet boss gives differnet ending
			//	cout << "roll_result = " << roll_result << endl;
			switch (roll_result) {
			case 16: case 17: case 18: case 19: case 20:	//Faust chance
				//		cout << "IN FAUST\n" << endl;	//**
				readEnemy.open("Faust.txt");
				readEnemy >> name;
				readEnemy.ignore();
				getline(readEnemy, desc);
				readEnemy >> hp;
				readEnemy >> ending;
				newWave->boss.setBoss(name, desc, hp, ending);
				break;
			case 9: case 10: case 11: case 12: case 13: case 14: case 15: 		//Baryard chance
				//		cout << "IN Baryard\n" << endl;	//**
				readEnemy.open("Baryard.txt");
				readEnemy >> name;
				readEnemy.ignore();
				getline(readEnemy, desc);
				readEnemy >> hp;
				readEnemy >> ending;
				newWave->boss.setBoss(name, desc, hp, ending);
				break;
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: 	//Lyanna chance
				//		cout << "IN Lyanna\n" << endl;	//**
				readEnemy.open("Lyanna.txt");
				readEnemy >> name;
				readEnemy.ignore();
				getline(readEnemy, desc);
				readEnemy >> hp;
				readEnemy >> ending;
				newWave->boss.setBoss(name, desc, hp, ending);
				break;
			default:
				break;
			}
		}
		//  newWave->boss.displayBossDescription();	//**
		// newWave->boss.displayBossInfo();		//**
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
	//cout << "Wave Index: " << waveindex << endl; //**
	// Determine if the first wave is the one.
	wavePtr = head;
	if (wavePtr->WaveIndex == waveindex) {
		cout << "-----Wave " << wavePtr->WaveIndex << "-----" << endl << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		if (!WavehasBoss(waveindex)) {
			for (int i = 0; i < wavePtr->MonsterCount; i++) {
				cout << "Enemy " << i + 1 << ":" << endl;
				wavePtr->enemy[i].displayEnemyInfo();
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << endl;
			}
		}
		else if (WavehasBoss(waveindex)) {
			cout << "-----BOSS WAVE-----" << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			wavePtr->boss.displayBossDescription();
			cout << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			wavePtr->boss.displayBossInfo();
		}
		return;
	}
	// Skip all waves whose index member is not equal to waveindex.
	while (wavePtr != NULL && wavePtr->WaveIndex != waveindex)
	{
		//cout << wavePtr->WaveIndex << " " <<  wavePtr->hasBoss << endl; //**
		wavePtr = wavePtr->next;
	}
	if (wavePtr)
	{
		if (!WavehasBoss(waveindex)) {
			cout << "-----Wave " << wavePtr->WaveIndex << "-----" << endl << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			for (int i = 0; i < wavePtr->MonsterCount; i++) {
				cout << "Enemy " << i + 1 << ":" << endl;
				wavePtr->enemy[i].displayEnemyInfo();
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << endl;
			}
		}
		else if (WavehasBoss(waveindex)) {
			cout << "-----BOSS WAVE-----" << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			wavePtr->boss.displayBossDescription();
			cout << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			wavePtr->boss.displayBossInfo();
		}
		return;
	}
	else
	{
		cout << "\nNot found\n";
		return;
	}
}

void Stage::displayAllWave() {
	Wave* waveptr;
	if (!head)
		cout << "The stage is empty." << endl;
	else {
		waveptr = head;

		while (waveptr != nullptr) {

			this_thread::sleep_for(std::chrono::seconds(1));
			if (!waveptr->hasBoss) {
			cout << "-----Wave " << waveptr->WaveIndex << "-----" << endl << endl;
				for (int i = 0; i < waveptr->MonsterCount; i++) {
					cout << "Enemy " << i + 1 << ":" << endl;
					waveptr->enemy[i].displayEnemyInfo();
					this_thread::sleep_for(std::chrono::seconds(1));
					cout << endl;
				}
			}
			else if (waveptr->hasBoss) {
				cout << "-----BOSS WAVE-----" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				waveptr->boss.displayBossDescription();
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << endl;
				waveptr->boss.displayBossInfo();
			}

			waveptr = waveptr->next;
		}

	}
}

int Stage::getStageIndex() {
	return index;
}

void Stage::TraverseWave(int& windex, Wave*& wavePtr) {
	if (!head)
		cout << "No wave in stage." << endl;
	wavePtr = head;
	while (wavePtr != nullptr && wavePtr->WaveIndex != windex) {
		wavePtr = wavePtr->next;
	}
	if (wavePtr == nullptr) {
		return;
	}
}

bool Stage::WaveExist(int waveindex) {
	Wave* wavePtr;
	bool status = true;
	TraverseWave(waveindex, wavePtr);
	if (wavePtr == nullptr) {
		status = false;
	}
	return status;
}

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
		else if (wavePtr->hasBoss == 1)
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

void Stage::copyWaveEnemy(int waveindex, Enemy copyEnemy[]) {
	Wave* wavePtr;
	TraverseWave(waveindex, wavePtr);
	if (wavePtr == nullptr) {
		cout << "No index" << endl;
	}
	else if (wavePtr != nullptr) {
		if (!WavehasBoss(waveindex)) {
			for (int i = 0; i < wavePtr->MonsterCount; i++) {
				copyEnemy[i] = wavePtr->enemy[i];
			}
		}
	}
}

void Stage::copyWaveBoss(int waveindex, Boss& copyBoss) {
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
	destroyWave();
}
