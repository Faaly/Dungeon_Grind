#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon{
    public:
        //Constructor
        Weapon() = default;
        Weapon(std::string aName, float aStrength, float aAgilty, float aStamina, int aItemLvl);
        
        //Functions(Methods)


        //Getters n Setters
        std::string get_Name();
        float get_Strength();
        float get_Agility();
        float get_Stamina();
        int get_ItemLvl();

        //Member Variables 
        std::string Name;
        float Strength;
        float Agility;
        float Stamina;
        int ItemLvl;
};



#endif