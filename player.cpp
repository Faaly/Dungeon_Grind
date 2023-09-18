#include "player.h"

Player::Player(std::string aName, float aStrength, float aAgilty, float aStamina){
            Name = aName;
            Strength = aStrength;
            Agility = aAgilty;
            Stamina = aStamina;
            Level = 1;
            DungeonLevel = 0;
}

//getter n setter methods
std::string Player::get_Name(){
   return Name;
}

float Player::get_Strength(){
    return Strength;
}

float Player::get_Agility(){
    return Agility;
}

float Player::get_Stamina(){
    return Stamina;
}
                                                                            /*
float Player::get_Damage(){
    Damage = (Strength * 2);
    return Damage;
}

float Player::get_Defense(){
    return Defense;
}

float Player::get_Health(){
    return Health;
}

int Player::get_Level(){
    return Level;
}

int Player::get_DungeonLevel(){
    return DungeonLevel;
}

int Player::get_ItemLvl(){
    return ItemLvl;
}
                                                                            */     