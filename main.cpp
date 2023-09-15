#include <stdlib.h>  //console commands in c++ 4 windows
#include <iostream> // in and out stream
#include <iomanip> // text formatierung
#include <fstream> // file in and out stream
#include <string> // string (text)
#include <conio.h> // getch()
#include "titlescreen.h"
#include "mainmenu.h"

/*
class Player{
    public:
        std::string Playername;
        double Playerstrength;
        double Playerdamage;
        double Playeragility;
        double Playerdefense;
        double Playerstamina;
        double Playerhealth;
        double Playerlevel;
        double Dungeonlevel;

        Adventurer(std::string aPlayername, double aPlayerstrength, double aPlayerdamage, double aPlayeragilty,
        double aPlayerdefense, double aPlayerstamina, double aPlayerhealth, double aPlayerlevel, double aDungeonlevel){
            Playername = aPlayername;
            Playerstrength = aPlayerstrength;
            Playerdamage = aPlayerdamage;
            Playeragility = aPlayeragilty;
            Playerdefense = aPlayerdefense;
            Playerstamina = aPlayerstamina;
            Playerhealth = aPlayerhealth;
            Playerlevel = aPlayerlevel;
            Dungeonlevel = aDungeonlevel;
        }
}; */

class Helmet{
    public:
        std::string HelmetName;
        float HelmetStrength;
        float HelmetAgility;
        float HelmetStamina;
        int HelmetItemLvl;
        Helmet(std::string aHelmetName, float aHelmetStrength, float aHelmetAgility, float aHelmetStamina, int aHelmetItemLvl){
            HelmetName = aHelmetName;
            HelmetStrength = aHelmetStrength;
            HelmetAgility = aHelmetAgility;
            HelmetStamina = aHelmetStamina;
            HelmetItemLvl = aHelmetItemLvl;
        } 

};

class Weapon{
    public:
        std::string WeaponName;
        float WeaponStrenght;
        float WeaponAgility;
        float WeaponStamina;
        int WeaponItemLvl;
        Weapon(std::string aWeaponName, float aWeaponStrenght, float aWeaponAgilty, float aWeaponStamina, int aWeaponItemLvl){
            WeaponName = aWeaponName;
            WeaponStrenght = aWeaponStrenght;
            WeaponAgility = aWeaponAgilty;
            WeaponStamina = aWeaponStamina;
            WeaponItemLvl = aWeaponItemLvl;
        }
};

