#include <iostream>
#include <fstream>
using namespace std;
   

void storeFile(){
	//This program is use to design the files for the games.
	ofstream write;
	//TITLE
	write.open("Title.txt");
	write << "REDEMPTION" << endl;
	write << "Welcome to REDEMPTION, a game that you play as a retired dwarf warrior and try to explore a dark dungeon ";
	write << "and fight off monsters." << endl;
	write.close();

	//PROLOGUE
	write.open("Prologue.txt");
	write << "Prologue: " << endl;
	write << "Ozen, the former warrior of the hero party, a dwarf whose name is well-known in the kingdom for his incredible strength. "
		<< "His party had successfully defeated the dragon that threatened the kingdom for decades. "
		<< "The capital was flooded with cheers when they finally ended their 8-year journey and came"
		<< " back to the palace, where the journey began. " << endl;	//Paragraph 1
	write << "After the celebration, Ozen decided to leave the party and prepared for his new life after retirement as a farmer."
		<< " His position in the party was replaced by his young son, Bayard. " << endl;
	write << "Time flies. Ozen started to adapt to these peaceful days after years of battle. "
		<< "On the other side, the hero party was called to the palace."
		<< " The King wanted them to defeat the Lich who controlled a dungeon in the north. " << endl;
	write << "The hero party succeeded in clearing the dungeon and killed the Lich, Uttara."
		<< " However, the Lich’s curse had made it impossible for them to leave the dungeon and slowly corrupted the party members." << endl;
	write << "This time, Ozen was recruited to explore the dungeon and find the missing party. "
		<< " Bringing his axe Sigrdrífa and his shield Wargard, "
		<< "Ozen stepped on his journey towards the dungeon……" << endl;
	write.close();

	//STAGE 1
	write.open("Stage 1_desc.txt");
	write << "1" << endl;
	write << "The Entrance" << endl;
	write << "It is cold and dark here. You with the light source from your ";
	write << "torch seems... alone. You can hear that the heavy door at ";
	write << "your back is slowly shutting. Besides the dripping water sound ";
	write << "echoing in the hallway, you can also hear a small giggling sound in front..." << endl;
	write << "Stage 1 COMPLETED: Look like you clear the area, you rekindle the torches on the walls,";
	write << "the entrance is much brighter now. The long and narrow hallway leads you to the staircase going downstairs,";
	write << "it is looking quite dangerous down there." << endl;
	write << "S1Wave1_desc.txt" << endl;
	write << "S1Wave2_desc.txt";
	write.close();
	
	write.open("S1Wave1_desc.txt");
	write << "1" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "1" << endl;		//Monster count
	write << "Goblin.txt" << endl;//Monster 1 info
	write.close();
	
	write.open("S1Wave2_desc.txt");
	write << "2" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "2" << endl;		//Monster count
	write << "Goblin.txt" << endl;	//Monster 1 info
	write << "Goblin.txt" << endl;	//Monster 2 info
	write.close();
	
	//STAGE 2
	write.open("Stage 2_desc.txt");
	write << "2" << endl;
	write << "The Basement" << endl;
	write << "Someone was here. There are bones and more bones on the ground,";
	write << " and a huge empty jail. No one knows what has been contained here. ";
	write << "Animal? People? Monster? At least they do not need to face the devil ";
	write << "right before your eyes right now. You can sense the rage inside its eyes..." << endl;
	write << "Stage 2 COMPLETED: You fight through the monster waves and rush into a room. ";
	write << "Now you can take a rest for a short moment and all you can only think is keep going on..." << endl;
	write << "S2Wave1_desc.txt" << endl;
	write << "S2Wave2_desc.txt" << endl;
	write << "S2Wave3_desc.txt";
	write.close();
	
	write.open("S2Wave1_desc.txt");
	write << "1" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "1" << endl;		//Monster count
	write << "Kobold.txt" << endl;//Monster 1 info
	write.close();
	
	write.open("S2Wave2_desc.txt");
	write << "2" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "2" << endl;		//Monster count
	write << "Kobold.txt" << endl;	//Monster 1 info
	write << "Goblin.txt" << endl;	//Monster 2 info
	write.close();
	
	write.open("S2Wave3_desc.txt");
	write << "3" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "3" << endl;		//Monster count
	write << "Kobold.txt" << endl;	//Monster 1 info
	write << "Goblin.txt" << endl;	//Monster 2 info
	write << "Kobold.txt" << endl;	//Monster 3 info	
	write.close();
	
	//STAGE 3
	write.open("Stage 3_desc.txt");
	write << "3" << endl;
	write << "The Secret Door" << endl;
	write << "The wall seems too weird, you try to push it but it has no use. ";
	write << "You search your surroundings to find a line connecting the wall to a book on the";
	write << "bookshelves and pull it.The hidden door is unlocked and you keep on moving.";
	write << " and a huge empty jail. No one knows what has been contained here. " << endl;
	write << "Stage 3 COMPLETED: The golem was tough, but it does not hold you back,  ";
	write << "you remember why you like to fight at the first place,";
	write << "the adrenaline…, the exciting emotions…, you reminisce through those memories, ";
	write << "there is only one difference, you feel tired easier as time goes by…";
	write << "You drag yourself into a tunnel pass the remnant of the golem…" << endl;
	write << "S3Wave1_desc.txt" << endl;
	write << "S3Wave2_desc.txt" << endl;
	write << "S3Wave3_desc.txt";
	write.close();

	write.open("S3Wave1_desc.txt");
	write << "1" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "1" << endl;		//Monster count
	write << "Ogre.txt" << endl;//Monster 1 info
	write.close();

	write.open("S3Wave2_desc.txt");
	write << "2" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "3" << endl;		//Monster count
	write << "Goblin.txt" << endl;	//Monster 1 info
	write << "Ogre.txt" << endl;	//Monster 2 info
	write << "Goblin.txt" << endl;	//Monster 3 info
	write.close();

	write.open("S3Wave3_desc.txt");
	write << "3" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "1" << endl;		//Monster count
	write << "Golem.txt" << endl;	//Monster 1 info
	write.close();

	//STAGE 4
	write.open("Stage 4_desc.txt");
	write << "4" << endl;
	write << "The Cavern" << endl;
	write << "The tunnel keeps narrowing down and it is the only road.";
	write << " The spiky rocks look sharp and it will be horrible if you get ";
	write << "caught in one of those. It is fortunate that you have a smaller body to go ";
	write << "through that narrow hole at the end of the tunnel. What a huge cave,";
	write << " the sound of something breathing echoes in the cave, ";
	write << "the sound is too large for an animal, and that does not sound good…" << endl;
	write << "Stage 4 COMPLETED ";
	write << "The wyvern falls onto the ground. This reminds you of the journey that had " 
		<< "ended years ago. You are relieved. You feel like this has been the last battle. "
		<< "Suddenly, you are haunted by an evil aura. You start to look for its origin in "
		<< "the huge cave. " << endl;
	write << "S4Wave1_desc.txt" << endl;
	write << "S4Wave2_desc.txt" << endl;
	write << "S4Wave3_desc.txt" << endl;
	write << "S4Wave4_desc.txt" << endl;
	write.close();

	write.open("S4Wave1_desc.txt");
	write << "1" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "3" << endl;		//Monster count
	write << "Goblin.txt" << endl;//Monster 1 info
	write << "Goblin.txt" << endl;	//Monster 2 info
	write.close();

	write.open("S4Wave2_desc.txt");
	write << "2" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "2" << endl;		//Monster count
	write << "Kobold.txt" << endl;	//Monster 1 info
	write << "Kobold.txt" << endl;	//Monster 2 info
	write.close();

	write.open("S4Wave3_desc.txt");
	write << "3" << endl;		//Wave no
	write << "0" << endl; 		//Not boss
	write << "2" << endl;		//Monster count
	write << "Ogre.txt" << endl;	//Monster 1 info
	write << "Ogre.txt" << endl;	//Monster 2 info
	write.close();

	write.open("S4Wave4_desc.txt");
	write << "4" << endl;		//Wave no
	write << "1" << endl; 		//Mini boss
	write.close();
	
	//STAGE 5
	write.open("Stage 5_desc.txt");
	write << "5" << endl;
	write << "The Final Battle" << endl;
	write << "You found a long narrow tunnel. It is the only way left you can find that "
		<< "goes further deeper into the dungeon. As you go deep inside, you notice that " 
		<< "there are no signs of living things anymore. You can hear some evil whisper, "
		<< "you hope it is just a sign of tiredness. Eventually, you find something at the "
		<< "end of the tunnel. It looks like a sanctuary, except you can notice the skulls "
		<< "surround it. Knowing this would be the end of the journey, you step on towards "
		<< "the sanctuary. As you get close to it, you notice that a person is waiting for you there..."<< endl;
	write << "S5Wave1_desc.txt";
	write.close();

	write.open("S5Wave1_desc.txt");
	write << "1" << endl;
	write << "1" << endl;
	write.close();

	//ENEMIES(NO SPECIAL MOVE)
	write.open("Goblin.txt");
	write << "Goblin" << endl;	
	write << "10" << endl;
	write << "120" << endl;
	write.close();
	
	write.open("Kobold.txt");
	write << "Kobold" << endl;
	write << "18" << endl;
	write << "200" << endl;
	write.close();
	
	write.open("Ogre.txt");
	write << "Ogre" << endl;
	write << "26" << endl;
	write << "500" << endl;
	write.close();

	write.open("Golem.txt");
	write << "Golem" << endl;
	write << "30" << endl;
	write << "800" << endl;
	write.close();

	//BOSS
	write.open("Wyvern.txt");
	write << "Wyvern" << endl;
	write << "A dragon is woken up. You never thought that there will be a dragon here..." << endl;
	write << "1000" << endl;
	write.close();

	write.open("Lyanna.txt");
	write << "Lyanna" << endl;
	write << "A lady slowly walks towards you with unkind eyes. You recognize the mage staff she holding and know this would be a tough fight..." << endl;
	write << "800" << endl;
	write.close();

	write.open("Baryard.txt");
	write << "Baryard" << endl;
	write << "A young man is ready for battle. There is no other weapons would be more familiar to you than his halberd but you refuse to think further..." << endl;
	write << "1000" << endl;
	write.close();

	write.open("Faust.txt");
	write << "Faust" << endl;
	write << "One man holding a familiar sword stands alone in the sanctuary. Even the hero himself couldn't escape the curse of the Lich..." << endl;
	write << "1200" << endl;
	write.close();

	//ENDINGS
	write.open("LyannaEnding.txt");
	write << "Looking at the dying mage who used to take care of a lot of the members in the party, "
		<< "Ozen still couldn’t accept the fact that the lady he treated like his daughter had been corrupted and tried to kill him. " << endl;
	write << "Ozen slowly stands up, trying to figure out what happened to the rest of the party. "
		<< "He takes a charm from the mage, one of a series of rings which was owned by each of the members in the party. "
		<< "Ozen is tired. "
		<< "He has to report the situation in the dungeon to the kingdom’s guards waiting outside. " << endl;
	write << "He steps on his feet. " 
		<< "It had been a long time since the last time he experienced such heavy steps. "
		<< "The fatigue exhausts him. " 
		<< "He never thought that the way back would be so long that he can’t feel himself getting close to exit……" << endl;
	write.close();

	write.open("BaryardEnding.txt");
	write << "“Dad…? ”" << endl;
	write << "“I thought…. I’ll never…. have a chance to see you again….” "
		<< "The young warrior says but Ozen couldn’t feel like the young one is talking to him. " << endl;
	write << "“Sorry…. I still can’t….. be your proud……”" << endl;
	write << "Without finishing his last word, the young warrior leaves the old warrior alone in the room. "
		<< "A drop of tear runs down Ozen's face. "
		<< "He stares at the young man’s face, holding his hand tightly but stays in silence. " << endl;
	write << "Knowing that he couldn’t safely leave the dungeon while carrying a person, "
		<< "Ozen takes a halberd which is owned by the young man. "
		<< "It had been years since he held a weapon like that. " << endl;
	write << "Instead of leaving the dungeon to report the situation, Ozen decides to take a rest first. "
		<< "He is already tired of the battles and killings. " 
		<< "He takes a nap, hoping there will not be any burdens when he awakes next time……." << endl;
	write.close();

	write.open("FaustEnding.txt");
	write << "Barely winning the fight, Ozen turns back, stepping to the exit of the room. "
		<< "He still can’t believe even the strongest among the party also fall to the curse." << endl;
	write << "“Ozen……” A familiar voice grabs the warrior’s attention. " << endl;
	write << "Ozen looks into the hero lying on the floor. " 
		<< "He notices that the evil aura is leaving the body of the man. " << endl;
	write << "“Thanks, mate….” The man tries to stand up on his own but falls with his face directly onto the floor." << endl;
	write << "“You must be having a tough time, huh?” "
		<< "The quiet dwarf says to the human, approaching him slowly. " << endl;
	write << "“Need some help? ” Ozen stands in front of Faust, staring at his face. " << endl;
	write << "“You old cruel stubborn dwarf…” The hero can barely stand up this time. " << endl;
	write << "“You’re gonna be asked about all this mess. Don't waste your stamina, we have to leave this place.” " << endl;
	write << "“Then stay with me till I fully recover... I don’t want to meet that old man alone.”" << endl;
	write << "Two men walk together in the dungeon, " 
		<< "heading towards the exit while complaining to each other about their old days. " << endl;
	write.close();

}
  