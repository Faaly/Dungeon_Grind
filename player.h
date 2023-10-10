#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

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

    void LevelUp();

    public:
        
        //Constructor
        Player() = default;
        Player(std::string aName, float aStrength, float aAgilty, float aStamina, int aLevel, int aDungeonLevel, float aExp);

        Player(std::string aName);

        //Functions(Methods)
        float get_Damage(); //1 strength = 2 damage(dmg)
        float get_Defense(); //1 agility = 1.75 defense(def)
        float get_Health(); //1 stamina = 2 health points(hp)

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

        void set_Name(std::string n);

        void set_Strength(float str);

        void set_Agility(float agi);

        void set_Stamina(float sta);

        void set_Level(int lvl);

        void gainExp(int exp);
}; 



#endif