int main(){
//MainStats
    float playerstrength {3}; //1 strength = 2 damage(dmg)
        float playerdamage {playerstrength * 2};
    float playeragility {3};//1 agility = 1.75 defense(def)
        float playerdefense {playeragility * 1.5f};
    float playerstamina {4};//1 stamina = 2 health points(hp)
        float playerhealth {playerstamina * 2};
    std::string playername;
    int playerlevel {1};
    int dungeonlevel {1};

    //Beginning
    system("cls");
    titlescreen();
        getch();


    system("cls");
    //Main Menu
    int MainMenuPick {};
    mainmenu();
    std::cin >> MainMenuPick;
    switch (MainMenuPick)
    {
    case 3:
        {
            system("exit");
        }
        break;
    case 2:
        {
        std::ifstream inFile;
        //float str;
        //float agi; 
        //float sta;
        //int lvl;
        //int dlvl;
        std::string DATA;
        std::string savefile;
        std::cout << "What file should be loaded?" << std::endl;
        //std::cin.clear();
        std::cin.ignore ( 100 , '\n' );
        std::getline(std::cin, savefile);
        inFile.open(savefile + ".dat");
        if (!inFile)
        {
            std::cout << "Error 404" << std::endl;
        }

        if (!inFile.is_open())
        {
            std::cout << "Error : Failed to open " << savefile << std::endl;
            return 1;
        }

        std::cout << "Print Data from file : " << savefile << ".dat" << std::endl;
        while (getline(inFile, DATA , ';'))
        {
            std::cout << DATA;
        }
        std::cout << "Loading feature not build in.  :P" << std::endl;
        inFile.close();
        system("exit");
        }
        break;
    case 1:
        {    
            std::cout << "Please name your Adventurer :" << std::endl;
            //std::cin.clear();
            std::cin.ignore ( 100 , '\n' );
            std::getline(std::cin, playername);
        }
        break;
    default:
        std::cout << "Error - Wrong input" << "\n Game Over";
            system("exit");
        
        break;
    }
    std::ofstream playername_savefile(playername + ".dat");  //create safefile and fill it with stats. 
                                                             //Str , Agi, Sta, lvl, Dungeonlvl
    playername_savefile << playerstrength << ";" << playeragility << ";" << playeragility << ";" << playerlevel <<  ";" << dungeonlevel << std::endl;
    playername_savefile.close();

    std::cout << "Welcome adventurer " << playername << ". Welcome to Dungeon Grind." << std::endl;
    std::cout << "Your Quest is simple: Fight your way deeper and deeper through the Dungeon. \nFind treasure and become stronger than ever!" << std::endl;
    std::cout << "But first.." << std::endl;
    getch();


//Starterweapons pick    
    Weapon Dagger ("Dull Dagger", 2, 4, 3, 1);
    Weapon Sword ("Broken Sword", 3, 3, 3, 1);
    Weapon Greatsword ("Old Greatsword", 4, 2, 3, 1);
    Weapon Polearm ("Rusty Polearm", 3, 2, 4, 1);
    system("cls");

    std::cout << "Before your adventure starts, please choose one Weapon:" << std::endl;
    int side {25};
    std::cout << std::left;
    std::cout << std::setw(side) << "Item: " << std::setw(side) << "Strength:" << std::setw(side) << "Agility:" << std::setw(side) << "Stamina:" << std::setw(side) << "Itemlevel:" << std::endl;
    std::cout << std::setw(side) << Dagger.WeaponName << std::setw(side) << Dagger.WeaponStrenght << std::setw(side) << Dagger.WeaponAgility << std::setw(side) << Dagger.WeaponStamina << std::setw(side) << Dagger.WeaponItemLvl << std::endl;
    std::cout << std::setw(side) << Sword.WeaponName << std::setw(side) << Sword.WeaponStrenght << std::setw(side) << Sword.WeaponAgility << std::setw(side) << Sword.WeaponStamina << std::setw(side) << Sword.WeaponItemLvl << std::endl;
    std::cout << std::setw(side) << Greatsword.WeaponName << std::setw(side) << Greatsword.WeaponStrenght << std::setw(side) << Greatsword.WeaponAgility << std::setw(side) << Greatsword.WeaponStamina << std::setw(side) << Greatsword.WeaponItemLvl << std::endl;
    std::cout << std::setw(side) << Polearm.WeaponName << std::setw(side) << Polearm.WeaponStrenght << std::setw(side) << Polearm.WeaponAgility << std::setw(side) << Polearm.WeaponStamina << std::setw(side) << Sword.WeaponItemLvl << std::endl;

    int StarterWeaponPick {};
    std::cout << "Which weapon do you want?" << std::endl;
    std::cout << "(1) - " << Dagger.WeaponName << std::endl;
    std::cout << "(2) - " << Sword.WeaponName << std::endl;
    std::cout << "(3) - " << Greatsword.WeaponName << std::endl;
    std::cout << "(4) - " << Polearm.WeaponName << std::endl;
    std::cin >> StarterWeaponPick;

switch (StarterWeaponPick) //Pick a starter-weapon and store info in savefile
    {
    case 1:
    {
        std::cout << "You've equiped " << Dagger.WeaponName << std::endl;
        std::ofstream playername_savefile(playername + ".dat", std::ios::app);
        playername_savefile << Dagger.WeaponStrenght << ";" << Dagger.WeaponAgility << ";" << Dagger.WeaponStamina << ";" << Dagger.WeaponItemLvl << ";" << Dagger.WeaponName << std::endl;
        playername_savefile.close();
    }
        break;
    case 2:
    {
        std::cout << "You've equiped " << Sword.WeaponName << std::endl;
        std::ofstream playername_savefile(playername + ".dat", std::ios::app);
        playername_savefile << Sword.WeaponStrenght << ";" << Sword.WeaponAgility << ";" << Sword.WeaponStamina << ";" << Sword.WeaponItemLvl << ";" << Sword.WeaponName << std::endl;
        playername_savefile.close();
    }    
        break;
    case 3:
    {
        std::cout << "You've equiped " << Greatsword.WeaponName << std::endl;
        std::ofstream playername_savefile(playername + ".dat", std::ios::app);
        playername_savefile << Greatsword.WeaponStrenght << ";" << Greatsword.WeaponAgility << ";" << Greatsword.WeaponStamina << ";" << Greatsword.WeaponItemLvl << ";" << Greatsword.WeaponName << std::endl;
        playername_savefile.close();
    }
        break;
    case 4:
    {
        std::cout << "You've equiped " << Polearm.WeaponName << std::endl;
        std::ofstream playername_savefile(playername + ".dat", std::ios::app);
        playername_savefile << Polearm.WeaponStrenght << ";" << Polearm.WeaponAgility << ";" << Polearm.WeaponStamina << ";" << Polearm.WeaponItemLvl << ";" << Polearm.WeaponName << std::endl;
        playername_savefile.close();
    }
        break;        
    default:
    std::cout << "Error - Wrong input" << "\n Game Over";
        break;
    }
    


//Main Menu
/*    int menu = 0;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "(1) Grind a Dungeon" << std::endl;
    std::cout << "(2) View my stats" << std::endl;
    std::cin >> menu;
    if (menu == 1)
    {
        std::cout << "Error - Dungeon not found" << "\n Game Over";

    } if (menu == 2)
    {
    std::cout << "str: " << playerstrength << " agi: " << playeragility << "\n";
    std::cout << "dmg: " << playerdamage << " def: " << playerdefense << std::endl;
    std::cout << "sta: " << playerstamina << " hp: " << playerhealth << std::endl;
    } else
     {
        std::cout << "Error - Wrong input" << "\n Game Over";
    }
*/
    




    return 0;
    }