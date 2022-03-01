#pragma once
#ifndef CLASS_HPP_
#define CLASS_HPP_
#include <iostream>
#include "playerPick.hpp"
#include <math.h>
class Hero{
    public:
    std::string monsterName [5] = { "Witch", "Werewolf", "Goblin", "Centaur", "Dwarf"};
    int currentMonsterNames = 5;
    std::string currentMonster = " ";
    int shopChoice, coins, choice, potion, totalPotion, monsterHP, monsterLevel, monsterXP;
    virtual void addStats() = 0;
    virtual void losehp() = 0;
    virtual void currentStats() = 0;    
    virtual void addLike() = 0;
    virtual void minusLike() = 0;
    virtual void addPotion() = 0;
    virtual void HUD() = 0;
    virtual void actionForest() = 0;
    virtual void CreateMonster() = 0;
    virtual void Combat() = 0;
    virtual void CombatHUD() = 0;
    virtual void LevelUP() = 0;
};
class Warrior: public Hero{
    public:
    // STATS
    int hp = 100, strenght = 6, agility = 5, coins = 10, like = 0, totalLike = like, smallPotion = 0, middPotion = 0, bigPotion = 0, totalHP = hp, temp;
    // LVL, XP etc
    int level = 1, maxHealth = totalHP, heal = 0;
    
    int current_xp = 0, base_xp = 83, xp_to_level = base_xp, minLevel = 1, maxLevel = 20;
    virtual void currentStats(){ // info about stats
        std::cout << "Health: " << totalHP << std::endl;
        Sleep(150);
        std::cout << "Strenght: " << strenght << std::endl;
        Sleep(150);
        std::cout << "Agility: " << agility << std::endl;
        Sleep(150);
        std::cout << "Coins: " << coins << "         Likability level: " << totalLike << std::endl;
    }
    virtual void losehp(){ // losing hp
        totalHP = totalHP - 10;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
    virtual void addStats(){ // adding stats from buying items in blacksmith
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> shopChoice;
        if(shopChoice == 1){
            coins = coins - 1;
            strenght = strenght + 1;
            std::cout << "Narrator: You have purchased a long sword which gives you +1 to strength" << std::endl;
            std::cout << "Narrator: Your current strenght is: " << strenght << " your coins: " << coins << std::endl;
        } else if (shopChoice == 2){
            coins = coins - 1;
            totalHP = totalHP + 1;
            std::cout << "Narrator: You have purchased a Plate armor which gives you +1 to health" << std::endl;
            std::cout << "Narrator: Your current hp is: " << totalHP << " your coins: " << coins << std::endl;      
        } else if(shopChoice == 3){
            coins = coins - 1;
            agility = agility + 1;
            std::cout << "Narrator: You have purchased a Light boots which gives you +1 to agility" << std::endl;
            std::cout << "Narrator: Your current hp is: " << agility << " your coins: " << coins <<std::endl;
        } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }
    }
    virtual void addLike(){ // adding 1 point of like
        totalLike = totalLike + 1;
        std::cout << "# Likability level is: " << totalLike << std::endl;
    }
    virtual void minusLike(){ // minus 1 point of like
        totalLike = totalLike - 1;
        std::cout << "# Likability level is: " << totalLike << std::endl;
    }
    virtual void addPotion(){ // adding 1 bottle of potion 
        retry:
        std::cout << "[1]. Small HP bottle [+1 HP, -1 coin]" << std::endl;
        std::cout << "[2]. Medium HP bottle [+2 HP, -3 coin]" << std::endl;
        std::cout << "[3]. Big HP bottle [+3 HP, -5 coin]" << std::endl;
        std::cin >> choice;
        if(choice == 1){
            smallPotion = smallPotion + 1;
            coins = coins - 1;
            std::cout << "You have " << smallPotion << " small bottle" << std::endl;
        }else if(choice == 2){
            middPotion = middPotion + 1;
            coins = coins - 3;            
            std::cout << "You have " << middPotion << " medium bottle"<< std::endl;
        }else if(choice == 3){
            coins = coins - 5;
            bigPotion = bigPotion + 1;
            std::cout << "You have " << bigPotion << " big bottle"<< std::endl;
        }else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl; 
            goto retry;
        }
    }
