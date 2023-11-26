#include "enemy.h"
#include "constants.h"
#include <random>
#include <cctype> // for std::toupper

Enemy::Enemy(Player& Player){

    //Randomizer 
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> randomModifier(-2, 2);

    this->player = Player;
    Strength = Player.maxstr() + randomModifier(gen);
    Agility = Player.maxagi() + randomModifier(gen);
    Stamina = Player.maxsta() + randomModifier(gen);
    std::string result;
    int dlevel = Player.get_DungeonLevel();
    if (dlevel < 6)
        {
            result = c_1_5NPC;
        }
    else if (dlevel < 11)
        {
            result = c_6_10NPC;
        }
    else if (dlevel < 16)
        {
            result = c_11_15NPC;
        }
    else if (dlevel < 21)
        {
            result = c_16_20NPC;
        }
    else
        {
            result = c_21_25NPC;
    }
    Name = result;

}

//functions (Methods)-----------------------------------------------
std::string Enemy::enemy_name_capitalizer(std::string a){
     if (a.empty()) {
        return a;            // Return the original string if it's empty
    }
    std::string result = a;
    result[0] = std::toupper(result[0]);

    return result;
}

void Enemy::show_enemystats(){
    std::string a = (this->Name);
    std::string enemy_name = enemy_name_capitalizer(a);
    std::cout << "Name : " << enemy_name << "\n" 
             << "Str : " << (this->Strength)<< ", Max Dmg:" << this->get_maxdmg() << "\n"
             << "Agi : " << (this->Agility)<< ", Max Def:" << this->get_maxdef() << "\n"
             << "Sta : " << (this->Stamina)<< ", Max Hp:" << this->get_maxhp() << std::endl;
}

float Enemy::get_maxhp(){
    float maxhp;
    return maxhp = this->Stamina * player.HPScaleFactor();
}



float Enemy::get_maxdmg(){
    float maxdmg;
    return maxdmg = this->Strength * player.DmgScaleFactor();
}

float Enemy::get_maxdef(){
    float maxdef;
    return maxdef = (this->Agility * player.DefScaleFactor1()) * player.DefScaleFactor2();
}


//getter n setter methods--------------------------------------------------------
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

float Enemy::get_currentHP(){
    float currentHP;
    return currentHP = this->currentHP;
}

void Enemy::set_currentHP(float currentHP){
    this->currentHP = currentHP;
}