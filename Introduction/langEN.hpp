#pragma once
#ifndef LANGEN_HPP_
#define LANGEN_HPP_ 
#include <iostream>
    char nick[50];
    char *name = nick;
    bool Intro = true;
class en {
    
    public: 
    void introducitonEN(){
        std::string Intro_story = "Narrator: You have set out on a long journey in search of new adventures and a good income,\n"
        "because your village has been taken over by the enemy army and all the settlers have been exterminated.\n"
        "After several long and exhausting days of wandering,\n"
        "you came upon a settlement, where you were greeted by the local mayor.\n";
        if(Intro)
        {
            int i = 0;
            while (Intro_story[i] != '\0'){
                std::cout << Intro_story[i];
                Sleep(80);
                i++;
            }
            Intro = false;
        }
    std::cout << "Mayor: Hello, my name is Leo, I'm the village chief here." << std::endl;
    std::cout << "Mayor: What's your name, stranger?" << std::endl; // insert name.

    std::cout << "Enter your name: ";
    std::cin.getline(nick, 50);
    }
};
#endif
