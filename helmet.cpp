#include "helmet.h"

Helmet::Helmet(char aCat, std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl){
    Cat = aCat;
    Name = aName;
    Strength = aStrength;
    Agility = aAgility;
    Stamina = aStamina;
    ItemLvl = aItemLvl;
} 

Helmet::Helmet(){
    Cat = 'H';
    Name = "None";
    Strength = 0;
    Agility = 0;
    Stamina = 0;
    ItemLvl = 0;
}

//getter n setter methods
char Helmet::get_Cat(){
    return Cat;
}

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