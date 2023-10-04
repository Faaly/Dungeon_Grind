#include "player.h"

Player::Player(std::string aName, float aStrength, float aAgilty, float aStamina, int aLevel, int aDungeonLevel){
            Cat = 'P';
            Name = aName;
            Strength = aStrength;
            Agility = aAgilty;
            Stamina = aStamina;
            Level = aLevel;
            DungeonLevel = aDungeonLevel;
}

Player::Player(std::string aName){
            Cat = 'P';
            Name = aName;
            Strength = 3;
            Agility = 3;
            Stamina = 3;
            Level = 1;
            DungeonLevel = 1;
}

//getter n setter methods
char Player::get_Cat(){
    return Cat;
}

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

int Player::get_Level(){
    return Level;
}

int Player::get_DungeonLevel(){
    return DungeonLevel;
}

void Player::show_playerstats() {
    // TODO: add Level, Dungeon Level, Category
    std::cout << "Cat : " << (this->Cat)
             << " , Name : " << (this->Name) << "\n" 
             << "Str : " << (this->Strength)
             << " , Agi : " << (this->Agility)
             << " , Sta : " << (this->Stamina)
             << " , LvL : " << (this->Level)
             << " , Dlvl : " << (this->DungeonLevel) << std::endl;
}

/*void Player::set_Name(std::string n){
    Name = n;
}

void Player::set_Strength(float str){
    Strength = str;
}

void Player::set_Agility(float agi){
    Agility = agi;
}

void Player::set_Stamina(float sta){
    Stamina = sta;
}*/
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

int Player::get_ItemLvl(){
    return ItemLvl;
}
                                                                            */     