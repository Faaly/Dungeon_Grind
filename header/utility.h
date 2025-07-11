#ifndef UTILITY_H
#define UTILITY_H

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void clearScreen();


#endif