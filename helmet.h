#ifndef HELMET_H
#define HELMET_H
#include <string>

class Helmet{
    public:
        //Constructor
        Helmet() = default;
        Helmet(std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl);

        //Functions(Methods)


        //Getter n Setters
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