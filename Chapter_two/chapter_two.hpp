#pragma once
#define CHAPTER_TWO_HPP_
#ifdef MOVE_HPP_
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "..\Chapter_one\chapter_one.hpp"
#include "..\Introduction\class.hpp"
void nextChapter();
class town_hall{
    public:
    Hero *infoHP;
    Warrior statsW;
    void nextChapter(){
        system("cls");
        std::cout << "# After a few minutes, you finally arrived at the town hall." << std::endl;
        std::cout << "\nMayor: Well, " << name << " I have a very important matter for you." << std::endl;
        std::cout << "You: What's the matter ?" << std::endl;
        std::cout << "Mayor: Namely, from time to time we are attacked by monsters from the nearby forest," << std::endl;
        std::cout << "with difficulty we managed to repel the previous attack" << std::endl;
        std::cout << "You: Okey, I think I know what you're getting at. " << std::endl;
        std::cout << "Mayor: Are you able to help us deal with the monsters ?" << std::endl;
        if(playerSelect == 1){ 
                Sleep(2000);
        }else if (playerSelect == 2){
            }
    }
};
#endif