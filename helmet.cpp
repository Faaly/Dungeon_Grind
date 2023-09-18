#include "helmet.h"

Helmet::Helmet(std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl){
    Name = aName;
    Strength = aStrength;
    Agility = aAgility;
    Stamina = aStamina;
    ItemLvl = aItemLvl;
} 

//getter n setter methods
std::string Helmet::get_Name(){
    return Name;
}

float Helmet::get_Strength(){
    return Strength;
}

float Helmet::get_Agility(){
    return Agility;
}

float Helmet::get_Stamina(){
    return Stamina;
}

int Helmet::get_ItemLvl(){
    return ItemLvl;
}