////////////////////////////////////////////////////////////////////////////////
                            //CHAPTER FOREST//
    virtual void HUD(){ // HUD player in forest
        std::cout << "Name: " << name << "              |Health: " << totalHP << std::endl;
        std::cout << "Level: " << level << "                  |Coins: " << coins << std::endl;
        std::cout << "XP: " << current_xp << "                     |Strenght: " << strenght << std::endl;
        std::cout << "XP to level up: " << xp_to_level << "        |Agility: " << agility << std::endl;
        actionForest();
    }
    virtual void CombatHUD(){
        Sleep(500);
        system("cls");
        std::cout << "Name: " << name << "    |       Monster Name: " << currentMonster << "\nHealth: " << totalHP << "      |       Monster Health: " <<
            monsterHP << "\nLevel: " << level << "        |       Monster Level: " << monsterLevel << std::endl;
    }
    virtual void Combat(){

        CombatHUD();
        int playerAttack;
        int playerDamage = strenght;
        int monsterAttack = 6 * monsterLevel / 2;

        if(totalHP >= 1 && monsterHP >= 1){
            std::cout << "\n";
            std::cout << "[1]. Attack\n";
            std::cout << "[2]. Block\n";
            std::cout << "[3]. RUN!\n";
            std::cout << "\n";
            std::cin >> playerAttack;

            if(playerAttack == 1){//ATTACK
                std::cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << std::endl;
                monsterHP = monsterHP - playerDamage;
                Sleep(2000);
                CombatHUD();
                    if(monsterHP >= 1){
                        std::cout << "\n";
                        std::cout << "Monster is Attacking...\n";
                        totalHP = totalHP - monsterAttack;
                        std::cout << "You suffered " << monsterAttack << " hp " << totalHP << std::endl;
                        //change to fuction
                        if(totalHP <= 0){
                            totalHP = 0;
                            system("cls");
                            std::cout << "You died! \nYou were level: " << level << " you got killed by " << currentMonster << std::endl;
                            Sleep(2000);
                            exit(0);                            
                        }
                    } else if (monsterHP <= 0){
                        monsterHP = 0;
                        std::cout << "\n";
                        std::cout << "You Defeated " << currentMonster << " you are rewarded with " << monsterXP << " xp.\nWell Done!\n";
                        
                        if(level != maxLevel){
                            current_xp += monsterXP;
                            LevelUP();
                        }

                        Sleep(2000);   
                        HUD();                      
                    }
                    Sleep(2000);
                    Combat();
            } else if(playerAttack == 2){//BLOCK
                std::cout << "Blocking\n";
                int i = rand() % agility + 1;
                if(i >= agility){
                    std::cout << "You Blocked the incoming attack\n";
                    heal = level * 10 / 2;
                    std::cout << "You have been Healed for " << heal << std::endl;
                    totalHP += heal;
                    Sleep(1000);
                    Combat();
                }else {
                    std::cout << "You failed to block the savage attack\n";
                    totalHP -= monsterAttack;
                    std::cout << "You were stabbed in the back for " << monsterAttack << " current hp " << totalHP << std::endl;
                    Sleep(1000);
                    Combat(); 
                }
            } else if(playerAttack == 3){//RUN
                std::cout << "You try to run\n";
                int x = rand() % 100 + 1;
                if(x >= 50){
                    std::cout << "You run away\n";
                    HUD();
                } else {
                    std::cout << "You failed to run away\n";
                    std::cout << "Monster does a savage attack on you!\n";
                    totalHP -= monsterAttack + 10;
                    std::cout << "You suffered " << monsterAttack + 10 << "Your current Health is " << totalHP << std::endl;
                    Sleep(1000);
                    Combat();
                }
            }else{
                std::cout << "Invalid number";
                Sleep(500);
                Combat();
            }
        }
    }    
    virtual void actionForest(){ // Searching for monsters in forest
        std::cout << "[1]. Searching the front area" << std::endl;
        std::cout << "[2]. Rest" << std::endl;
        std::cout << "[3]. Searching the backwards area";
        std::cout << "\n\n";

        std::cin >> choice;

        if(choice == 1){
            temp = rand() % 100 + 1;
            std::cout << "# You begin search forward...\n";
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        } else if(choice == 2){
            std::cout << "You want to set up camp for the evening\n";
            if(totalHP <=99){
                totalHP += 5 * level;
            }
            std::cout << "You healed by resting. Health is now: " << totalHP << std::endl; 
            Sleep(1000);
            HUD();
        } else if(choice == 3){
            temp = rand() % 100 + 1;
            std::cout << "# You begin search backwards...\n";
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        }else{
            std::cout << "Invalid number";
            Sleep(500);
            actionForest();
        }
    }    
    virtual void LevelUP(){ // LVL UP
        if(current_xp >= xp_to_level){
            xp_to_level += floor(level + 25 * pow(2, level / 7));
            totalHP = floor(totalHP + 13 * pow(2, level /8));

            if(level >= minLevel && level <= maxLevel){
                level++;
            } else{
                level = 20;
            }
            maxHealth = totalHP;
            std::cout << "Wait whats this a level up! you are now level " << level << std::endl;
            std::cout << "You have 1 power point to give away" << std::endl;
            retry:
            std::cout << "[1]. +1 Strenght" << std::endl;
            std::cout << "[2]. +1 Agility" << std::endl;
            std::cin >> choice;
            if(choice == 1){
                strenght += 1;
                std::cout << "now u have " << strenght;
            } else if(choice == 2){
                agility += 1;
                std::cout << "now u have " << agility;
            } else {
                goto retry;
            }
            std::cout << "Your total health increased now your health is " << totalHP << std::endl;
            std::cout << "\n";
            Sleep(1000);
            LevelUP();
        }
            Sleep(2000);
            HUD();
    }
    virtual void CreateMonster(){ // Create Monsters
        monsterHP = 30;

        monsterLevel = (rand() % 3) + level;
        monsterHP = (rand() % 30) * monsterLevel;

        monsterXP = monsterHP;

        if(monsterHP == 0)
            CreateMonster();
        if(monsterLevel == 0)
            CreateMonster();
    }
