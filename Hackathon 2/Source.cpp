#include "Stage.h"
#include "Player.h"
#include "BossMove.h"
#include "WriteFile.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
// Function to record the stage and wave index;
void checkStageAndWave(int&, int&);
// Display the Winner Board.
void displayWinnerBoard();
// function allowing dices to goes into more functions below as a RNG
double rollD6();
double rollD20();

// REST function 
// runs at the end of every stage to power up player as leveling up feature
void rest(Player&, Move&, Move&, Move&);

// function to process battle between player and non-boss Enemies
bool battleEnemy(Stage, int, Player&, Move&, Move&, Move&, Move&, bool&);

// function to process battle between player and Bosses
bool battleBoss(Boss&, Move&, Move&, Move&, Move&, Player&, BossMove&, BossMove&, BossMove&, bool&);

// these two functions work together to process Boss' turn to attack
// 'BossAction' decide which BossMove will be use with a D20 dice.
// then the BossMove selected is passed to 'BossAttacking', to do the rest stuff.
void BossAction(Boss&, Player&, BossMove&, BossMove&, BossMove&);
void BossAttacking(Boss&, BossMove&, Player&);

// function to process Player's attack against bosses
// using the move where the player had chose in 'battleBoss'
void PlayerAttackingBoss(Player&, Move&, Boss&);

// if player choose to use a single-target move against a wave of enemy,
// these function will ask player to enter choose a target and call 'PlayerAttackingEnemy' to do the rest.
void Choose2Target(Player&, Move&, Enemy&, Enemy&);
void Choose2Target(Player&, Move&, Enemy&, Enemy&, Enemy&);
void Choose3Target(Player&, Move&, Enemy&, Enemy&, Enemy&);

// function to process Player's attack against enemies
void PlayerAttackingEnemy(Player&, Move&, Enemy&);

// function to process Enemy's attack against player
void EnemyAttacking(Enemy&, Player&);

// function to determine if player's move successfully lands 
// based on dice and the move's own accuracy Rate
bool isATKhit(Player&, Move&);

//****
void showbossdmg(BossMove& bossmove) {
	cout << bossmove.getAttack() << " " << bossmove.getBaseDmg();
}

// Function to save the player's progress
void saveProgress(double dwarfHP, double dwarfmaxHP, double durability, int stageNumber,
	int waveNumber, double m1dmg, double m2dmg, double m3dmg, double m1acc, double m2acc, double m3acc) {
	ofstream saveFile("progress.txt");


	if (saveFile.is_open()) {
		saveFile << dwarfHP << " " << dwarfmaxHP << " " << durability << " " << stageNumber << " " << waveNumber;
		saveFile << " " << m1dmg << " " << m2dmg << " " << m3dmg << " " << m1acc << " " << m2acc << " " << m3acc;
		saveFile.close();
		cout << "Progress saved successfully!" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
	}
	else {
		cout << "Unable to save progress. Please try again." << endl;
	}
}
// Function to load the player's progress
void loadProgress(double& dwarfHP, double& dwarfmaxHP, double& durability, int& stageNumber,
	int& waveNumber, double& m1dmg, double& m2dmg, double& m3dmg, double& m1acc, double& m2acc, double& m3acc) {
	ifstream saveFile("progress.txt");

	if (saveFile.is_open()) {
		saveFile >> dwarfHP >> dwarfmaxHP >> durability >> stageNumber >> waveNumber;
		saveFile >> m1dmg >> m2dmg >>  m3dmg >> m1acc >> m2acc >> m3acc;
		saveFile.close();
		cout << "Progress loaded successfully!" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
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
		this_thread::sleep_for(std::chrono::seconds(1));
	}
	read.close();
}




