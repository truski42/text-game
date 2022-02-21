#pragma once
#include <iostream>
class Hero{
    public:
    virtual void currentStats() = 0;
};
class Warrior: public Hero{
    public:
    int hp;
    int strenght;
    int agility;
    virtual void currentStats(){
        std::cout << "HP: " << 10 << std::endl;
        std::cout << "Strenght: " << 6 << std::endl;
        std::cout << "Agility: " << 5 << std::endl;
    }
};
class Mage: public Hero{
    public:
    int hp;
    int inteligence;
    int mana;
    virtual void currentStats(){
        std::cout << "HP: " << 6 << std::endl;
        std::cout << "Inteligence: " << 10 << std::endl;
        std::cout << "Mana: " << 10 << std::endl;
    }
};

