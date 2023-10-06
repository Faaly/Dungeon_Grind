#include <stdlib.h>  //console commands in c++ 4 windows
#include <iostream> // in and out stream
#include <iomanip> // text formatierung
#include <fstream> // file in and out stream
#include <sstream>
#include <string> // string (text)
#include <conio.h> // getch()
#include "constants.h" // Title, Main Menu, Errors
#include "weapon.h" // Class Weapon
#include <vector> //Vectoren für fstream input
#include "helmet.h"
#include "player.h"
#include "bodyarmor.h"
#include "ring.h"

//std::vector<std::string> load_savegame(std::string savefile);

void savegame(Player Adventurer, Weapon currentWeapon, Helmet currentHelmet,
Bodyarmor currentArmor, Ring currentRing);

Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm);

void showstats(Player Adventurer, Weapon currentWeapon, Helmet currentHelmet,
Bodyarmor currentArmor, Ring currentRing);

template <class T>
void convert_loadfile2game(T a, std::string b);

//-------------------------------------------BEGIN int main() ------------------------------------------

int main(){
    //Titlescreen
    system("cls");
    std::cout << c_ENTER_SCREEN << std::endl;
    getch();
    //Main Menu
    system("cls");
    int mainmenupick = 0;
    
    Player Adventurer;
    std::string player_name;
    Weapon currentWeapon;
    Helmet currentHelmet;
    Bodyarmor currentArmor;
    Ring currentRing;

    bool pickagain = true;
    do
    {
        std::cout << c_MAIN_MENU << std::endl;
        std::cin >> mainmenupick;

        std::string playername;
        switch (mainmenupick)
        {
        case 3:
            {
            system("cls"); 
            std::exit(0);
            }
            break;
        case 2:
            {
            std::ifstream inFile;
            std::string DATA;
            std::string savefile;
            std::cout << "What file should be loaded?" << std::endl;
            std::cin.ignore ( 100 , '\n' );
            std::getline(std::cin, savefile);
            inFile.open(savefile + ".dat");
            if (!inFile)
            {
                std::cout << c_ERROR_404 << std::endl;
            }

            if (!inFile.is_open())
            {
                std::cout << c_ERROR_001 << savefile << ".dat" << std::endl;
                return 1;
            }
            
            std::cout << "Print Data from file : " << savefile << ".dat" << std::endl;
            std::stringstream ss_DATA;
            while (getline(inFile, DATA, '\n')){
                std::string type = DATA.substr(0, DATA.find(';'));
                if(type == "P") {
                    std::istringstream tmp(DATA);
                    std::string::size_type sz;
                    std::string tmp_c,tmp_str, tmp_agi, tmp_sta, tmp_lvl, tmp_dlvl;
                    std::getline(tmp, tmp_c, ';');
                    std::getline(tmp, tmp_str, ';');
                    std::getline(tmp, tmp_agi,';');
                    std::getline(tmp, tmp_sta, ';');
                    std::getline(tmp, tmp_lvl,';');
                    std::getline(tmp, tmp_dlvl);

                    Adventurer = Player(savefile, std::stof(tmp_str,&sz), std::stof(tmp_agi,&sz)
                    , std::stof(tmp_sta,&sz), std::stoi(tmp_lvl,&sz), std::stoi(tmp_dlvl,&sz));
                    Adventurer.show_playerstats();
                }
                if(type == "W"){
                    convert_loadfile2game(currentWeapon, DATA);
                    currentWeapon.show_weaponstats();
                }
                if(type == "H"){
                    convert_loadfile2game(currentHelmet, DATA);
                    currentHelmet.show_helmetstats();
                }
                if(type == "B"){
                    convert_loadfile2game(currentArmor, DATA);
                    currentArmor.show_armorstats();
                }
                if(type == "R"){
                    convert_loadfile2game(currentRing, DATA);
                    currentRing.show_ringstats();
                }
            }
            inFile.close();
            getch();
            pickagain = false;
            }
            break;
        case 1:
            {    
            system("cls");
            std::cout << "\nPlease name your Adventurer :" << std::endl;
            std::cin.ignore ( 100 , '\n' );
            std::getline(std::cin, playername);
            Adventurer = Player(playername);
            pickagain = false;

            system("cls");

            std::cout << "\nWelcome Adventurer " << Adventurer.get_Name() << ". Welcome to Dungeon Grind.\n" << std::endl;
            std::cout << "Your Quest is simple: Fight your way deeper and deeper through the Dungeon. \nFind treasure and become stronger than ever!" << std::endl;
            std::cout << "But first.." << std::endl;
            getch();
            system("cls");

        //Starterweapons pick    
            Weapon dagger ("Dull Dagger", 2, 4, 3, 1);
            Weapon sword ("Broken Sword", 3, 3, 3, 1);
            Weapon greatsword ("Old Greatsword", 4, 2, 3, 1);
            Weapon polearm ("Rusty Polearm", 3, 2, 4, 1);
            
            Weapon picked_weapon = PickStarterWeapon(dagger, sword, greatsword, polearm);
            currentWeapon = picked_weapon;
            
            std::cout << "You've equiped " << currentWeapon.get_Name() << std::endl;
            getch();
            savegame(Adventurer, currentWeapon, currentHelmet, currentArmor, currentRing);

            }
            break;
        default: 
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            system("cls");
            std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
        }
    } while (pickagain);

//Hub-Menu - Here starts the real game
pickagain = true;
int hubmenu = 0;
do
{
    system("cls");
    std::cout << c_HUB_MENU << std::endl;
    std::cin >> hubmenu;

    switch (hubmenu)
    {
    case 3:
        {
            savegame(Adventurer, currentWeapon, currentHelmet, currentArmor, currentRing);            
            system("cls"); 
            std::exit(0);
        }
        break;
    case 2:
        {
            system("cls");
            showstats(Adventurer, currentWeapon, currentHelmet, currentArmor, currentRing);
            //Stats stuff
            // check if player has equip
            //show all items w/ stats

            //count all stats together and show. Show damage, Hp and defense too
            getch();
        }
        break;
    case 1:
        {
            //code GAME! function stuff ect
        }
        break;
    default:
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        system("cls");
        std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
    }
} while (pickagain);


    return 0;
}