int main(){
	
	Player Ozen;
	Move AxeS("AxeStrike", "You use axe to hit ", 50, 0.8, false, false);
	Move Swipe("Swipe", "You sway your sharp axe in an arc to the enemy(s).", 45, 0.7, true, false);
	Move Guillotine("Guillotine", "You throw the axe aiming for the neck of ", 80, 0.4, false, false);
	Move Concentrate("Concentrate", "You focus to find the weakness of enemy(s).", 0, 1, false, true);
	//	AxeS, Swipe, Guillotine, Concentrate
	//	AxeS: 50, Swipe: 40, Guillotine: 80
	
	//Lyanna
	BossMove Fireball("Fireball", "The mage launches a fiery ball towards you.", 30, false);
	BossMove Frostbite("Frostbite", "The mage summons an icy jaw towards you.", 45, false);

	//Baryard
	BossMove Pierce("Pierce", "The warrior pierces you in the speed of lightning.", 30, false);
	BossMove HalberdS("Halberd Strike", "The warrior strikes his Halberd heavily onto you.", 50, false);

	//Lyanna & Baryard
	BossMove Curse("Curse", "The curse of the Lich haunts you.", 0, true);

	//Wyvern
	BossMove Claw("Claw", "The dragon claw you with its sharp claws.", 25, false);
	BossMove Bite("Bite", "The dragon bites you with its huge jaw.", 30, false);
	BossMove Dive("Diving Strike", "The dragon flies and crashes down to make a shockwave.", 60, false);

	//Faust
	BossMove Slash("Slash", "The hero dashes to you and slashes you in a blink.", 35, false);
	BossMove Hurricane("Hurricane", "The hero attacks you multiple times heavily like a storm.", 55, false);
	BossMove Excalibur("Excalibur", "The hero fires several beams towards you with the shining legendary sword.", 100, false);
	
	storeFile();
	system("cls");
	//Start
	string test;
	cout << "PLAY?\n";
	cout << "Enter any key to continue...";
	cin >> test;
	cout << endl;
	
	if (test == "test") {
		return 0;
	}


	
	double move1dmg = 0, move2dmg = 0, move3dmg = 0;//To take load file saved damage.
	double move1acc = 0, move2acc = 0, move3acc = 0;//To take load file saved accuracy.
	char play_choice;
	readFile("Title.txt");

	//Choose to play or continue playing if have saved data file.
	cout << "\n                        NEW GAME(n) \n                        CONTINUE(c) \n                        QUIT(q)" << endl;
	int play_choice_record = 0;	//To save and load
	int StageIndex = 0;
	int WaveIndex = 0;
	double hp = 0, maxhp = 0, shd_dura = 0;
	char sure = ' ';
	while (!play_choice_record) {	
		cin >> play_choice;
		switch (play_choice) {
		case 'n': case 'N':			//A new play
			cout << "Sure? You will lose the progress of previous data." << endl;
			cout << "Enter any key to continue... or Press q or Q to quit." << endl;
			cin >> sure;
			if (sure == 'q' || sure == 'Q') {
				return 0;
			}
			else {
				play_choice_record = 1;
			}
			
			//Print the prologue
			cout << "                        ";
			readFile("Prologue.txt");
			StageIndex = 1;			//Make StageIndex and WaveIndex default.
			WaveIndex = 1;
			play_choice_record = 1;
			break;
		case 'c': case 'C':
			loadProgress(hp, maxhp, shd_dura, StageIndex, WaveIndex, move1dmg, move2dmg, move3dmg, move1acc, move2acc, move3acc); //Load when select CONTINUE
			Ozen.loadPlayerInfo(hp, maxhp, shd_dura);
			AxeS.loadAaA(move1dmg, move1acc);
			Swipe.loadAaA(move2dmg, move2acc);
			Guillotine.loadAaA(move3dmg, move3acc);
			if(StageIndex == 6){			//Indicate won status
				cout << "You already won this game. Wanna try again?" << endl;
				break;
			}
			play_choice_record = 2;
			break;
		case 'q': case 'Q':
			cout << "You have quit the game." << endl;
			return 0;
		default:
			cout << "Enter n, c or q only" << endl;
		}
	}

	cout << endl;
	for (int i = 0; i < 40; i++)
		cout << "*";

	cout << endl << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	//Pre-battle stage
	//Make objects of characters
	Stage stage[5];
	stage[0].loadStage(1);
	
	if (play_choice_record == 1)  {//New game
		stage[StageIndex-1].loadStage(StageIndex);
		saveProgress(300, 300, 75, StageIndex, WaveIndex, 
			50, 45, 80, 0.8, 0.7, 0.4);
		cout << endl;
	}
	else if (play_choice_record == 2) {
		stage[StageIndex-1].loadStage(StageIndex);
	}
	this_thread::sleep_for(std::chrono::seconds(2));
	



	char quitopt = ' ';
	// Big loop, main loop for battle use
	while (StageIndex != 6) {

		if (WaveIndex == 1) {
			stage[StageIndex-1].displayStageDesc();
			cout << endl;

		}

		stage[StageIndex-1].searchWave(WaveIndex);
		cout << endl;
		this_thread::sleep_for(std::chrono::seconds(2));
		//Battle either enemy or boss.
		if (!stage[StageIndex - 1].WavehasBoss(WaveIndex)) {
			bool win = false;
			//Fight enemy
			if (battleEnemy(stage[StageIndex - 1], WaveIndex, Ozen, AxeS, Swipe, Guillotine, Concentrate, win)) { 
				if (win) {
					WaveIndex++;
					Ozen.Heal();
				}
				else {
					cout << "Do you want to retry? C/c\n";
					cout << "Or quit? Q/q\n";
					cin >> sure;
					if (sure != 'c' && sure != 'C') {
						continue;
					}
					else if (sure == 'q' || sure == 'Q') {
						cout << "Quitting the game..." << endl;
						this_thread::sleep_for(std::chrono::seconds(3));
						return 0;
					}
				}
			}//Battle enemy ended.
			else {
				cout << "Quitting the game..." << endl;
				this_thread::sleep_for(std::chrono::seconds(3));
				return 0;
			}

		}
		else {
			bool win = false;
			Boss mainboss;
			BossMove Bmove[3];
			stage[StageIndex - 1].copyWaveBoss(WaveIndex,mainboss);
			if (mainboss.getBossName() == "Wyvern") { //Choose their skill for the respective boss
				Bmove[0] = Claw;
				Bmove[1] = Bite;
				Bmove[2] = Dive;
			}
			else if (mainboss.getBossName() == "Lyanna") {
				Bmove[0] = Fireball;
				Bmove[1] = Frostbite;
				Bmove[2] = Curse;
			}
			else if (mainboss.getBossName() == "Baryard") {
				Bmove[0] = Pierce;
				Bmove[1] = HalberdS;
				Bmove[2] = Curse;
			}
			else if (mainboss.getBossName() == "Faust") {
				Bmove[0] = Slash;
				Bmove[1] = Hurricane;
				Bmove[2] = Excalibur;
			}
			//Fight boss
			if (battleBoss(mainboss, AxeS, Swipe, Guillotine, Concentrate, Ozen, Bmove[0], Bmove[1], Bmove[2], win)) {
				if (win) {
					WaveIndex++;
					Ozen.Heal();
				}
				else {
					cout << "Do you want to retry? C/c\n";
					cout << "Or quit? Q/q\n";
					if (sure != 'c' && sure != 'C') {
						continue;
					}
					else if (sure == 'q' || sure == 'Q') {
						cout << "Quitting the game..." << endl;
						this_thread::sleep_for(std::chrono::seconds(3));
						return 0;
					}
				}
			}
			else{
				cout << "Quitting the game..." << endl;
				this_thread::sleep_for(std::chrono::seconds(3));
				return 0;
			}
			// Battle boss ended
			
		}
			

	//Battle ends
		checkStageAndWave(StageIndex, WaveIndex);
		//Use rest function if the game continue to a new Stage but not Stage 6 because does not have 6 stages
		if (WaveIndex == 1 && StageIndex != 6) {
			rest(Ozen, AxeS, Swipe, Guillotine); 
			Ozen.setConcentrated(0);
			cout << "Saving file..." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			saveProgress(Ozen.getHealth(), Ozen.getMAX_Health(), Ozen.getShieldDura(), StageIndex, WaveIndex,
				AxeS.getAttack(), Swipe.getAttack(), Guillotine.getAttack(), AxeS.getAccuracy(), Swipe.getAccuracy(), Guillotine.getAccuracy());
			cout << endl;
			cout << "Enter any key to continue... q/Q to quit.\n";
			cin >> quitopt;
			if (quitopt == 'q' || quitopt == 'Q') {
				cout << "Thanks for playing.\n";
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Quitting the game..." << endl;
				this_thread::sleep_for(std::chrono::seconds(3));
				return 0;
			}
			stage[StageIndex-1].loadStage(StageIndex);
		}
	}
		//save for next play notification of new game
		saveProgress(Ozen.getHealth(), Ozen.getMAX_Health(), Ozen.getShieldDura(), StageIndex, WaveIndex,
			AxeS.getAttack(), Swipe.getAttack(), Guillotine.getAttack(), AxeS.getAccuracy(), Swipe.getAccuracy(), Guillotine.getAccuracy());
		//Play with ending winner board
			ofstream record;
			cout << "Congrats and enter your name here. Enter Winner board to see winners." << endl;
			do {
				cout << "Enter: ";
				cin.ignore();
				getline(cin, test);

				if (test == "Winner board") {
					cout << endl;
					displayWinnerBoard();
					cout << endl;
					quitopt = 'n';
					cin.ignore();
					continue;
				}
				else if(test == "quit" || test == "Quit") {
					cout << "Quitting the game..." << endl;
					this_thread::sleep_for(std::chrono::seconds(3));
					return 0;
				}

				cout << "You sure you want to enter this name: " << test << endl;
				cout << "Enter any key to continue... n/N to retry.\n";
				cin >> quitopt;

			} while (quitopt == 'n' || quitopt == 'N');

			record.open("WinnerBoard.txt",ios::app);
			record << test;
			record.close();
		cout << "Quitting the game..." << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
	return 0;
}

