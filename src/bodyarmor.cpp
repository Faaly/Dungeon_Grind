#include "../header/bodyarmor.h"
#include <iomanip> // text formatierung

Bodyarmor::Bodyarmor(std::string aName, float aStrength, float aAgility, float aStamina, int aItemLvl){
    Cat = 'B';
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

//////////////////////////////////functions

void Bodyarmor::show_armorstats(){
    std::cout << "Cat : " << (this->Cat)
             << " , Name : " << (this->Name) << "\n" 
             << "Str : " << (this->Strength)
             << " , Agi : " << (this->Agility)
             << " , Sta : " << (this->Stamina)
             << " , iLvL : " << (this->ItemLvl) << std::endl;
}

void Bodyarmor::show_compare(){
    int side {20};
    std::cout << std::left;
    std::cout << std::setw(side) << "Name of Armor :" << (this->Name)
              << "             " << "\nStr : " << std::setw(side) << (this->Strength) <<  " Agi :" << std::setw(side) << (this->Agility) << " Sta : " << (this->Stamina) << std::endl;
    }