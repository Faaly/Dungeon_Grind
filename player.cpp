#include "player.h"
#include <conio.h> // getch()
#include "constants.h"

Player::Player(std::string aName, float aStrength, float aAgilty, float aStamina, int aLevel, int aDungeonLevel, float aExp){
            Cat = 'P';
            Name = aName;
            Strength = aStrength;
            Agility = aAgilty;
            Stamina = aStamina;
            Level = aLevel;
            DungeonLevel = aDungeonLevel;
            Exp = aExp;
}

Player::Player(std::string aName){
            Cat = 'P';
            Name = aName;
            Strength = 3;
            Agility = 3;
            Stamina = 3;
            Level = 1;
            DungeonLevel = 1;
            Exp = 0;
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

float Player::get_ExpScaleFactor(){
    return ExpScaleFactor;
}

float Player::get_Exp(){
    return Exp;
}

float Player::get_BaseExp(){
    return BaseExp;
}

float Player::get_Exp2lvl(){
    float Exp2lvl = 0;
    if (Level == 1)
    {
        Exp2lvl = 100;
    }
    else
     Exp2lvl = BaseExp * (Level - 1) * ExpScaleFactor;
    return Exp2lvl;
}

void Player::show_playerstats() {
    // TODO: add Level, Dungeon Level, Category
    std::cout << "Cat : " << (this->Cat)
             << " , Name : " << (this->Name) << "\n" 
             << "Str : " << (this->Strength)
             << " , Agi : " << (this->Agility)
             << " , Sta : " << (this->Stamina)
             << " , LvL : " << (this->Level)
             << " , Dlvl : " << (this->DungeonLevel) 
             << " , Exp : " << (this->Exp) << std::endl;
}

// löschen, brauchst du nicht mehr
void Player::set_Level(int lvl){
    Level = lvl;
}


void Player::gainExp(int gained_exp){
    this->Exp += gained_exp;
    // proofe if level up
    while (this->Exp >= this->get_Exp2lvl())
    {
        int result = this->Exp - this->get_Exp2lvl();
        this->LevelUp();
        this->Exp = result;
    }
}

void Player::LevelUp() {    
    system("cls");
    this->Level += 1;
    this->Strength += 1;
    this->Agility += 1;
    this->Stamina += 1;
 
    std::cout   << c_TUTORIALHELPER_03
                << "                          Congratulation " << this->Name << ".\n"
                << "                          You've reached Level " << this->Level << "."
                << "\n             Your strength has increased by 1. New strength : " << this->Strength
                << "\n              Your agility has increased by 1. New agility : " << this->Agility
                << "\n              Your stamina has increased by 1. New stamina : " << this->Stamina << std::endl;
    std::cout   << "\n\n                            Press Any Key.";
    getch();
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