//Rest definition
void rest(Player &p, Move &m1, Move &m2, Move &m3) {
	p.plusMAXHealth();
	m1.UpgradeMoveAttack();
	m1.UpgradeAcc();
	m2.UpgradeMoveAttack();
	m2.UpgradeAcc();
	m3.UpgradeMoveAttack();
	m3.UpgradeAcc();

	char choice = ' ';
	bool invalid =false;
	
	cout << "Finishing those encounters, you decide to rest and prepare for upcoming challenges." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Your max HP has been increased and your moves are now stronger. " << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	p.displayPlayerInfo();
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "Now, you can choose either one between these options: " << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "1. Repair my shield. I think I can do it myself." << endl;
	cout << "2. Take a nap. I've already too tired." << endl;
	cout << "Enter 1 or 2 to select." << endl;
	
	do {
		cin >> choice;
	
		switch (choice){
			case '1': p.repairShield();
					cout << "You have repaired the shield yourself. " << endl;
					this_thread::sleep_for(std::chrono::seconds(2));
					cout << "The result is not as good as the professional BlackSmith but it is still better than none." << endl;
					this_thread::sleep_for(std::chrono::seconds(2));
					cout << "Shield durability: " << p.getShieldDura() << endl;
					this_thread::sleep_for(std::chrono::seconds(1));
					invalid= false;
					break;
			case '2': p.HealHalf();
					cout << "ZZZ......" << endl;
					this_thread::sleep_for(std::chrono::seconds(5));
					cout << "Awake from nap, you are now filled with DETERMINATION." << endl;
					this_thread::sleep_for(std::chrono::seconds(2));
					p.displayHP();
					this_thread::sleep_for(std::chrono::seconds(1));
					invalid= false;
					break;
			default: cout << "Choose wisely, there would not be many chances to rest in this journey." << endl;
					invalid = true;
		} 
		cin.ignore();
		cin.clear();

		} while (invalid);
	
}
//To validate the stage and wave and determine either is it the next stage or wave.
void checkStageAndWave(int& stageIndex, int& waveIndex) {
	Stage funcstage;
	funcstage.loadStage(stageIndex);	//to set the stage
	if (!funcstage.WaveExist(waveIndex)) { //Check if there is no wave, get in the loop
		switch (waveIndex) {
		case 1: case 2: case 3: case 4: case 5:
				funcstage.displayStageEnding();
				cout << endl;
		this_thread::sleep_for(std::chrono::seconds(2));
			default:
				break;
		}

		stageIndex++;
		waveIndex = 1;
		return;
	}
	if (stageIndex == 6) {
		cout << "Congrats on winning! Thanks for playing." << endl;
		return;
	}
}

