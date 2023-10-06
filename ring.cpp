#include "ring.h"

Ring::Ring(std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl){
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

//////////////////////////////////functions

void Ring::show_ringstats(){
    std::cout << "Cat : " << (this->Cat)
             << " , Name : " << (this->Name) << "\n" 
             << "Str : " << (this->Strength)
             << " , Agi : " << (this->Agility)
             << " , Sta : " << (this->Stamina)
             << " , iLvL : " << (this->ItemLvl) << std::endl;
}