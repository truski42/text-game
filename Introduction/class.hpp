#pragma once
#ifndef CLASS_HPP_
#define CLASS_HPP_
#include <iostream>
#include "playerPick.hpp"
class Hero{
    public:
    int shopChoice, coins, choice, potion, totalPotion;
    virtual void addStats() = 0;
    virtual void losehp() = 0;
    virtual void currentStats() = 0;    
    virtual void addLike() = 0;
    virtual void minusLike() = 0;
    virtual void addPotion() = 0;
    virtual void HUD() = 0;
};
class Warrior: public Hero{
    public:
    int hp = 10, strenght = 6, agility = 5, coins = 10, like = 0, totalLike = like, smallPotion = 0, middPotion = 0, bigPotion = 0;
    int level = 0, xp = 0, maxHealth = 0, nextLevel = 0, heal = 0, totalHP = hp;
    virtual void currentStats(){ // info about stats
        std::cout << "Name: " << name << "         Health: " << totalHP << std::endl;
        std::cout << "Strenght: " << strenght << std::endl;
        std::cout << "Agility: " << agility << std::endl;
        std::cout << "Coins: " << coins << "         Likability level: " << totalLike << std::endl;
    }
    virtual void losehp(){ // losing hp
        totalHP = totalHP - 1;
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
    virtual void addPotion(){
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
    virtual void HUD(){
        std::cout << "Name: " << name << "         Health: " << totalHP << std::endl;
        std::cout << "Strenght: " << strenght << std::endl;
        std::cout << "Agility: " << agility << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "XP: " << xp << std::endl;
        std::cout << "XP to level up: " << nextLevel << std::endl;
        std::cout << "Coins: " << coins;
    }
};
class Mage: public Hero{
    public:
    int hp = 6, inteligence = 10, mana = 5, coins = 10, like = 0, totalLike = like, smallPotion = 0, middPotion = 0, bigPotion = 0;
    int level = 0, xp = 0, maxHealth = 0, nextLevel = 0, heal = 0, totalHP = hp;
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
    virtual void addPotion(){
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
    virtual void HUD(){

    }
};
#endif