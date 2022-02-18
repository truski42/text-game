#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "class.hpp"
class chooseClass
{
private:
    std::string playerSelect;
    std::string hero;

public:
    void getClass(){
        Warrior p1;
        Mage p2;
        do{
            std::cout << "\nWhats your class?"; // choosing class
            std::cout << "\n[1]. Warrior [2]. Mage";
            std::cout << "\nChoose a class: ";
            std::cin >> playerSelect;
        
                if(playerSelect == "1"){
                    system("cls");
                    std::cout << "You have chosen a Warrior\n" << "Here are your stats:" << std::endl;
                    std::cout << "HP: " << p1.hp << std::endl;
                    std::cout << "Strenght: " << p1.strenght << std::endl;
                    std::cout << "Agility: " << p1.agility << std::endl; 
                }else if (playerSelect == "2"){
                    system("cls");
                    std::cout << "You have chosen a Mage\n" << "Here are your stats:" << std::endl;
                    std::cout << "HP: " << p2.hp << std::endl;
                    std::cout << "Intelligence: " << p2.intelligence << std::endl;
                    std::cout << "Mana: " << p2.mana << std::endl; 
                } else{
                    std::cout << "\nPress either '1' or '2', nothing else!";
                }
        }while(playerSelect != "1" && playerSelect != "2");
    }
};