void displayWinnerBoard() {
	ifstream displayBoard;
	string readboard;
	cout << "Winner: \n";
	displayBoard.open("WinnerBoard.txt");
	while (getline(displayBoard, readboard)) {
		cout << readboard << endl;
	}
	displayBoard.close();
}


//Battle for enemy
// m1=AxeS, m2=Swipe, m3=Guillotine, m4=Concnetrate
bool battleEnemy(Stage useStage, int waveInd, Player &p, Move &m1, Move &m2, Move &m3, Move &m4, bool& win) { //Station 1, Station 5 - from PlayerAttackingEnemy
					
	bool end = false;
	bool complete = true;
	win = false;
	int Ecount = 0;

	useStage.getMonsterCount(waveInd, Ecount);
	
	int deadcount = 0;

	Enemy ene[3];

	useStage.copyWaveEnemy(waveInd, ene);
	
	bool checkedE1 = false, checkedE2 = false, checkedE3 = false; 
	
		int roundcount = 1;
			cout << "|||| Select your move by entering the move NAME" << endl;
			cout << "\\/\\/" << endl;
			m1.displayMoveHorizontally();
			m2.displayMoveHorizontally();
			m3.displayMoveHorizontally();
			m4.displayMoveHorizontally();
			this_thread::sleep_for(chrono::seconds(1));
			cout << "SETTING TO USE:\nShow\t\tShows the battle info\nQuit\t\t Save and quit the game\nSelf\t\tSee Ozen info\n";
			cout << endl;
			this_thread::sleep_for(chrono::seconds(1));
	while(!end){
		string pAction;
		bool misspell = false;
		
		

		do {
			cout << "                   Round " << roundcount << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "******************Your Turn******************" << endl << endl;
			this_thread::sleep_for(std::chrono::seconds(1));

			//Show menu with and without concentrate
			if (!p.getConcentrated()) {
					cout << m1.getName() << " | " << m2.getName() << " | " << m3.getName() << " | ";
					cout << m4.getName() << " | " << "Show | Self | Quit" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));
					cout << "Concentrated: " << "FALSE";
				}
			else {
					cout << m1.getName() << " | " << m2.getName() << " | " << m3.getName();
					cout  << " | " << "Show | Self | Quit" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));
					cout << "Concentrated: " << "TRUE ";
			}
			cout << endl;
			cout << "Enter your move: ";
			cin >> pAction;
			cout << endl;
			if (pAction == m4.getName()){		// player choose concentrate
				if (!p.getConcentrated()) {
					p.setConcentrated(true);
					m4.displayMoveDesc();
					this_thread::sleep_for(std::chrono::seconds(2));
					cout << endl << endl;
					misspell = false;
				}
				else if (p.getConcentrated()) {
					cout << "You had concentrated" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));
					cout << "Choose another move..." << endl;
					continue;
				}

			}
			else if(pAction == m2.getName()) {				// player choose swipe (AOE)
				m2.displayMoveDesc();
				this_thread::sleep_for(std::chrono::seconds(2));
				cout << endl << endl;
				if (Ecount == 1){
					cout << "Enemy " << Ecount << ": ";
					PlayerAttackingEnemy(p, m2, ene[0]);
				}
				else if (Ecount == 2) {
					cout << "Enemy " << Ecount - 1<< ": ";
					PlayerAttackingEnemy(p, m2, ene[0]);
					p.setConcentrated(1);					//To "refill" the Concentrate status

					cout << "Enemy " << Ecount  << ": ";
					PlayerAttackingEnemy(p, m2, ene[1]);
				}
				else if (Ecount == 3) {

					cout << "Enemy " << Ecount - 2 << ": ";
					PlayerAttackingEnemy(p, m2, ene[0]);
					p.setConcentrated(1);
					cout << "Enemy " << Ecount - 1 << ": ";
					PlayerAttackingEnemy(p, m2, ene[1]);
					p.setConcentrated(1);
					cout << "Enemy " << Ecount << ": ";
					PlayerAttackingEnemy(p, m2, ene[2]);
				}
				misspell= false;
			}
			else if(pAction == m1.getName()) {				// player choose AxeStrike
				if (Ecount == 1){
					cout << "Enemy 1: ";
					PlayerAttackingEnemy(p, m1, ene[0]);
				}
				else if (Ecount == 2) {
					if (deadcount == Ecount - 1) {
						if (ene[0].isDead()) {
							cout << "Enemy 2: ";
							PlayerAttackingEnemy(p, m1, ene[1]);
						}
						else if (ene[1].isDead()) {
							cout << "Enemy 1: ";
							PlayerAttackingEnemy(p, m1, ene[0]);
						}
					}
					else
						Choose2Target(p, m1, ene[0], ene[1]);
				}
				else if (Ecount == 3) {
					if (deadcount == Ecount - 1) {
						if (!ene[0].isDead()) {
							cout << "Enemy 1: ";
							PlayerAttackingEnemy(p, m1, ene[0]);
						}
						else if (!ene[1].isDead()) {
							cout << "Enemy 2: ";
							PlayerAttackingEnemy(p, m1, ene[1]);
						}
						else if (!ene[2].isDead()) {
							cout << "Enemy 3: ";
							PlayerAttackingEnemy(p, m1, ene[2]);
						}
					}
					else if (deadcount == Ecount - 2) {
							Choose2Target(p, m1, ene[0], ene[1], ene[2]);
					}
					else
						Choose3Target(p, m1, ene[0], ene[1], ene[2]);
				}
				misspell= false;
			}
			else if(pAction == m3.getName()) {				// player choose Guillotine
				if (Ecount == 1){
					cout << "Enemy 1: ";
					PlayerAttackingEnemy(p, m3, ene[0]);
				}
				else if (Ecount == 2) {
					if (deadcount == Ecount - 1) {
						if (ene[0].isDead()) {
							cout << "Enemy 2: ";
							PlayerAttackingEnemy(p, m1, ene[1]);
						}
						else if (ene[1].isDead()) {
							cout << "Enemy 1: ";
							PlayerAttackingEnemy(p, m1, ene[0]);
						}
					}
					else
						Choose2Target(p, m3, ene[0], ene[1]);
				}
				else if (Ecount == 3) {
					if (deadcount == Ecount - 1) {
						if (!ene[0].isDead()) {
							cout << "Enemy 1: ";
							PlayerAttackingEnemy(p, m1, ene[0]);
						}
						else if (!ene[1].isDead()) {
							cout << "Enemy 2: ";
							PlayerAttackingEnemy(p, m1, ene[1]);
						}
						else if (!ene[2].isDead()) {
							cout << "Enemy 3: ";
							PlayerAttackingEnemy(p, m1, ene[2]);
						}
					}
					else if (deadcount == Ecount - 2) {
							Choose2Target(p, m1, ene[0], ene[1], ene[2]);
					}
					else
						Choose3Target(p, m3, ene[0], ene[1], ene[2]);
				}
				misspell= false;
			}
			else if (pAction == "Show") {	//Show current battle info
				cout << "Stage " << useStage.getStageIndex() << " Wave " << waveInd << ":\n";
				for (int i = 0; i < Ecount; i++) {
					cout << "Enemy " << i + 1 << endl;
					ene[i].displayEnemyInfo();
					this_thread::sleep_for(std::chrono::seconds(2));
					cout << endl;
					this_thread::sleep_for(std::chrono::seconds(1));
				}
			}
			else if (pAction == "Self") {
				p.displayPlayerInfo();
			}
			else if (pAction == "q" || pAction == "Q" || pAction == "Quit" || pAction == "quit") {
				cout << "Sure? You lose the progress to this wave and back to the start of stage..." << endl;
				cout << "Enter q to quit or other key to not quit." << endl;
				char sure;
				cin >> sure;
				if (sure == 'q') {
					complete = false;
					return complete;
				}
			}
			else if (pAction == "CPT113") {//CPT113 enemy
			ene[0].setisDead();
			ene[1].setisDead();
			ene[2].setisDead();
			misspell = false;
			}
			else {
				cout << "You misspell your move!" << endl;
				cout << "Lucky you, this is just a game so you can have another chance." << endl;
				misspell = true;
				cin.ignore();
				cin.clear();	
			}
			
			
		} while (misspell);
		

		if (pAction == "Show" || pAction == "Self") {
			continue;
		}
		cout << "******************Enemy Turn******************" << endl << endl;
		this_thread::sleep_for(chrono::seconds(1));
		// check if the enemy is dead
		// if so, add one counter on deadcount
		// once deadcount == Ecount, break
		// if not, it attacks

		// after every one enemy attack resolve, check if player has died
		// if so, break.
			
		// check for e1 first	
		cout << "Enemy 1: " << endl;
		if (ene[0].isDead()) {
			cout << ene[0].getEnemyType() << " downed. " << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			if(!checkedE1) {			// use another boolean variable
				deadcount++;						// to avoid repeating ++ of deadcount
				checkedE1 = true;					// when only one of the enemy died.
				if (deadcount == Ecount) {
					end = true;
					break;
				}
				}
			}
		else {
			EnemyAttacking(ene[0], p);
			this_thread::sleep_for(std::chrono::seconds(2));
			if (p.isDead()) break;
		}
		//To prevent enemy 2 activation if there is none.
		if (Ecount < 2) {
			roundcount++;
			continue;
		}
		cout << "Enemy 2: " << endl;
		// check for e2 status
		if (ene[1].isDead()) {
			cout << ene[1].getEnemyType() << " downed. " << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			if (!checkedE2) {
				deadcount++;
				checkedE2 = true;
				if (deadcount == Ecount) {
					end = true;
					break;
				}
		}  
		}
		else {
			EnemyAttacking(ene[1], p);
			if (p.isDead()) break;
		}
		//To prevent enemy 3 activation if there is none.
		if (Ecount < 3) {
			roundcount++;
			continue;
		}
		cout << "Enemy 3: " << endl;
		// check for e3 status
		if (ene[2].isDead()) {
			cout << ene[2].getEnemyType() << " downed. \n" << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			if(!checkedE3) {
				deadcount++;
				checkedE3 = true;
				if (deadcount == Ecount) {
					end = true;
					break;
			}
		} 
		}
		else {
			EnemyAttacking(ene[2], p);
			if (p.isDead()) break;
		}
	roundcount++;
	}
	
	if (deadcount == Ecount) {
		cout << "You've defeated all the enemy(s)!" << endl << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		win = true;
		return complete;
	}
	
	if (p.isDead()) {
		cout << "You Died." << endl;
		cout << "___________Game Over___________" << endl << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		win = false;
		return complete;
	}
		
}

