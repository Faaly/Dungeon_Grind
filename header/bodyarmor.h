#ifndef BODYARMOR_H
#define BODYARMOR_H
#include <string>
#include <iostream>

class Bodyarmor{

//Member Variables
        char Cat;
        std::string Name;
        float Strength;
        float Agility;
        float Stamina;
        int ItemLvl;

    public:
        //Constructor
        Bodyarmor();
        Bodyarmor(std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl);
        

        //Functions(Methods)

        void show_armorstats();
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