//----------------------------------------ENDE int main() -------------------------------------------------------

Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm){

    Weapon choosed_weapon;

   std::cout << "Before your adventure starts, please choose one Weapon:\n" << std::endl;
    int side {25};
    std::cout << std::left;
    std::cout << std::setw(side) << "Item: " << std::setw(side) << "Strength:" << std::setw(side) << "Agility:" << std::setw(side) << "Stamina:\n" << std::endl;
    std::cout << std::setw(side) << dagger.get_Name() << std::setw(side) << dagger.get_Strength() << std::setw(side) << dagger.get_Agility() << std::setw(side) << dagger.get_Stamina() << std::endl;
    std::cout << std::setw(side) << sword.get_Name() << std::setw(side) << sword.get_Strength() << std::setw(side) << sword.get_Agility() << std::setw(side) << sword.get_Stamina() << std::endl;
    std::cout << std::setw(side) << greatsword.get_Name() << std::setw(side) << greatsword.get_Strength() << std::setw(side) << greatsword.get_Agility() << std::setw(side) << greatsword.get_Stamina() << std::endl;
    std::cout << std::setw(side) << polearm.get_Name() << std::setw(side) << polearm.get_Strength() << std::setw(side) << polearm.get_Agility() << std::setw(side) << polearm.get_Stamina() << std::endl;

    int pick = 0;
    bool pickagain = true;
    do
    {
        std::cout << "\nWhich weapon do you want?\n" << std::endl;
        std::cout << "(1) - " << dagger.get_Name() << std::endl
                  << "(2) - " << sword.get_Name() << std::endl
                  << "(3) - " << greatsword.get_Name() << std::endl
                  << "(4) - " << polearm.get_Name() << std::endl;
        std::cin >> pick;
        switch (pick)
        {
        case 1:
            choosed_weapon = dagger;
            pickagain = false;
            break;
        case 2:
            choosed_weapon = sword;
            pickagain = false;
            break;
        case 3:
            choosed_weapon = greatsword;
            pickagain = false;
            break;
        case 4:
            choosed_weapon = polearm;
            pickagain = false;
            break;
        
        default:
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            system("cls");
            std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
       //     break;
        }
    } while (pickagain);
    
    return choosed_weapon;
}

