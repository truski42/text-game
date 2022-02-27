#pragma once
#ifndef LANGEN_HPP_
#define LANGEN_HPP_ 
#include <iostream>
    char nick[50];
    char *name = nick;
class en {
    
    public: 
    void introducitonEN(){
    std::cout << "Narrator: You have set out on a long journey in search of new adventures and a good income, because your village has been taken over by the enemy army and all the settlers have been exterminated.\n\t  After several long and exhausting days of wandering, you came upon a settlement, where you were greeted by the local mayor.\n" << std::endl;
    std::cout << "Mayor: Hello, my name is Leo, I'm the village chief here." << std::endl;
    std::cout << "Mayor: What's your name, stranger?" << std::endl; // insert name.
    std::cout << "Enter your name: ";
    std::cin.getline(nick, 50);
    }
};
#endif
