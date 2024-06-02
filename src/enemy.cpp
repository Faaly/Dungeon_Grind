#include "../header/enemy.h"
#include "../header/constants.h"
#include <random>
#include <cctype> // for std::toupper

Enemy::Enemy(Player& Player){

    //Randomizer 
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> randomModifier(-2, 2);

    this->player = Player;  // Enemy getting data from Player to create stats.
    int dlevel = Player.get_DungeonLevel();
    float result_float;
    std::string result;
    if (dlevel < 6) // strength calc
    {
        result_float = (Player.maxstr() + randomModifier(gen)) - 2; 
    }
    else {
        result_float = Player.maxstr() + randomModifier(gen);
    } Strength = result_float;
    //Strength = Player.maxstr() + randomModifier(gen);


    if (dlevel < 6) // Agility Calc
    {
        result_float = (Player.maxagi() + randomModifier(gen)) - 2; 
    }
    else {
        result_float = Player.maxagi() + randomModifier(gen);
    } Agility = result_float;
    //Agility = Player.maxagi() + randomModifier(gen);


    if (dlevel < 6) //Stamina calc
    {
        result_float = (Player.maxsta() + randomModifier(gen)) + 4; 
    }
    else {
        result_float = Player.maxsta() + randomModifier(gen);
    } Stamina = result_float;
    //Stamina = Player.maxsta() + randomModifier(gen); 

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
    else if (dlevel < 26)
    {
        result = c_21_25NPC;
    }
    else if (dlevel < 31)
    {
        result = c_26_30NPC;
    }
    else if (dlevel < 36)
    {
        result = c_31_35NPC;
    }
    else if (dlevel < 41)
    {
        result = c_36_40NPC;
    }
    else if (dlevel < 46)
    {
        result = c_41_45NPC; 
    }
    else if (dlevel < 51)
    {
        result = c_46_50NPC;
    }
    else if (dlevel < 56)
    {
        result = c_51_55NPC;
    }
    else if (dlevel < 61)
    {
        result = c_56_60NPC;
    }
    else if (dlevel < 63)
    {
        result = c_61_62NPC;
    }
    else if (dlevel < 65)
    {
        result = c_63_64NPC;
    }
    else if (dlevel < 67)
    {
        result = c_65_66NPC;
    }
    else if (dlevel < 69)
    {
        result = c_67_68NPC;
    }
    else if (dlevel < 71)
    {
        result = c_69_70NPC; 
    }
    else if (dlevel < 73)
    {
        result = c_71_72NPC;
    }
    else if (dlevel < 75)
    {
        result = c_73_74NPC;
    }
    else if (dlevel < 77)
    {
        result = c_75_76NPC;
    }
    else if (dlevel < 79)
    {
        result = c_77_78NPC;
    }
    else if (dlevel < 81)
    {
        result = c_79_80NPC; 
    }
    else if (dlevel < 83)
    {
        result = c_81_82NPC;
    }
    else if (dlevel < 85)
    {
        result = c_83_84NPC;
    }
    else if (dlevel < 87)
    {
        result = c_85_86NPC;
    }
    else if (dlevel < 89)
    {
        result = c_87_88NPC;
    }
    else if (dlevel < 91)
    {
        result = c_89_90NPC; 
    }
    else if (dlevel < 93)
    {
        result = c_91_92NPC;
    }
    else if (dlevel < 95)
    {
        result = c_93_94NPC;
    }
    else if (dlevel < 97)
    {
        result = c_95_96NPC;
    }
    else if (dlevel < 99)
    {
        result = c_97_98NPC;
    }
    else
    {
        result = c_99_100NPC;
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