#include "weapon.h"

Weapon::Weapon(char aCat, std::string aName, float aStrength, float aAgilty, float aStamina, int aItemLvl){
    Cat = aCat;
    Name = aName;
    Strength = aStrength;
    Agility = aAgilty;
    Stamina = aStamina;
    ItemLvl = aItemLvl;
}

//getter n setter methods
char Weapon::get_Cat(){
    return Cat;
}

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