void Choose2Target(Player &p, Move &move, Enemy &e1, Enemy &e2){
	char atkTarget;
	bool invalid = false;
	
	do {
		cout << "Choose a target to attack. " << endl;
		cout << "Enter the target's number: " ;
		cin >> atkTarget;
		
		switch (atkTarget) {
			case '1': cout << "Enemy 1: "; 
				PlayerAttackingEnemy(p, move, e1);
				invalid = false;
					break;
			case '2': cout << "Enemy 2: "; 
				PlayerAttackingEnemy(p, move, e2);
				invalid = false;
					break;
			default: 
				invalid = true;
				cout << "You choose an invalid target." << endl;
				cout << "Aim better next time." << endl;
				cin.ignore();
				cin.clear();
		}
		
		
	} while (invalid);
}

//using this overload function to apply at 3 players
void Choose2Target(Player& p, Move& move, Enemy& e1, Enemy& e2, Enemy& e3) {
	char atkTarget = ' ';
	bool invalid = false;
	
		do {
			if (e3.isDead()) {
				cout << "Choice: \n1: Enemy 1 \n2: Enemy 2 \n3: Downed\n";
				cout << "Choose a target to attack. " << endl;
				cout << "Enter the target's number: ";
				cin >> atkTarget;
				if (atkTarget == 3) {
					atkTarget = 4;
				}
			}
			else if (e2.isDead()) {
				cout << "Choice: \n1: Enemy 1 \n2: Downed \n3: Enemy 3\n";
				cout << "Choose a target to attack. " << endl;
				cout << "Enter the target's number: ";
				cin >> atkTarget;
				if (atkTarget == 2) {
					atkTarget = 4;
				}
			}
			else if (e1.isDead()) {
				cout << "Choice: \n1: Downed \n2: Enemy 2 \n3: Enemy 3\n";
				cout << "Choose a target to attack. " << endl;
				cout << "Enter the target's number: ";
				cin >> atkTarget;
				if (atkTarget == 1) {
					atkTarget = 4;
				}
			}
			switch (atkTarget) {
			case '1': cout << "Enemy 1: ";
				PlayerAttackingEnemy(p, move, e1);
				invalid = false;
				break;
			case '2': cout << "Enemy 2: "; 
				PlayerAttackingEnemy(p, move, e2);
				invalid = false;
				break;
			case '3': cout << "Enemy 3: ";
				PlayerAttackingEnemy(p, move, e3);
				invalid = false;
				break;
			default:
				invalid = true;
				cout << "You choose an invalid target." << endl;
				cout << "Aim better next time." << endl;
				cin.ignore();
				cin.clear();
			}


		} while (invalid);
	
}
void Choose3Target(Player &p, Move &move, Enemy &e1, Enemy &e2, Enemy &e3){
	char atkTarget;
	bool invalid = false;
	
	do {
		cout << "Choose a target to attack. " << endl;
		cout << "Enter the target's number: " ;
		cin >> atkTarget;
		
		switch (atkTarget) {
			case '1': cout << "Enemy 1: "; 
				PlayerAttackingEnemy(p, move, e1);
				invalid = false;
					break;
			case '2': cout << "Enemy 2: ";
				PlayerAttackingEnemy(p, move, e2);
				invalid = false;
					break;
			case '3': cout << "Enemy 3: "; 
				PlayerAttackingEnemy(p, move, e3);
				invalid = false;
					break;
			default: invalid = true;
					cout << "You choose an invalid target." << endl;
					cout << "Aim better next time." << endl;
					cin.ignore();
					cin.clear();
		}
		
		
	} while (invalid);
}

