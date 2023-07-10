# Hackathon2-G14-2023
This project ts to make a game using OOP and linked list to show our understandings.

Group 14
> Cheng Jia Xiu (164649)   
> Chia Jie Lun (163659)   
> Vimal S/O Ravichandran (162601)

Game Title:
REDEMPTION

# Game Description
This is a text-based RPG we built entirely in C++.

In this game, you play as a dwarf warrior deeping into a dungeon.
You are once a member in the hero party which had slained the evil dragon.
After the journey ended, you had left from your party and enjoyed peaceful days.  

One day, your ex-party members were on their mission to explore a dungeon and defeat a Lich living inside.
For some reason, they had been trapped inside the dungeon.
You are recruited to investigate the truth behind this mystery. 

# Game Features
- Traditional Turn-based Combat
- RNG Mechanic Providing Diverse Gameplay Experience
- Multiple Endings
- Auto-Saving Game Progress
- Winner board Celebrating Victories

# How to Play
To play this game, you have to download it. Open the .h and .cpp files on a C++ IDE, and link them in a project.  
Run the program and have your time playing it.  

**P.S.** During the combat, you will be asked to **ENTER YOUR MOVE's NAME** to use them.  
These moves include  

1. **AxeStrike**   --> A steady move dealing single-target damage to an enemy.  
2. **Swipe**       --> An AOE move dealing damage to all the enemies you currently encounter.  
3. **Guillotine**  --> A heavy move (has lower accuracy) dealing significant damage to an enemy.  
4. **Concentrate** --> A status move that boosts your next move's power and accuracy.

# Object-oriented Concepts in the Game
The game consists of several classes to define their respective objects.  

These class includes Player, Dice, Stage, Move, Enemy, Boss and BossMove.  

Inheritance is used between some classes. Boss is inherited from Enemy and BossMove is inherited from Move.

# How Linked List Play a Role in the Game
Stage is a the linked list we used that contains Wave structure that act as nodes containing Boss class and Enemy class. 
We use the Wave(Node) to store the Boss and Enemies of every wave in a stage. That is that Wave 1 contains 1 goblin, or Wave 3 contains 
1 Wyvern(boss) for examples. With Wave, we can keep moving forward every time the wave ends to load the next Wave in a Stage. That is how
Wave are used to make it simpler to load data of the enemies in the wave in stages of the game.

# Screenshots

# Game Demo Video
https://www.youtube.com/watch?v=jCkClFeZVwY
