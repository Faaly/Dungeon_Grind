#ifndef RING_H
#define RING_H
#include <string>

class Ring{
    public:
        //Constructor
        Ring();
        Ring(char aCat, std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl);

        //Functions(Methods)


        //Getter n Setters
        char get_Cat();
        std::string get_Name();
        float get_Strength();
        float get_Agility();
        float get_Stamina();
        int get_ItemLvl();

        //Member Variables
        char Cat;
        std::string Name;
        float Strength;
        float Agility;
        float Stamina;
        int ItemLvl;

};
#endif