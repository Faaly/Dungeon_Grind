#include "weapon.h"

Weapon::Weapon(std::string aName, float aStrength, float aAgilty, float aStamina, int aItemLvl){
    Name = aName;
    Strength = aStrength;
    Agility = aAgilty;
    Stamina = aStamina;
    ItemLvl = aItemLvl;
}

//getter n setter methods
std::string Weapon::get_Name(){
    return Name;
}

float Weapon::get_Strength(){
    return Strength;
}

float Weapon::get_Agility(){
    return Agility;
}

float Weapon::get_Stamina(){
    return Stamina;
}

int Weapon::get_ItemLvl(){
    return ItemLvl;
}