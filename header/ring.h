#ifndef RING_H
#define RING_H
#include <string>
#include <iostream>

class Ring{

    //Member Variables
        char Cat;
        std::string Name;
        float Strength;
        float Agility;
        float Stamina;
        int ItemLvl;

    public:
        //Constructor
        Ring();
        Ring(std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl);
        
        //Functions(Methods)

        void show_ringstats();
        void show_compare();

        //Getter n Setters
        char get_Cat();
        std::string get_Name();
        float get_Strength();
        float get_Agility();
        float get_Stamina();
        int get_ItemLvl();

        

};
#endif