#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "Introduction\langEN.hpp"
#include "Introduction\playerPick.hpp"
#include "Introduction\dialog.hpp"
#include "Move\move.hpp"

int main(){
    srand( time( NULL ) );
    en menuEN;
    smallTalk dialog;
    chooseClass player;
    move move;
    system("cls");
    std::cout << "\n----------------------WELCOME TO TEXT GAME----------------------\n";
    menuEN.introducitonEN(); // intro
    player.getClass(); // player choose class
    dialog.dialog(); // first diolog with mayor
    move.movePlayer(); // first chapter

   /* int choiceLang;
    std::cout << "\n---------Select game language----------";
    std::cout << "\n1. EN\n" << "2. PL" << std::endl;
    std::cin >> choiceLang;
    do{
        switch(choiceLang){
            case 1: 
            system("cls");
            menuEN.introducitonEN();
            break;
            case 2:
            system("cls");
            menuPL.introducitonPL();
            break;
        }
    }while(choiceLang != 1 && choiceLang != 2);
    */
}
/*void pl::introducitonPL(){
    int choice;
    char nick[50]; 
    std::cout << "Wyruszyłeś w długą podróż w poszukiwaniu nowych przygód i dobrego zarobku, ponieważ twoja wioska została zajęta przez wrogą armię, a wszyscy osadnicy zostali wytępieni.\nPo kilku długich i wyczerpujących dniach wędrówki dotarłęś do osady, gdzie przywitał cię miejscowy burmistrz.\n" << std::endl;
    std::cout << "Witam, nazywam się Leo, jestem tutaj sołtysem." << std::endl;
    std::cout << "Jak się nazywasz, nieznajomy?" << std::endl; // insert name.
    std::cin.getline(nick, 50);
    std::cout << "Witaj " << nick << ". Co sprowadza Cię do naszej wioski ?" << std::endl;
    do{
    std::cout << "\n----------Dokonaj wyboru----------" << std::endl; // Making choice for 
    std::cout << "1. Szukałem nowych przygód i nowych zadań." << std::endl;
    std::cout << "2. Po prostu zgubiłem się wracając do domu i trafiłem do waszej wioski." << std::endl;
    std::cout << "3. Co cię to obchodzi." << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Trafiłeś we właściwe miejsce " << nick << ", nasza wioska dostarczy Ci wrażeń." << std::endl;
        break;
    case 2:
        std::cout << "Co za kretyn! Jak mogłeś zgubić drogę do domu." << std::endl;
        break;
    case 3:
        std::cout << "Trochę kultury! Czy twoja matka cię nie wychowała ?" << std::endl;
        break;
    default:
        std::cout << "Nie rozumiem, co mówisz, możesz powtórzyć ?" << std::endl;
        break;
    }
    }while(choice != 1 && choice != 2 && choice != 3);
}
*/