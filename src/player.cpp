#include "../header/player.h"
#include <conio.h> // getch()
#include "../header/constants.h"
#include <iomanip> // text formatierung
#include <iostream>

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

float Player::DmgScaleFactor(){
    return dmgScaleFactor;
}

float Player::HPScaleFactor(){
    return hpScaleFactor;
}


float Player::DefScaleFactor1(){
    return defScaleFactor1;
}

float Player::DefScaleFactor2(){
    return defScaleFactor2;
}

float Player::CritrateScaleFactor(){
    return critrateScaleFactor;
}

float Player::maxstr(){
    float maxstr;
    return maxstr = this->get_Strength() + p_currentWeapon.get_Strength() + p_currentHelmet.get_Strength() +
    p_currentArmor.get_Strength() + p_currentRing.get_Strength();
}

float Player::maxagi(){
    float maxagi;
    return maxagi = this->get_Agility() + p_currentWeapon.get_Agility() + p_currentHelmet.get_Agility() +
    p_currentArmor.get_Agility() + p_currentRing.get_Agility();
}

float Player::maxsta(){
    float maxsta;
    return maxsta = this->get_Stamina() + p_currentWeapon.get_Stamina() + p_currentHelmet.get_Stamina() +
    p_currentArmor.get_Stamina() + p_currentRing.get_Stamina();
}

float Player::maxdmg(){
    float maxdmg;
    return maxdmg = this->maxstr() * this->DmgScaleFactor();
}

float Player::maxdef(){
    float maxdef;
    return maxdef = (this->maxagi() * this->DefScaleFactor1()) * this->DefScaleFactor2();   
}

float Player::critrate(){
    float critrate;
    return critrate = this->maxagi() * this->CritrateScaleFactor();
}

float Player::maxhp(){
    float maxhp;
    return maxhp = this->maxsta() * this->HPScaleFactor();
}

float Player::get_currentHP(){
    float currentHP;
    return currentHP = this->currentHP;
}

void Player::set_currentHP(float currentHP){
    this->currentHP = currentHP;
}

void Player::show_playerstats() {
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
//void Player::set_Level(int lvl){
//    Level = lvl;
//}


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

void Player::set_DungeonLevel(int dlvl){
    this->DungeonLevel = dlvl;
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

void Player::showstats(){
    int side = 15;
    std::cout << std::left;
    std::cout << c_TUTORIALHELPER_03 << "Welcome " << this->get_Name() << ".\n"
              << "You're currently Level " << this->get_Level()
              << "\nExp        : " << this->get_Exp() << ". Exp needed for next Level : " << this->get_Exp2lvl()  
              << "\nYou're at Sub-Level " << this->get_DungeonLevel() << " in this Dungeon.\n\n"
              << "\nYour current Stats are: \n"
              << "Strength   : " << this->maxstr()
              << "\n>Max DMG   : " << this->maxdmg()
              << "\nAgility    : " << this->maxagi()
              << "\n>Crit-Rate : " << this->critrate() << "%"
              << "\n>Def       : " << this->maxdef()
              << "\nStamina    : " << this->maxsta()  
              << "\n>Max HP    : " << this->maxhp() << "\n\n"
              << "\nCurrent Gear equiped: \n\n"
              << "             " << std::setw(side) << "Name:" << std::setw(side) << "Strength:" << std::setw(side) << "Agility:" << std::setw(side) << "Stamina:" << std::setw(side) << "Item Level:"
              << "\nWeapon     : " << std::setw(25) << p_currentWeapon.get_Name() << "\n             " << std::setw(side) << " " << std::setw(side) << p_currentWeapon.get_Strength() << std::setw(side) << p_currentWeapon.get_Agility() << std::setw(side) << p_currentWeapon.get_Stamina() << std::setw(side) << p_currentWeapon.get_ItemLvl()
              << "\nHelmet     : " << std::setw(25) << p_currentHelmet.get_Name() << "\n             " << std::setw(side) << " " << std::setw(side) << p_currentHelmet.get_Strength() << std::setw(side) << p_currentHelmet.get_Agility() << std::setw(side) << p_currentHelmet.get_Stamina() << std::setw(side) << p_currentHelmet.get_ItemLvl()
              << "\nBody Armor : " << std::setw(25) << p_currentArmor.get_Name()  << "\n             " << std::setw(side) << " " << std::setw(side) << p_currentArmor.get_Strength() << std::setw(side) << p_currentArmor.get_Agility() << std::setw(side) << p_currentArmor.get_Stamina() << std::setw(side) << p_currentArmor.get_ItemLvl( )
              << "\nRing       : " << std::setw(25) << p_currentRing.get_Name()   << "\n             " << std::setw(side) << " " << std::setw(side) << p_currentRing.get_Strength() << std::setw(side) << p_currentRing.get_Agility() << std::setw(side) << p_currentRing.get_Stamina() << std::setw(side) << p_currentRing.get_ItemLvl() << std::endl;    

   }  
   

void Player::set_weapon(Weapon currentWeapon)  {
    this->p_currentWeapon = currentWeapon;
}

void Player::set_helmet(Helmet currentHelmet){
    this->p_currentHelmet = currentHelmet;
}

void Player::set_bodyarmor(Bodyarmor currentArmor){
    this->p_currentArmor = currentArmor;
}

void Player::set_ring(Ring currentRing){
    this->p_currentRing = currentRing;
}

Weapon Player::get_weapon(){
    return p_currentWeapon;
}

Helmet Player::get_helmet(){
    return p_currentHelmet;
}

Bodyarmor Player::get_bodyarmor(){
    return p_currentArmor;
}

Ring Player::get_ring(){
    return p_currentRing;
}

void Player::attack(){
    
}