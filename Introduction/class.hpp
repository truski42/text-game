#pragma once
#include <iostream>
class Hero{
    public:
    virtual void losehp() = 0;
    virtual void currentStats() = 0;
};
class Warrior: public Hero{
    public:
    int hp = 10, strenght = 6, agility = 5, totalHP = hp;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << totalHP << std::endl;
        std::cout << "Strenght: " << strenght << std::endl;
        std::cout << "Agility: " << agility << std::endl;
    }
    virtual void losehp(){ // losing hp
        totalHP = totalHP - 1;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
};
class Mage: public Hero{
    public:
    int hp = 6, inteligence = 10, mana = 5, totalHP = hp;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << totalHP << std::endl;
        std::cout << "Inteligence: " << inteligence << std::endl;
        std::cout << "Mana: " << mana << std::endl;
    }
    virtual void losehp(){ //losing hp
    totalHP = totalHP - 1;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
};

