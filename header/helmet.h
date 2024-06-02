#ifndef HELMET_H
#define HELMET_H
#include <string>
#include <iostream>

class Helmet{

    //Member Variables
        char Cat;
        std::string Name;
        float Strength;
        float Agility;
        float Stamina;
        int ItemLvl;

    public:
        //Constructor
        Helmet();
        Helmet(std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl);

        //Functions(Methods)


        //Getter n Setters
        char get_Cat();
        std::string get_Name();
        float get_Strength();
        float get_Agility();
        float get_Stamina();
        int get_ItemLvl();

        
        void show_helmetstats();
        void show_compare();

};
#endif