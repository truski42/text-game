#pragma once
#include <iostream>
class Hero{
    public:
    virtual void losehp() = 0;
    virtual void currentStats() = 0;
};
class Warrior: public Hero{
    public:
    int hp = 10;
    int strenght = 6;
    int agility = 5;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << hp << std::endl;
        std::cout << "Strenght: " << strenght << std::endl;
        std::cout << "Agility: " << agility << std::endl;
    }
    virtual void losehp(){ // losing hp
        std::cout << "Narrator: Your current life is: " << hp - 1 << std::endl;
    }
};
class Mage: public Hero{
    public:
    int hp = 6;
    int inteligence = 10;
    int mana = 5;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << hp << std::endl;
        std::cout << "Inteligence: " << inteligence << std::endl;
        std::cout << "Mana: " << mana << std::endl;
    }
    virtual void losehp(){ //losing hp
        std::cout << "Narrator: Your current life is: " << hp - 1 << std::endl;
    }
};

