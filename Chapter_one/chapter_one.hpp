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
struct walk{ 
	void explore(){ // this funciton show u walking on screen
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
};
struct tavern: public en // structure performing actions in a tavern
{
    void tavern_action(){ 
        int choice;
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
        std::cout << "Barman: Why are you so hotheaded ?" << std::endl;
        Sleep(2000);
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
        } else if (choice == 2){
            system("cls");
            Sleep(1000);
            std::cout << "Barman: I know as much as my parents told me, but Leo has been in charge here since I was a kid, I don't know how old this guy is anymore." << std::endl;
            Sleep(4000);
            std::cout << "Barman: There's been better years where we've had plenty, and there's been years like this where we can barely get by." << std::endl;
            Sleep(4000);
            std::cout << "Barman: We don't know if it's because of him, but maybe you can help him.";
        } else if(choice == 3){
            system("cls");
            std::cout << "Narrator: You leave the tavern";
            Sleep(2000);
            walk exit;
            exit.explore();
        }else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }
    }
};
struct blacksmith: public en // structure making conversation with blacksmith
{
    void blacksmith_action(){
        Sleep(2000);
        system("cls");
        std::cout << "Blacksmith: Hello " << name << " what brings you to me ?" << std::endl;
        Sleep(4000);
        std::cout << "You: How do you know who I am ?" << std::endl;
        Sleep(4000);
        std::cout << "Blacksmith: It's rare for a new face to show up here and our ladies have already started gossiping about the newcomer.";
    }
};
#endif