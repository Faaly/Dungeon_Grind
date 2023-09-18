#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player{
    public:
        
        //Constructor
        Player(std::string aName, float aStrength, float aDamage, float aAgilty);

        //Functions(Methods)
        float get_Damage(); //1 strength = 2 damage(dmg)
        float get_Defense(); //1 agility = 1.75 defense(def)
        float get_Health(); //1 stamina = 2 health points(hp)

        //Getter n Setter
        std::string get_Name();

        float get_Strength();

        float get_Agility();

        float get_Stamina();

        //int Player::get_Level();

        //int Player::get_DungeonLevel();

        //int Player::get_ItemLvl();

        //Member Variables
        std::string Name;
        float Strength = 3; 
        float Agility = 3;     
        float Stamina = 3;       
        int Level = 1;
        int DungeonLevel = 1;
}; 



#endif