void showstats(Player Adventurer, Weapon currentWeapon, Helmet currentHelmet,
Bodyarmor currentArmor, Ring currentRing){
    float maxstr = Adventurer.get_Strength() + currentWeapon.get_Strength() + currentHelmet.get_Strength() +
    currentArmor.get_Strength() + currentRing.get_Strength();
    float maxagi = Adventurer.get_Agility() + currentWeapon.get_Agility() + currentHelmet.get_Agility() +
    currentArmor.get_Agility() + currentRing.get_Agility();
    float maxsta = Adventurer.get_Stamina() + currentWeapon.get_Stamina() + currentHelmet.get_Stamina() +
    currentArmor.get_Stamina() + currentRing.get_Stamina();
    float maxdmg = maxstr * 2;
    float maxdef = (maxagi * 1.75) * 0.9;
    float maxhp = maxsta * 2;
    float critrate = maxagi * 0.75;
    std::cout << std::left;
    std::cout << "Welcome " << Adventurer.get_Name() << ".\n"
              << "You're currently Level " << Adventurer.get_Level()
              << " and you're at Sub-Level " << Adventurer.get_DungeonLevel() << " in this Dungeon.\n\n"
              << "\nYour current Stats are: \n"
              << "Strength   : " << maxstr
              << "\n>Max DMG   : " << maxdmg
              << "\nAgility    : " << maxagi
              << "\n>Crit-Rate : " << critrate << "%"
              << "\n>Def       : " << maxdef
              << "\nStamina    : " << maxsta  
              << "\n>Max HP    : " << maxhp << "\n\n"
              << "\nCurrent Gear equiped: \n"
              << "Weapon     : "<< currentWeapon.get_Name()
              << "\nHelmet     : " << currentHelmet.get_Name()
              << "\nBody Armor : " << currentArmor.get_Name()
              << "\nRing       : " << currentRing.get_Name() << std::endl; 
}

void savegame(Player Adventurer, Weapon currentWeapon, Helmet currentHelmet,
Bodyarmor currentArmor, Ring currentRing){
    std::ofstream playername_savefile(Adventurer.get_Name() + ".dat");  //create safefile and fill it with stats. 
                                                             //Str , Agi, Sta, lvl, Dungeonlvl
    playername_savefile << Adventurer.get_Cat() << ";" << Adventurer.get_Strength() << ";" << Adventurer.get_Agility() << ";" << Adventurer.get_Stamina() << ";" << Adventurer.get_Level() <<  ";" << Adventurer.get_DungeonLevel() << ";" << std::endl;
    playername_savefile << currentWeapon.get_Cat() << ";" << currentWeapon.get_Strength() << ";" << currentWeapon.get_Agility() << ";" << currentWeapon.get_Stamina() << ";" << currentWeapon.get_ItemLvl() << ";" << currentWeapon.get_Name() << ";" <<std::endl;
    playername_savefile << currentHelmet.get_Cat() << ";" << currentHelmet.get_Strength() << ";" << currentHelmet.get_Agility() << ";" << currentHelmet.get_Stamina() << ";" << currentHelmet.get_ItemLvl() << ";" << currentHelmet.get_Name() << ";" <<std::endl;
    playername_savefile << currentArmor.get_Cat() << ";" << currentArmor.get_Strength() << ";" << currentArmor.get_Agility() << ";" << currentArmor.get_Stamina() << ";" << currentArmor.get_ItemLvl() << ";" << currentArmor.get_Name() << ";" <<std::endl;
    playername_savefile << currentRing.get_Cat() << ";" << currentRing.get_Strength() << ";" << currentRing.get_Agility() << ";" << currentRing.get_Stamina() << ";" << currentRing.get_ItemLvl() << ";" << currentRing.get_Name() << ";" <<std::endl;
    playername_savefile.close();

}

template <class T>
void convert_loadfile2game(T a, std::string b){
                    std::istringstream tmp(b);     // b works!
                    std::string::size_type sz;     // tmp_* works!
                    std::string tmp_c,tmp_str, tmp_agi, tmp_sta, tmp_ilvl, tmp_name;
                    std::getline(tmp, tmp_c, ';');
                    std::getline(tmp, tmp_str, ';');
                    std::getline(tmp, tmp_agi,';');
                    std::getline(tmp, tmp_sta, ';');
                    std::getline(tmp, tmp_ilvl,';');
                    std::getline(tmp, tmp_name);

                    T obj(tmp_name, std::stof(tmp_str,&sz), std::stof(tmp_agi,&sz)
                    , std::stof(tmp_sta,&sz), std::stoi(tmp_ilvl,&sz));
                

}