//Station 2 - from BattleEnemy, Station 4 - from isATKhit
void PlayerAttackingEnemy(Player &p, Move &move, Enemy &mon){
	if (mon.isDead()) {
		return;
	}
	//	AxeS: 50, Swipe: 40, Guillotine: 80
	double DamageValue = move.getAttack();			// get damage of a move
	
	if (p.getConcentrated()) {					// check if the player status is concentrated
		DamageValue *= 1.5;						// if so, the damage of move will boost up
	}
	
	if (isATKhit(p, move)) {				// defining if the attack hit enemy
		if (!move.getisAOE()) {
			move.displayMoveDesc();
			string name1 = mon.getEnemyType();
			transform(name1.begin(), name1.end(), name1.begin(),[](unsigned char c) { return std::tolower(c); });
			cout << name1  << ". "<< endl;
		}
		this_thread::sleep_for(std::chrono::seconds(2));
		mon.EnemyAttacked(DamageValue, rollD6());		// calculate damage ratio on enemy
		this_thread::sleep_for(std::chrono::seconds(2));
		mon.displayEnemyInfo();
		cout << endl;
	}
	else {
		cout << "Your attack missed..." << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		mon.displayEnemyInfo();
		cout << endl;
	}
	p.setConcentrated(0);						// reset player status
}


