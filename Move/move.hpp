#pragma once
#define MOVE_HPP_
#ifdef LANGEN_HPP_
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "..\Introduction\langEN.hpp"
#include "..\Chapter_one\chapter_one.hpp"
struct walking{ 
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

struct chapterOne{
	bool istavern = false;
	bool isblacksmith = false;
	void random(){ // event draw1
		int random;
		for(int i = 1; i<2; i++){
			random = rand()%10;
			if(random >= 0 && random <= 5){
				std::cout << "You came across a tavern\n";
				istavern = true;
			}else if (random >= 6 && random < 11){
				std::cout << "You came across the local blacksmith\n";
				isblacksmith;
			}
		} 
		std::cout << random;
		Sleep(1000);
	}
	void goIn(){
		if(istavern == true){
			goinTavern();
		} else if(istavern == false){
			goinBlacksmith();
		}
	}
	void goinBlacksmith(){
		blacksmith talk;
		talk.blacksmith_action();
	}
	void goinTavern(){ // funcition what we should do
		tavern action;
		blacksmith talk;
		char choiceGo_In;
		std::cout << "Narrator: Do you want to go inside, enter 'y' or 'n'" << std::endl;
		retry:
		std::cout << "[1]. Yes" << std::endl;
		std::cout << "[2]. No" << std::endl;
		std::cin >> choiceGo_In;
		if(choiceGo_In == 'y' || choiceGo_In == 'Y'){
			action.tavern_action();
		} else if (choiceGo_In == 'n' || choiceGo_In == 'N'){
			w.explore();
			std::cout << "You came across the local blacksmith\n";
			talk.blacksmith_action();
		}else{
			std::cout << "Narrator: You are doing it wrong, warrior! Press either 'y' or 'n', nothing else!" << std::endl;
			goto retry;
		}
	}
	walking w;
	void random1(){ // event draw2
		w.explore();
		int random;
		for(int i = 1; i<2; i++){
			random = rand()%10;
			if(random > 0 && random <10){
				std::cout << "You came across a oops";
			}
		} 
		Sleep(1000);
	}
};
struct move: public en
{
	chapterOne r;
    void movePlayer(){ // here we are doing first chapter decision
        system("cls");
	int choiceOne_Path;
	std::cout << "Narrator: What would you like to do?" << std::endl;
	std::cout << "\t >> Enter '1' to follow the mayor to city hall." << std::endl;
	std::cout << "\t >> Enter '2' to look around the village on your own." << std::endl;
	retry:
	std::cout << "\nEnter your choice: ";
	std::cin >> choiceOne_Path;
	if(choiceOne_Path == 1)
	{
		std::cout << "\n!!!----------------------Chapter One: East Hatley----------------------!!!" << std::endl;
		std::cout << "\nYou: Why are you leading me to city hall??" << std::endl;
		std::cout << "Mayor: Soon you will know. Just follow me." << std::endl;
		std::cout << "# You run behind the mayor." << std::endl;
	}
	else if(choiceOne_Path == 2)
	{
		system("cls");
		std::cout << "Walking." << std::endl;
		Sleep(1000);
		system("cls");
		std::cout << "Walking.." << std::endl;
		Sleep(1000);
		system("cls");
		std::cout << "Walking..." << std::endl;
		Sleep(1000);
		r.random();
		r.goIn();
	}
	else
	{
		std::cout << "You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
		goto retry;
	}
	std::cout << "\n----------------------Press any key to continue----------------------" << std::endl;
	_getch();
    }
};
#endif