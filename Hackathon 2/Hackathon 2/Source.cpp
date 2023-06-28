#include "Stage.h"
#include "Player.h"
#include "MoveSet.h"
#include "WriteFile.h"
using namespace std;

// Function to record the stage and wave index;
void recordStageAndWave(int&, int&);
// REST function 
// runs at the end of every stage to power up player as leveling up feature
void rest(Player&, Move&, Move&, Move&, int&);

// Function to save the player's progress
void saveProgress(int dwarfHP, int stageNumber, int waveNumber) {
	ofstream saveFile("progress.txt");

	if (saveFile.is_open()) {
		saveFile << dwarfHP << " " << stageNumber << " " << waveNumber;
		saveFile.close();
		cout << "Progress saved successfully!" << endl;
	}
	else {
		cout << "Unable to save progress. Please try again." << endl;
	}
}
// Function to load the player's progress
void loadProgress(int& dwarfHP, int& monsterHP, int& stageNumber, int& waveNumber) {
	ifstream saveFile("progress.txt");

	if (saveFile.is_open()) {
		saveFile >> dwarfHP >> monsterHP >> stageNumber >> waveNumber;
		saveFile.close();
		cout << "Progress loaded successfully!" << endl;
	}
	else {
		cout << "No saved progress found." << endl;
	}
}

void readFile(string fileName) {
	ifstream read;
	string line;
	read.open(fileName);
	while (getline(read,line)) {
		cout << line << endl;
//		this_thread::sleep_for(std::chrono::seconds(2));
	}
	read.close();
}

//MAINNNNNNNNNNNNNNN
int main()
{
	storeFile();
	system("cls");
	//Start
	char play_choice;
	readFile("Title.txt");

	//Choose to play or continue playing if have saved data file.
	cout << "New game(n) \t\t Continue(c) \t\t Quit(q)" << endl;
	string prologue; //For first play use
	int play_choice_record = 0;
	int StageIndex = 1;
	int WaveIndex = 1;

	while (!play_choice_record) {	
		cin >> play_choice;
		switch (play_choice) {
		case 'n': case 'N': //A new play
			//Print the prologue
			readFile("Prologue.txt");
			play_choice_record = 1;
			break;
		case 'c': case 'C':
	//		loadData("SavedData.txt"); //Not yet implant
			play_choice_record = 2;
			break;
		case 'q': case 'Q':
			cout << "You have quit the game." << endl;
			return 0;
		default:
			cout << "Choose p or c only" << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < 20; i++)
		cout << "*";
	cout << endl << endl;
	//Pre-battle stage
	Enemy enemy[3];
	Boss boss;
	Stage stage[5];
	if (play_choice_record == 1) {
		StageIndex = 1;
		WaveIndex = 1;
		stage[StageIndex].loadStage(1);
		stage[StageIndex].displayStageDesc();
		cout << endl;
		stage[StageIndex].searchWave(WaveIndex);
	} //New game
	else if (play_choice_record == 2) {
		StageIndex = 3;
		WaveIndex = 2;
		stage[StageIndex].loadStageAndWave(StageIndex, WaveIndex);
	}
	this_thread::sleep_for(std::chrono::seconds(2));
	
	string bossname = "baby";
	Boss boss(bossname, bossname, 10000);
	boss.displayBossDescription();
	boss.displayBossInfo();
}


void rest(Player &p, Move &m1, Move &m2, Move &m3, int& stageIndex) {
	p.plusMAXHealth();
	m1.UpgradeMoveAttack();
	m1.UpgradeAcc();
	m2.UpgradeMoveAttack();
	m2.UpgradeAcc();
	m3.UpgradeMoveAttack();
	m3.UpgradeAcc();
	
	char choice;
	bool invalid =false;
	
	cout << "This is a rest phase. " << endl;
	cout << "Your max HP has been increased and your moves are now stronger. " << endl;
	p.displayHP();
	cout << "Now, you can choose either one between these options: " << endl;
	cout << "1. Repair my shield. I think I can do it myself." << endl;
	cout << "2. Take a nap. I've already too tired." << endl;
	cout << "Enter 1 or 2 to select." << endl;
	
	do {
		cin >> choice;
	
		switch (choice){
			case '1': p.repairShield();
					cout << "You have repaired the shield yourself. " << endl;
					cout <<  "The result is not as good as the pro-BlackSmith but it is still better than none." << endl;
					cout << "Shield durability: " << p.getShieldDura() << endl;
					invalid= false;
					break;
			case '2': p.HealHalf();
					cout << "ZZZ......" << endl;
					cout << "Awake from nap, you are now filled with DETERMINATION." << endl;
					p.displayHP();
					invalid= false;
					break;
			default: cout << "invalid input. Try again." << endl;
					invalid = true;
		} 
		cin.ignore();
		cin.clear();
		
	} while (invalid);
	stageIndex++;
}

void recordStageAndWave(int& stageIndex, int& waveIndex) {

}
     