void EnemyAttacking(Enemy &mon, Player &p) {
	
	double damageValue = mon.getAttack();
	cout << mon.getEnemyType();
	p.PlayerAttacked(damageValue, rollD20());
	p.displayHP();
	this_thread::sleep_for(std::chrono::seconds(1));
}

//Station 3 - from PlayerAttackingEnemy
bool isATKhit(Player &p, Move &move){
	
	// Boolean function to determine if the player's attack hit the enemy
	// based on the moves' accuracy rate.
	
	if (p.getConcentrated()) return true;		// if player concentrated in the last turn
												// the attack is guaranteed to hit
												
	bool hit = true;
	
	//	AxeS: 0.6, Swipe: 0.6, Guillotine: 0.6
	double temp = 20 * move.getAccuracy();
	int HitMiss = static_cast<int>(temp) ;						// better use D20 to have more
																// more valid chances
	double val;
	val = rollD20();
	if (val <= HitMiss && val >= 1) hit = true;
	else if (val > HitMiss) hit = false;
	

	return hit;
}

void BossAction(Boss &b, Player &p, BossMove &b1, BossMove &b2, BossMove &b3) {
	
	// decide a Boss' move first in this function using D20 dice
	// then Boss will start to attack the player
	
	double val = rollD20();
	if (val <= 12) BossAttacking(b, b1, p);
	else if (val > 12 && val <= 18) BossAttacking(b, b2, p);
	else if (val > 18) BossAttacking(b, b3, p);
}

void BossAttacking(Boss &b, BossMove &bossmove, Player &p) {
	
	// showing the whole process of the attack of boss
	
	cout << b.getBossName() << ": " << endl;
	this_thread::sleep_for(chrono::seconds(2));
	bossmove.displayMoveDesc();
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl;
	showbossdmg(bossmove);
	cout << endl;
	
	if (bossmove.getisCurse()) {
		cout << b.getBossName();
		p.Cursed();
	}
	else if (b.RAGE() && !bossmove.rageBoosted()) {
		bossmove.inRage();
		this_thread::sleep_for(chrono::seconds(1));
		double BossDamageValue = bossmove.getAttack();
		cout << b.getBossName();
		p.PlayerAttacked(BossDamageValue, rollD20());
		
	}
	else {
		double BossDamageValue = bossmove.getAttack();
		cout << b.getBossName();
		p.PlayerAttacked(BossDamageValue, rollD20());
	}

	p.displayHP();
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << endl;
}

void PlayerAttackingBoss(Player &p, Move &move, Boss &b){
	
	// only considering attacking move as
	// Concentrate will be separated when 
	// player input the chosen move in battleBoss function.
	
	double DamageValue = move.getAttack();	
		if (p.getConcentrated()) {
		DamageValue *= 1.5;
	}
	
	if (isATKhit(p, move)) {
		if (!move.getisAOE()) {
			move.displayMoveDesc();
			string nameb = b.getBossName();
			cout << nameb << ". \n";
		}
		this_thread::sleep_for(std::chrono::seconds(2));
		b.EnemyAttacked(DamageValue, rollD20());
		this_thread::sleep_for(std::chrono::seconds(2));
		b.displayBossInfo();
	}
	else {
		cout << "Your attack missed..." << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		b.displayBossInfo();
	}		
		
	p.setConcentrated(0);
		
}

