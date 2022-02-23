#pragma once
#define CHAPTER_ONE_HPP_
#ifdef MOVE_HPP_
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "..\Move\move.hpp"
#include "..\Introduction\langEN.hpp"
#include "..\Introduction\class.hpp"
#include "..\Chapter_two\chapter_two.hpp"
void walk();
void tavern();
void tavernMenu();
void blacksmith();
void blacksmithMenu();
class village{
    public:
    int choice;
    Hero *infoHP;
    Warrior statsW;
    Mage statsM;
    town_hall next;
    void walk(){// exploring
        system("cls");
		std::cout << "Walking." << std::endl;
		Sleep(1000);
		system("cls");
		std::cout << "Walking.." << std::endl;
		Sleep(1000);
		system("cls");
		std::cout << "Walking..." << std::endl;
		Sleep(1000);
    }
    void tavern(){ //action in tavern
        system("cls");
        std::cout << "Narrator: You slowly enter the tavern..." << std::endl;
        Sleep(2000);
        std::cout << "Narrator: The locals immediately notice that you are a stranger and direct their attention to you. " << std::endl;
        Sleep(4000);
        std::cout << "Narrator: Behind the counter is a barman." << std::endl;
        Sleep(2000);
        std::cout << "\nBarman: Hey " << name << " what to get you ?" << std::endl;
        Sleep(3000);
        std::cout << "You: Does everyone in this village already know who I am!?" << std::endl;
        Sleep(3000);
        std::cout << "Barman: Why are you so hotheaded ?\n" << std::endl;
        Sleep(2000);
        tavernMenu();
        }
    void tavernMenu(){// menu tavern
        std::cout << "Barman: Doesn't matter what I give you ?" << std::endl;
        std::cout << "[1]. Beer, please." << std::endl;
        std::cout << "[2]. Tell me a little about your village." << std::endl;
        std::cout << "[3]. Exit" << std::endl;
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        if(choice == 1){
            system("cls");
            std::cout << "Narrator: The bartender hands you a beer, you drink it right away." << std::endl;
            Sleep(3000);
            std::cout << "Narrator: You like the local beer so much that you buy three more." << std::endl;
            Sleep(3000);
            std::cout << "Narrator: After a few beers you are already drunk and get into a fight." << std::endl;
            Sleep(3000);
            std::cout << "Narrator: You were not able to fight and you lose one hp" << std::endl;
            if(playerSelect == 1){
                infoHP = &statsW;
                infoHP ->losehp();
                Sleep(2000);
            }else if (playerSelect == 2){
                infoHP = &statsM;
                infoHP ->losehp();
            }
            std::cout << "\n# They throw you out of the tavern";
            Sleep(3000);
            walk();
            std::cout << "You came across the local blacksmith\n";
            blacksmith();
        } else if (choice == 2){
            system("cls");
            Sleep(1000);
            std::cout << "Barman: I know as much as my parents told me, but Leo has been in charge here since I was a kid, I don't know how old this guy is anymore." << std::endl;
            Sleep(4000);
            std::cout << "Barman: There's been better years where we've had plenty, and there's been years like this where we can barely get by." << std::endl;
            Sleep(4000);
            std::cout << "Barman: We don't know if it's because of him, but maybe you can help him." << std::endl;
            Sleep(4000);
            std::cout << "You: How am I supposed to help him?" << std::endl;
            Sleep(4000);
            std::cout << "Barman: You'll have to talk to Leo.\n" << std::endl;
            tavernMenu();
        } else if(choice == 3){
            std::cout << "# You leave the tavern";
            Sleep(2000);
            walk();
            std::cout << "You came across the local blacksmith\n";
            blacksmith();              
        }else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }        
        }
    void blacksmith(){ //blacksmith action
        Sleep(2000);
        system("cls");
        std::cout << "Blacksmith: Hello " << name << " what brings you to me ?" << std::endl;
        Sleep(4000);
        std::cout << "You: How do you know who I am ?" << std::endl;
        Sleep(4000);
        std::cout << "Blacksmith: It's rare for a new face to show up here and our ladies have already started gossiping about the newcomer." << std::endl;
        Sleep(4000);
        if(playerSelect == 1){
                infoHP = &statsW;
                infoHP ->currentStats();
                Sleep(2000);
        }else if (playerSelect == 2){
                infoHP = &statsM;
                infoHP ->currentStats();
        }
        Sleep(2000);
        blacksmithMenu();        
        }
    void blacksmithMenu(){ // blacksmith menu
        std::cout << "Blacksmith: What checks you into my humble props ?" << std::endl;        
        std::cout << "[1]. Show me your stuff." << std::endl;
        std::cout << "[2]. Tell me a little about your village." << std::endl;
        std::cout << "[3]. Exit" << std::endl;
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        if(choice == 1){
            if(playerSelect == 1){
                std::cout << "[1]. Long sword [+1 strenght, -1 coin]" << std::endl;
                std::cout << "[2]. Plate armor [+1 health, -1 coin]" << std::endl;
                std::cout << "[3]. Light boots [+1 agility, -1 coin]" << std::endl;
                /*std::cout << "\nEnter your choice: ";
                std::cin >> infoHP ->shopChoice;*/
                infoHP ->addStats();
                std::cout << "# You leave the blacksmith";
                Sleep(4000);
                walk();
                next.HUD();
                // need to do funciton about next chapter
            } else if(playerSelect == 2){
                std::cout << "[1]. Staff [+1 inteligence, -1 coin]" << std::endl;
                std::cout << "[2]. Magic robe [+1 health, -1 coin]" << std::endl;
                std::cout << "[3]. Ring [+1 mana, -1 coin]" << std::endl;
                infoHP ->addStats();
                Sleep(4000);
                std::cout << "# You leave the blacksmith";
                walk();
                next.HUD();
            }
        } else if (choice == 2){
            system("cls");
            Sleep(1000);
            std::cout << "Barman: I know as much as my parents told me, but Leo has been in charge here since I was a kid, I don't know how old this guy is anymore." << std::endl;
            Sleep(4000);
            std::cout << "Barman: There's been better years where we've had plenty, and there's been years like this where we can barely get by." << std::endl;
            Sleep(4000);
            std::cout << "Barman: We don't know if it's because of him, but maybe you can help him." << std::endl;
            Sleep(4000);
            std::cout << "You: How am I supposed to help him?" << std::endl;
            Sleep(4000);
            std::cout << "Barman: You'll have to talk to Leo.\n" << std::endl;
            blacksmithMenu();
        } else if(choice == 3){
            std::cout << "# You leave the blacksmith";
            Sleep(2000);
            walk();
            next.HUD();
        } 
        else {
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;           
        }
    }
};
#endif