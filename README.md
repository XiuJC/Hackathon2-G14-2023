# Hackathon2-G14-2023
This project ts to make a game using OOP and linked list to show our understandings.

Group 14
> Cheng Jia Xiu (164649)   
> Chia Jie Lun (163659)   
> Vimal S/O Ravichandran (162601)

Game Title:
REDEMPTION

# Game Description
In this game, you play as a dwarf warrior deeping into a dungeon.
You are once a member in the hero party which had slained the evil dragon.
After the journey ended, you had left from your party and enjoyed peaceful days.  

One day, you ex-party members were on their mission to explore a dungeon and defeat a Lich living inside.
For some reason, they had been trapped inside the dungeon.
You are recruited to investigate the truth behind this mystery. 

# Game Feature
- Traditional Turn-based Combat
- RNG Mechanic Providing Diverse Gameplay Experience
- Multiple Endings
- Auto-Saving Game Progress

# How to Play
During the combat, you will be asked to **ENTER YOUR MOVE's NAME** to use them.  
These moves include  

1. **AxeStrike**   --> A steady move dealing single-target damage to an enemy.  
2. **Swipe**       --> An AOE move dealing damage to all the enemies you currently encounter.  
3. **Guillotine**  --> A heavy move (has lower accuracy) dealing significant damage to an enemy.  
4. **Concentrate** --> A status move that boosts your next move's power and accuracy.

# Object-oriented concepts in the game
The game consists of several classes to define their respective objects.  

These class includes Player, Dice, Stage, Move, Enemy, Boss and BossMove.  

Inheritance is used between some classes. Boss is inherited from Enemy and BossMove is inherited from Move.

Stage is a the linked list we used that contains Wave structure that contains Boss class and Enemy class.
