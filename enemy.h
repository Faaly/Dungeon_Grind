#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
#include "player.h"
#include "weapon.h"

class Enemy{

    //Member Variables 
        std::string Name;
        float Strength;
        float Agility;
        float Stamina;

    public:
        //Constructor
        Enemy() = default;
        Enemy(Player& Player);
        
        
        //Functions(Methods)
        void show_enemystats();
        


        //Getters n Setters
        std::string get_Name();
        float get_Strength();
        float get_Agility();
        float get_Stamina();
        int get_ItemLvl();
    
        
};

#endif