#include "mainmenu.h"

#include <string>
#include <iostream>


std::string loading(){
    std::string loadingtext = "Loading function works";
    return loadingtext;
}

void mainmenu(){
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "(1) New Game" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "(2) Load Savefile" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "(3) Exit" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
}