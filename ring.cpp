#include "ring.h"

Ring::Ring(char aCat, std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl){
    Cat = aCat;
    Name = aName;
    Strength = aStrength;
    Agility = aAgility;
    Stamina = aStamina;
    ItemLvl = aItemLvl;
} 

Ring::Ring(){
    Cat = 'R';
    Name = "None";
    Strength = 0;
    Agility = 0;
    Stamina = 0;
    ItemLvl = 0;
}

//getter n setter methods
char Ring::get_Cat(){
    return Cat;
}

std::string Ring::get_Name(){
    return Name;
}

float Ring::get_Strength(){
    return Strength;
}

float Ring::get_Agility(){
    return Agility;
}

float Ring::get_Stamina(){
    return Stamina;
}

int Ring::get_ItemLvl(){
    return ItemLvl;
}