#include <iostream>
#include <fstream>
using namespace std;
   

void storeFile(){
	//This program is use to design the files for the games.
	ofstream write;
	//TITLE
	write.open("Title.txt");
	write << "                        REDEMPTION" << endl;
	write << "Welcome to REDEMPTION, a game that you play as a retired dwarf  " << endl;
	write << "warrior and try to explore a dark dungeon and fight off monsters." << endl; 
	write.close();

	//PROLOGUE
	write.open("Prologue.txt");
	write << "Prologue" << endl;
	write << "Ozen, the former warrior of the hero party, a dwarf whose name is well-known in the kingdom for " << endl;
	write << "his incredible strength. His party had successfully defeated the dragon that threatened the " << endl;
	write << "kingdom for decades. The capital was flooded with cheers when they finally ended their 8-year " << endl;
	write << "journey and came back to the palace, where the journey began. " << endl << endl;	//Paragraph 1

	write << "After the celebration, Ozen decided to leave the party and prepared for his new life after retirement " << endl;
	write << "as a farmer. His position in the party was replaced by his young son, Bayard. " << endl << endl; //Paragraph 2

	write << "Time flies. Ozen started to adapt to these peaceful days after years of battle. On the other side, " << endl;
	write << "the hero party was called to the palace. The King wanted them to defeat the Lich who controlled " << endl;
	write << "a dungeon in the north. " << endl << endl; //Paragraph 3

	write << "The hero party succeeded in clearing the dungeon and killed the Lich, Uttara. However, the final " << endl;
	write << "curse of Lich had made it impossible for them to leave the dungeon and slowly corrupted the party " << endl;
	write << "members. \n"<< endl; //Paragraph 4

	write << "This time, Ozen was recruited to explore the dungeon and find the missing party. Bringing his axe " << endl;
	write << "Sigrdrifa and his shield Wargard, Ozen stepped on his journey towards the dungeon......";
	write.close();

	//STAGE 1
	write.open("Stage1.txt");
	write << "1" << endl;
	write << "The Entrance" << endl;
	write << "Stage1_desc.txt" << endl;
	write << "Stage1_ending.txt" << endl;
	write << "S1Wave1_desc.txt" << endl;
	write << "S1Wave2_desc.txt";
	write.close();

	write.open("Stage1_desc.txt");
	write << "It is cold and dark here. You with the light source from your torch seems... alone." << endl;
	write << "You can hear that the heavy door at your back is slowly shutting. Besides the dripping " << endl;
	write << "water sound echoing in the hallway, you can also hear a small giggling sound in front..." << endl;
	write.close();

	write.open("Stage1_ending.txt");
	write << "                                    Stage 1 COMPLETED" << endl;
	write << "Look like you clear the area, you rekindle the torches on the walls,the entrance is much brighter " << endl;
	write << "now. The long and narrow hallway leads you to the staircase going downstairs, it is looking quite " << endl;
	write << "dangerous down there..." << endl;
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
	write.open("Stage2.txt");
	write << "2" << endl;
	write << "The Basement" << endl;
	write << "Stage2_desc.txt" << endl;
	write << "Stage2_ending.txt" << endl;
	write << "S2Wave1_desc.txt" << endl;
	write << "S2Wave2_desc.txt" << endl;
	write << "S2Wave3_desc.txt";
	write.close();

	write.open("Stage2_desc.txt");
	write << "Someone was here. There are bones and more bones on the ground, and a huge empty jail. No one " << endl;
	write << "knows what has been contained here. Animal? People? Monster? At least they do not need to face "<< endl;
	write << "the devil right before your eyes right now. You can sense the rage inside its eyes..." << endl;
	write.close();
	
	write.open("Stage2_ending.txt");
	write << "                                    Stage 2 COMPLETED" << endl;
	write << "You fight through the monster waves and rush into a room. Now you can take a rest for a short " << endl;
	write << "moment and all you can only think is keep going on..." << endl;
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
	write.open("Stage3.txt");
	write << "3" << endl;
	write << "The Secret Door" << endl;
	write << "Stage3_desc.txt" << endl;
	write << "Stage3_ending.txt" << endl;
	write << "S3Wave1_desc.txt" << endl;
	write << "S3Wave2_desc.txt" << endl;
	write << "S3Wave3_desc.txt";
	write.close();

	write.open("Stage3_desc.txt");
	write << "The wall seems too weird, you try to push it but it has no use. You search your surroundings to " << endl;
	write << "find a line connecting the wall to a book on thebookshelves and pull it.The hidden door is unlocked " << endl;
	write << "and you keep moving on ..." << endl;
	write.close();

	write.open("Stage3_ending.txt");
	write << "                                  Stage 3 COMPLETED" << endl;
	write << "The golem was tough, but it does not hold you back, you remember why you like to fight at the " << endl;
	write << "first place, the adrenaline..., the exciting emotions..., you reminisce through those memories, " << endl;
	write << "there is only one difference, you feel tired easier as time goes by... You drag yourself into a " << endl;
	write << "tunnel pass the remnant of the golem..." << endl;
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
	write.open("Stage4.txt");
	write << "4" << endl;
	write << "The Cavern" << endl;
	write << "Stage4_desc.txt" << endl;
	write << "Stage4_ending.txt" << endl;
	write << "S4Wave1_desc.txt" << endl;
	write << "S4Wave2_desc.txt" << endl;
	write << "S4Wave3_desc.txt" << endl;
	write << "S4Wave4_desc.txt" << endl;
	write.close();

	write.open("Stage4_desc.txt");
	write << "The tunnel keeps narrowing down and it is the only road. The spiky rocks look sharp and it " << endl;
	write << "will be horrible if you get caught in one of those. It is fortunate that you have a smaller " << endl;
	write << "body to go through that narrow hole at the end of the tunnel. What a huge cave, the sound " << endl;
	write << "of something breathing echoes in the cave, the sound is too large for an animal, and that " << endl;
	write << "does not sound good..." << endl;
	write.close();

	write.open("Stage4_ending.txt");
	write << "                                    Stage 4 COMPLETED: " << endl;
	write << "The wyvern falls heavily onto the ground. This reminds you of the journey that had ended years " << endl;
	write << "ago. You are relieved. You feel like this has been the last battle. Suddenly, you are haunted " << endl;
	write << "by an evil aura. You start to look for its source in the huge cave... " << endl;
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
	write.open("Stage5.txt");
	write << "5" << endl;
	write << "The Final Battle" << endl;
	write << "Stage5_desc.txt" << endl;
	write << "None." << endl;
	write << "S5Wave1_desc.txt";
	write.close();

	write.open("Stage5_desc.txt");
	write << "You found a long narrow tunnel. It is the only way left you can find that goes further deeper " << endl;
	write << "into the dungeon. As you go deep inside, you notice that there are no signs of living things " << endl;
	write << "anymore. You can hear some evil whisper, you hope it is just a sign of tiredness. Eventually, " << endl;
	write << "you find something at the end of the tunnel. It looks like a sanctuary, except there are skulls " << endl;
	write << "surrounding it. Knowing this would be the end of the journey, you step on towards the sanctuary. " << endl;
	write << "As you get close to it, you notice that a person is waiting for you there..." << endl;
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
	write << "350" << endl;
	write.close();

	write.open("Golem.txt");
	write << "Golem" << endl;
	write << "30" << endl;
	write << "750" << endl;
	write.close();

	//BOSS
	write.open("Wyvern.txt");
	write << "Wyvern" << endl;
	write << "A dragon is woken up. You never thought that there will be a dragon here..." << endl;
	write << "1000" << endl;
	write << endl;
	write.close();

	write.open("Lyanna.txt");
	write << "Lyanna" << endl;
	write << "A lady slowly walks towards you with unkind eyes. You recognize the mage staff she holding and know this would be a tough fight..." << endl;
	write << "800" << endl;
	write << "LyannaEnding.txt";
	write.close();

	write.open("Baryard.txt");
	write << "Baryard" << endl;
	write << "A young man is ready for battle. There is no other weapons would be more familiar to you than the halberd on his hand..." << endl;
	write << "1000" << endl;
	write << "BaryardEnding.txt";
	write.close();

	write.open("Faust.txt");
	write << "Faust" << endl;
	write << "One man holding a familiar sword stands alone in the sanctuary. Even the hero himself couldn't escape the curse of the Lich..." << endl;
	write << "1200" << endl;
	write << "FaustEnding.txt";
	write.close();

	//ENDINGS
	write.open("LyannaEnding.txt");
	write << "Looking at the dying mage who used to take care of a lot of the members in the party, Ozen cannot " << endl;
	write << "accept the fact that the lady he treated like his daughter had been corrupted and tried to kill him. \n"<< endl;

	write << "Ozen slowly stands up, trying to figure out what happened to the rest of the party. He takes a charm " << endl;
	write << "from the mage, one of a series of rings which was owned by each of the members in the party. \n " << endl;

	write << "Ozen is tired but he has to report the situation in the dungeon to the kingdom guards waiting " << endl;
	write << "outside. He steps on his feet. It had been a long time since the last time he experienced such " << endl;
	write << "heavy steps. The fatigue exhausts him. He never thought that the way back would be so long that " << endl;
	write << "he cannot feel himself getting any closer to the exit......\n" << endl;
	write.close();
	
	write.open("BaryardEnding.txt");
	write << "Baryard: Dad...? I thought... I will never... have a chance to see you again..." << endl << endl;

	write << "The young warrior says but Ozen could not feel like the young one is talking to him. " << endl << endl;

	write << "Baryard: Sorry, ...... I still cannot...... make you prou......" << endl << endl;

	write << "Without finishing his last word, the young warrior leaves the old warrior alone in the sanctuary. " << endl;
	write << "A drop of tear runs down his face. He stares at the familiar face, holding his hand tightly but " << endl; 
	write << "stays in silence.\n" << endl;

	write << "Knowing that he could not safely leave the dungeon while carrying a person, Ozen takes the halberd. " << endl;
	write << "It had been years since he held it like that. \n " << endl;

	write << "Instead of leaving the dungeon to report the situation, Ozen decides to take a rest first. He is " << endl;
	write << "already tired of the battles and killings. He takes a nap, hoping there will be no burdens when " << endl;
	write << "he awakes next time......." << endl;
	write.close();

	write.open("FaustEnding.txt");
	write << "Barely winning the fight, Ozen turns back, stepping to the exit of the room. He still cannot " << endl;
	write << "believe that even the strongest among the party also fell to the curse.\n" << endl;
	
	write << "Faust : Ozen......\n" << endl;

	write << "A familiar voice can be heard by Ozen. Ozen looks at the hero lying on the floor. He notices " << endl;
	write << "that the dark aura is leaving the body of the man. \n"<< endl;

	write << "Faust: Thanks, mate...\n";
	write << "Said the man while trying to stand up on his own but falls with his face directly onto the floor.\n" << endl;

	write << "Ozen: You must be having a tough time, huh? "<< endl;
	write << "Said the quiet dwarf while picking him up. \n" << endl;

	write << "Ozen: Need some help?\n Ozen stands in front of Faust, staring at his face. \n" << endl;

	write << "Faust : You... old cruel stubborn dwarf...\n\n The hero can barely stand up this time. \n" << endl;

	write << "Ozen : You are gonna be asked about all this mess. Do not waste my time, we have to leave this " << endl;
	write << "place.\n " << endl;

	write << "Faust : Ehh... Why do I to need to meet that troublesome old man again...... Hey Ozen, take me " << endl;
	write << "        along with you, anywhere except the Palace. You have to pay for all these wounds.\n" << endl;

	write << "Ozen : ......Sounds fair to me.\n" << endl;

	write << "The two old friends head towards the exit while complaining to each other about their good old days. " << endl;
	write.close();

}
  