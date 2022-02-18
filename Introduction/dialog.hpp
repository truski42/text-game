#pragma once
#define DIALOG_HPP_
#ifdef LANGEN_HPP_
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "langEN.hpp"
class smallTalk :public en{
    std::string choice;
public:
    void dialog(){
    Sleep(2000);
    system("cls");
    std::cout << "\n# Mayor: Hi " << name << ". What brings you to our village ?" << std::endl;
    do{
    std::cout << "\t >> [1]. I was looking for new adventures and new assignments." << std::endl;
    std::cout << "\t >> [2]. I just got lost on my way back home and ended up in your village." << std::endl;
    std::cout << "\t >> [3]. What do you care." << std::endl;
    std::cout << "\nMake your choice: "; // Making choice for 
    std::cin >> choice;
    if(choice == "1"){
        std::cout << "Mayor: You have come to the right place " << name << ", our village will give you an experience." << std::endl;
    } else if (choice == "2"){
        std::cout << "Mayor: What a moron! How could you lose your way home." << std::endl;
    } else if (choice == "3"){
        std::cout << "Mayor: A little culture! Didn't your mother raise you?" << std::endl;
    } else{
        system("cls");
        std::cout << "Mayor: I don't understand what you are saying, can you repeat it ?\nPress either '1' or '2' or '3', nothing else!" << std::endl;
    }
    }while(choice != "1" && choice != "2" && choice != "3");
    std::cout << "\n----------------------Press any key to move on----------------------" << std::endl;
    _getch();
    }
};
#endif