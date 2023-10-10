#include "enemy.h"

Enemy::Enemy(std::string aName, float aStrength, float aAgilty, float aStamina){
    Name = aName;
    Strength = aStrength;
    Agility = aAgilty;
    Stamina = aStamina;
}


//getter n setter methods

std::string Enemy::get_Name(){
    return Name;
}

float Enemy::get_Strength(){
    return Strength;
}

float Enemy::get_Agility(){
    return Agility;
}

float Enemy::get_Stamina(){
    return Stamina;
}


