#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "bodyarmor.h"
#include "helmet.h"
#include "ring.h"
#include "weapon.h"

class Player{
    //Private Member Variables
    char Cat;
    std::string Name;
    float Strength; 
    float Agility;     
    float Stamina;       
    int Level;
    int DungeonLevel;
    float Exp;
    float BaseExp = 100;
    float ExpScaleFactor = 1.5f;

    float dmgScaleFactor = 2;
    float hpScaleFactor = 2;
    float defScaleFactor1 = 1.75;
    float defScaleFactor2 = 0.9;
    float critrateScaleFactor = 0.75;

    float currentHP = 0;

    Weapon p_currentWeapon;
    Helmet p_currentHelmet;
    Bodyarmor p_currentArmor;
    Ring p_currentRing;

    void LevelUp();

    public:
        
        //Constructor
        Player() = default;
        Player(std::string aName, float aStrength, float aAgilty, float aStamina, int aLevel, int aDungeonLevel, float aExp);

        Player(std::string aName);

        //Functions(Methods)
        float get_Damage(); 
        float get_Defense();
        float get_Health(); 

        void show_playerstats(); 

        //Getter n Setter
        char get_Cat();

        std::string get_Name();

        float get_Strength();

        float get_Agility();

        float get_Stamina();

        int get_DungeonLevel();

        int get_Level();

        float get_Exp();

        float get_BaseExp();

        float get_Exp2lvl();

        float get_ExpScaleFactor();

        float DmgScaleFactor();

        float HPScaleFactor();

        float DefScaleFactor1();

        float DefScaleFactor2();

        float CritrateScaleFactor();

        float maxstr();

        float maxagi();

        float maxsta();

        float maxdmg();

        float maxdef();

        float critrate();

        float maxhp();

        float get_currentHP();

        void set_currentHP(float currentHP);

        void set_Name(std::string n);

        void set_Strength(float str);

        void set_Agility(float agi);

        void set_Stamina(float sta);

        void set_Level(int lvl);

        void set_DungeonLevel(int dlvl);

        void gainExp(int exp);

        void showstats();

        void set_weapon(Weapon currentWeapon);
        void set_helmet(Helmet currentHelmet);
        void set_bodyarmor(Bodyarmor currentArmor);
        void set_ring(Ring currentRing);

        Weapon get_weapon();
        Helmet get_helmet();
        Bodyarmor get_bodyarmor();
        Ring get_ring();

        void attack();

// Fight Functions -----------------------------------------------



}; 



#endif