// m1=AxeS, m2=Swipe, m3=Guillotine, m4=Concentrate, d=D20, 
bool battleBoss(Boss &b, Move &m1, Move &m2, Move &m3, Move &m4, Player &p, BossMove &b1, BossMove &b2, BossMove &b3,bool &win) {
	win = false;
	int roundcount = 1;
	string pAction;
	bool misspell = false;
	bool ragetrigger = false;
	cout << "|||| Select your move by entering the move NAME" << endl;
	cout << "\\/\\/" << endl;
	m1.displayMoveHorizontally();
	m2.displayMoveHorizontally();
	m3.displayMoveHorizontally();
	m4.displayMoveHorizontally();
	this_thread::sleep_for(chrono::seconds(1));
	cout << "SETTING TO USE:\nShow\t\tShows the battle info\nQuit\t\t Save and quit the game\nSelf\t\tSee Ozen info\n";
	cout << endl;
	this_thread::sleep_for(chrono::seconds(1));

	while (!b.isDead()) {

		do{
			cout << "                   Round " << roundcount << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "******************Your Turn******************" << endl << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			//Let user knows if player used concentrate last round or not. Concentrate is a buff move.
			if (!p.getConcentrated()) {
				cout << m1.getName() << " | " << m2.getName() << " | " << m3.getName() << " | ";
				cout << m4.getName() << " | " << "Show | Self | Quit" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Concentrated: " << "FALSE";
			}
			else {
				cout << m1.getName() << " | " << m2.getName() << " | " << m3.getName();
				cout << " | " << "Show | Self | Quit" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Concentrated: " << "TRUE ";
			}
			cout << endl;
			cout << "Enter your move: ";
			cin >> pAction;
			cout << endl;

			if (pAction == m4.getName()) {		// separate Concentrate from other attacking move
				if (!p.getConcentrated()) {
					p.setConcentrated(true);
					m4.displayMoveDesc();
					this_thread::sleep_for(std::chrono::seconds(2));
					cout << endl << endl;
					misspell = false;
				}
				else if (p.getConcentrated()) {
					cout << "You had concentrated" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));
					cout << "Choose another move..." << endl;
					continue;
				}

			}
			else if(pAction == m1.getName()) {
				PlayerAttackingBoss(p, m1, b);
				misspell= false;
			}
			else if(pAction == m2.getName()) {
				m2.displayMoveDesc();
				this_thread::sleep_for(std::chrono::seconds(2));
				cout << endl << endl;
				PlayerAttackingBoss(p, m2, b);
				misspell= false;
			}
			else if(pAction == m3.getName()) {
				PlayerAttackingBoss(p, m3, b);
				misspell= false;
			}
			else if (pAction == "Show") {	//Show current battle info
					cout << "Boss: " << endl;
					b.displayBossInfo();
					this_thread::sleep_for(std::chrono::seconds(2));
					cout << endl;
					this_thread::sleep_for(std::chrono::seconds(1));
				continue;
			}
			else if (pAction == "Self") {
				p.displayPlayerInfo();
			}
			else if (pAction == "Quit" || pAction == "Q") {
				cout << "Sure? You lose the progress to this wave and back to the start of stage..." << endl;
				cout << "Enter q to quit or other key to not quit." << endl;
				char sure;
				cin >> sure;
				if (sure == 'q')
					return false;
			}
			else if (pAction == "CPT113") {
					b.BossAttacked(5000, 20);
					misspell = false;
				}
			//********************
			else if (pAction == "500") {
				b.setEHealth(500);
				misspell = false;
			}
			else {
				cout << "You misspell your move!" << endl;
				cout << "Lucky you, this is just a game so you can have another chance." << endl;
				misspell = true;
				cin.ignore();
				cin.clear();
			}
		
		if (pAction == "Show" || pAction == "Self") {
			continue;
		} 
		
		}while (misspell);

		if (b.RAGE() && !ragetrigger) {
			cout << "\n" << b.getBossName() << " in RAGE mode\n Boss skill damage upgraded.\n";
			ragetrigger = true;
		}

		if (b.isDead()) {
			cout << b.getBossName() << " downed. \n";
			this_thread::sleep_for(std::chrono::seconds(3));
			for (int i = 0; i < 3; i++) {
				cout << ".";
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << endl;
			break;

		}

		cout << "******************Enemy Turn******************" << endl << endl;
		this_thread::sleep_for(chrono::seconds(1));
		
		BossAction(b, p, b1, b2, b3);
		
		if (p.isDead()) {
			break;
		}
		roundcount++;
	}
	if (b.isDead()) {
		cout << "You defeat the boss!" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		b.displayBossEnding();
		this_thread::sleep_for(std::chrono::seconds(3));
		cout << endl;
		win = true;
		//ifstream
		//waveindex++;
		return true;
	}
	
	if (p.isDead()) {
		cout << "You Died." << endl;
		cout << "___________Game Over___________" << endl;
		win = false;
		return true;
	}
	
}

double rollD6(){
	Dice dice;
	dice.roll();
	return dice.getValue();
}

double rollD20() {
	Dice dice(20);
	dice.roll();
	return dice.getValue();
}
