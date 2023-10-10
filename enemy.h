#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>

class Enemy{

    //Member Variables 
        std::string Name;
        float Strength;
        float Agility;
        float Stamina;

    public:
        //Constructor
        Enemy() = default;
        Enemy(std::string aName, float aStrength, float aAgilty, float aStamina);
        
        //Functions(Methods)


        //Getters n Setters
        std::string get_Name();
        float get_Strength();
        float get_Agility();
        float get_Stamina();
        int get_ItemLvl();

    
        
};

#endif