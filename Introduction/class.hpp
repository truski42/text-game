#pragma once
#define CLASS_HPP_
#ifdef CLASS_HPP_
#include <iostream>
#include "playerPick.hpp"
class Hero{
    public:
    int shopChoice, coins;
    virtual void addStats() = 0;
    virtual void losehp() = 0;
    virtual void currentStats() = 0;
};
class Warrior: public Hero{
    public:
    int hp = 10, strenght = 6, agility = 5, totalHP = hp, coins = 10;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << totalHP << std::endl;
        std::cout << "Strenght: " << strenght << std::endl;
        std::cout << "Agility: " << agility << std::endl;
        std::cout << "Coins: " << coins << std::endl;
    }
    virtual void losehp(){ // losing hp
        totalHP = totalHP - 1;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
    virtual void addStats(){
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
};
class Mage: public Hero{
    public:
    int hp = 6, inteligence = 10, mana = 5, totalHP = hp, coins = 10;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << totalHP << std::endl;
        std::cout << "Inteligence: " << inteligence << std::endl;
        std::cout << "Mana: " << mana << std::endl;
        std::cout << "Coins: " << coins << std::endl;
    }
    virtual void losehp(){ //losing hp
    totalHP = totalHP - 1;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
    virtual void addStats(){
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> shopChoice;
        if(shopChoice == 1){
            coins = coins - 1;
            inteligence = inteligence + 1;
            std::cout << "Narrator: You have purchased a staff which gives you +1 to strength" << std::endl;
            std::cout << "Narrator: Your current strenght is: " << inteligence << " your coins: " << coins << std::endl;
        } else if (shopChoice == 2){
            coins = coins - 1;
            totalHP = totalHP + 1;
            std::cout << "Narrator: You have purchased a magic robe which gives you +1 to health" << std::endl;
            std::cout << "Narrator: Your current hp is: " << totalHP << " your coins: " << coins << std::endl;      
        } else if(shopChoice == 3){
            coins = coins - 1;
            mana = mana + 1;
            std::cout << "Narrator: You have purchased a ring which gives you +1 to agility" << std::endl;
            std::cout << "Narrator: Your current hp is: " << mana << " your coins: " << coins << std::endl;
        } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }
    }
};
#endif