#include "bodyarmor.h"

Bodyarmor::Bodyarmor(char aCat, std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl){
    Cat = aCat;
    Name = aName;
    Strength = aStrength;
    Agility = aAgility;
    Stamina = aStamina;
    ItemLvl = aItemLvl;
} 

Bodyarmor::Bodyarmor(){
    Cat = 'B';
    Name = "None";
    Strength = 0;
    Agility = 0;
    Stamina = 0;
    ItemLvl = 0;
}

//getter n setter methods
char Bodyarmor::get_Cat(){
    return Cat;
}

std::string Bodyarmor::get_Name(){
    return Name;
}

float Bodyarmor::get_Strength(){
    return Strength;
}

float Bodyarmor::get_Agility(){
    return Agility;
}

float Bodyarmor::get_Stamina(){
    return Stamina;
}

int Bodyarmor::get_ItemLvl(){
    return ItemLvl;
}