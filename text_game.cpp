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
    std::cout << "\n----------------------WELCOME TO TEXT GAME----------------------\n";
    menuEN.introducitonEN(); // intro
    player.getClass(); // player choose class
    dialog.dialog(); // first diolog with mayor
    move.movePlayer(); // first chapter

}