///////////////////////////////////////////////////////////////////////////////
};
class Mage: public Hero{
    public:
    int hp = 60, inteligence = 10, mana = 5, coins = 10, like = 0, totalLike = like, smallPotion = 0, middPotion = 0, bigPotion = 0;
    int level = 0, xp = 0, maxHealth = 0, nextLevel = 0, heal = 0, totalHP = hp, temp;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << totalHP << std::endl;
        std::cout << "Inteligence: " << inteligence << std::endl;
        std::cout << "Mana: " << mana << std::endl;
        std::cout << "Coins: " << coins << " Likability level: " << totalLike << std::endl;
    }
    virtual void losehp(){ //losing hp
    totalHP = totalHP - 1;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
    virtual void addStats(){ // adding stats from buying items in blacksmith
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> shopChoice;
        if(shopChoice == 1){
            coins = coins - 1;
            inteligence = inteligence + 1;
            std::cout << "Narrator: You have purchased a staff which gives you +1 to inteligence" << std::endl;
            std::cout << "Narrator: Your current strenght is: " << inteligence << " your coins: " << coins << std::endl;
        } else if (shopChoice == 2){
            coins = coins - 1;
            totalHP = totalHP + 1;
            std::cout << "Narrator: You have purchased a magic robe which gives you +1 to health" << std::endl;
            std::cout << "Narrator: Your current hp is: " << totalHP << " your coins: " << coins << std::endl;      
        } else if(shopChoice == 3){
            coins = coins - 1;
            mana = mana + 1;
            std::cout << "Narrator: You have purchased a ring which gives you +1 to mana" << std::endl;
            std::cout << "Narrator: Your current hp is: " << mana << " your coins: " << coins << std::endl;
        } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }
    }
    virtual void addLike(){ // adding 1 point of like
        totalLike = totalLike + 1;
        std::cout << "# Likability level is: " << totalLike << std::endl;
    }
    virtual void minusLike(){ // minus 1 point of like
        totalLike = totalLike - 1;
        std::cout << "# Likability level is: " << totalLike << std::endl;
    }
    virtual void addPotion(){ // adding 1 bottle of potion 
        retry:
        std::cout << "[1]. Small HP bottle [+1 HP, -1 coin]" << std::endl;
        std::cout << "[2]. Medium HP bottle [+2 HP, -3 coin]" << std::endl;
        std::cout << "[3]. Big HP bottle [+3 HP, -5 coin]" << std::endl;
        std::cin >> choice;
        if(choice == 1){
            smallPotion = smallPotion + 1;
            coins = coins - 1;
            std::cout << "You have " << smallPotion << " small bottle"<< std::endl;
        }else if(choice == 2){
            middPotion = middPotion + 1;
            coins = coins - 3;            
            std::cout << "You u have " << middPotion << " medium bottle"<< std::endl;
        }else if(choice == 3){
            coins = coins - 5;
            bigPotion = bigPotion + 1;
            std::cout << "You u have " << bigPotion << " big bottle"<< std::endl;
        }else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl; 
            goto retry;
        }
    }
    virtual void HUD(){ // HUD player in forest
        nextLevel = 70;
        std::cout << "Name: " << name << "         Health: " << totalHP << std::endl;
        std::cout << "Level: " << level << "         Coins: " << coins << std::endl;
        std::cout << "XP: " << xp << "         Inteligence: " << inteligence << std::endl;
        std::cout << "XP to level up: " << nextLevel << "         Mana: " << mana << std::endl;
    }
    virtual void actionForest(){ // Searching for monsters in forest
        std::cout << "[1]. Searching the front area" << std::endl;
        std::cout << "[2]. Rest" << std::endl;
        std::cout << "[3]. Searching the backwards area";
        std::cout << "\n\n";

        std::cin >> choice;

        if(choice == 1){
            temp = rand() % 100 + 1;
            std::cout << "# You begin search forward...\n";
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        } else if(choice == 2){
            std::cout << "You want to set up camp for the evening\n";
            if(totalHP <=99){
                totalHP += 10 * level;
            }
            std::cout << "You healed by resting. Health is now: " << totalHP << std::endl; 
            Sleep(1000);
            HUD();
        } else if(choice == 3){
            temp = rand() % 100 + 1;
            std::cout << "# You begin search backwards...\n";
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        }else{
            std::cout << "Invalid number";
            Sleep(500);
            actionForest();
        }
    }
    virtual void CreateMonster(){}
    virtual void CombatHUD(){}
    virtual void Combat(){}
    virtual void LevelUP(){}
};
#endif