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
        float currentHP = 0;

    public:
        //Constructor
        Enemy() = default;
        Enemy(Player& Player);
        
        
        //Functions(Methods)
        std::string enemy_name_capitalizer(std::string a);
        void show_enemystats();
        
        float get_maxhp();
        float get_maxdmg();
        float get_maxdef();

        //void attack;


        //Getters n Setters
        std::string get_Name();
        float get_Strength();
        float get_Agility();
        float get_Stamina();
        float get_currentHP();
        void set_currentHP(float currentHP);
        Player player;  
    
        
};

#endif