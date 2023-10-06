#include "weapon.h"

Weapon::Weapon(std::string aName, float aStrength, float aAgilty, float aStamina, int aItemLvl){
    Cat = 'W';
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

void Weapon::show_weaponstats(){
    // TODO: add Level, Dungeon Level, Category
    std::cout << "Cat : " << (this->Cat)
             << " , Name : " << (this->Name) << "\n" 
             << "Str : " << (this->Strength)
             << " , Agi : " << (this->Agility)
             << " , Sta : " << (this->Stamina)
             << " , iLvL : " << (this->ItemLvl) << std::endl;
}