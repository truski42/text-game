#pragma once
#define CHAPTER_TWO_HPP_
#ifdef CHAPTER_ONE_HPP_
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "..\Chapter_one\chapter_one.hpp"
void HUD();
class town_hall{
    public:
    void HUD(){
        std::cout << "Mayor: I have a very important matter for you";
    }
};
#endif