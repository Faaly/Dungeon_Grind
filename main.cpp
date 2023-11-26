#include <stdlib.h>  //console commands in c++ 4 windows
#include <iostream> // in and out stream
#include <iomanip> // text formatierung
#include <fstream> // file in and out stream
#include <sstream>
#include <string> // string (text)
#include <conio.h> // getch()
#include "constants.h" // Title, Main Menu, Errors
#include <vector> //Vectoren für fstream input
#include "weapon.h" // Class Weapon
#include "helmet.h" // Class Helmet
#include "player.h" // Class Player
#include "bodyarmor.h" // Class Bodyarmor
#include "ring.h" // Class Ring
#include "enemy.h" // Class Enemy
#include "fight.h" // Fight function





void savegame(Player Adventurer);

Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm);

template <class T>
T convert_loadfile2game(T a, std::string b);

std::string Enter_Dungeon_dlvl_chest(Player Adventurer);
std::string Enter_Dungeon_dlvl_npc(Player Adventurer);






//-------------------------------------------BEGIN int main() ------------------------------------------
//------------------------------------------------------------------------------------------------------

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
            
            //std::cout << "Print Data from file : " << savefile << ".dat" << std::endl;
            std::stringstream ss_DATA;
            while (getline(inFile, DATA, '\n')){
                std::string type = DATA.substr(0, DATA.find(';'));
                if(type == "P") {
                    std::istringstream tmp(DATA);
                    std::string::size_type sz;
                    std::string tmp_c,tmp_str, tmp_agi, tmp_sta, tmp_lvl, tmp_dlvl, tmp_exp;
                    std::getline(tmp, tmp_c, ';');
                    std::getline(tmp, tmp_str, ';');
                    std::getline(tmp, tmp_agi,';');
                    std::getline(tmp, tmp_sta, ';');
                    std::getline(tmp, tmp_lvl,';');
                    std::getline(tmp, tmp_dlvl,';');
                    std::getline(tmp, tmp_exp);

                    Adventurer = Player(savefile, std::stof(tmp_str,&sz), std::stof(tmp_agi,&sz)
                    , std::stof(tmp_sta,&sz), std::stoi(tmp_lvl,&sz), std::stoi(tmp_dlvl,&sz), std::stof(tmp_exp,&sz));
                    Adventurer.show_playerstats();
                }
                if(type == "W"){
                    currentWeapon = convert_loadfile2game(currentWeapon, DATA);
                    currentWeapon.show_weaponstats();
                    Adventurer.set_weapon(currentWeapon);
                }
                if(type == "H"){
                    currentHelmet = convert_loadfile2game(currentHelmet, DATA);
                    currentHelmet.show_helmetstats();
                    Adventurer.set_helmet(currentHelmet);
                }
                if(type == "B"){
                    currentArmor = convert_loadfile2game(currentArmor, DATA);
                    currentArmor.show_armorstats();
                    Adventurer.set_bodyarmor(currentArmor);
                }
                if(type == "R"){
                    currentRing = convert_loadfile2game(currentRing, DATA);
                    currentRing.show_ringstats();
                    Adventurer.set_ring(currentRing);
                }
            }
            inFile.close();
            std::cout << "Savefile successfully loaded.\n\n"
                      << c_ANY_KEY << std::endl;
            getch();
            pickagain = false;
            }
            break;
        case 1:
            {    
            system("cls");
            std::cout << c_TUTORIALHELPER_01 << "\nPlease name your Adventurer :" << std::endl;
            std::cin.ignore ( 100 , '\n' );
            std::getline(std::cin, playername);
            Adventurer = Player(playername);
            pickagain = false;

            system("cls");
            std::cout << c_TUTORIALHELPER_01 << "\n\nWelcome Adventurer " << Adventurer.get_Name() << ". Welcome to Dungeon Grind.\n" << std::endl;
            std::cout << "Your Quest is simple: Fight your way deeper and deeper through the Dungeon. \nFind treasure and become stronger than ever!" << std::endl;
            std::cout << "But first..\n\n\n" << std::endl;
            std::cout << c_ANY_KEY;
            getch();
            system("cls");

        //Starterweapons pick    
            Weapon dagger ("Dull Dagger", 2, 4, 3, 1);
            Weapon sword ("Broken Sword", 3, 3, 3, 1);
            Weapon greatsword ("Old Greatsword", 4, 2, 3, 1);
            Weapon polearm ("Rusty Polearm", 3, 2, 4, 1);
            
            Weapon picked_weapon = PickStarterWeapon(dagger, sword, greatsword, polearm);
            Adventurer.set_weapon(picked_weapon);
            
            std::cout << "You've equiped " << Adventurer.get_weapon().get_Name() << "\n\n\n"<< c_ANY_KEY << std::endl;
            getch();
            savegame(Adventurer);

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
    std::cout << c_TUTORIALHELPER_01 << c_HUB_MENU << std::endl;
    std::cin >> hubmenu;

    switch (hubmenu)
    {
    case 3:
        {
            savegame(Adventurer);            
            system("cls"); 
            std::exit(0);
        }
        break;
    case 2:
        {
            system("cls");
            Adventurer.showstats();
            //Stats stuff
            // check if player has equip
            //show all items w/ stats

            //count all stats together and show. Show damage, Hp and defense too
            std::cout << "\n" << c_ANY_KEY << std::endl;
            getch();
        }
        break;
    case 1:
        {
            //Create Enemy
            Enemy Enemy1(Adventurer);
            system("cls");
            std::cout << c_TUTORIALHELPER_01 << c_ENTER_DUNGEON_pt1 << Adventurer.get_DungeonLevel() << ".\n" 
                      << c_ENTER_DUNGEON_pt2 << Enemy1.get_Name() << "\n" 
                      << c_ENTER_DUNGEON_pt3 << Enter_Dungeon_dlvl_chest(Adventurer) << c_ENTER_DUNGEON_pt4
                      << "\n\n\n         " << c_ANY_KEY;
            getch();

            Enemy1.show_enemystats();
            getch();
            fight(Adventurer, Enemy1); // Bug #1
            if (Adventurer.get_Level() == 1)
            {
                int erfahrung = 101;
                Adventurer.gainExp(erfahrung);
            }
            
    //  Kampf UI erstellen 
            
        
    //Loot
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
//---------------------------------------------------------------------------------------------------------------

Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm){

    Weapon choosed_weapon;

   std::cout << c_TUTORIALHELPER_05 << "Before your adventure starts, please choose one Weapon:\n" << std::endl;
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



void savegame(Player Adventurer){
    std::ofstream playername_savefile(Adventurer.get_Name() + ".dat");  //create safefile and fill it with stats. 
                                                             //Str , Agi, Sta, lvl, Dungeonlvl
    playername_savefile << Adventurer.get_Cat() << ";" << Adventurer.get_Strength() << ";" << Adventurer.get_Agility() << ";" << Adventurer.get_Stamina() << ";" << Adventurer.get_Level() <<  ";" << Adventurer.get_DungeonLevel() << ";" << Adventurer.get_Exp() << ";" << std::endl;
    playername_savefile << Adventurer.get_weapon().get_Cat() << ";" << Adventurer.get_weapon().get_Strength() << ";" << Adventurer.get_weapon().get_Agility() << ";" << Adventurer.get_weapon().get_Stamina() << ";" << Adventurer.get_weapon().get_ItemLvl() << ";" << Adventurer.get_weapon().get_Name() << ";" <<std::endl;
    playername_savefile << Adventurer.get_helmet().get_Cat() << ";" << Adventurer.get_helmet().get_Strength() << ";" << Adventurer.get_helmet().get_Agility() << ";" << Adventurer.get_helmet().get_Stamina() << ";" << Adventurer.get_helmet().get_ItemLvl() << ";" << Adventurer.get_helmet().get_Name() << ";" <<std::endl;
    playername_savefile << Adventurer.get_bodyarmor().get_Cat() << ";" << Adventurer.get_bodyarmor().get_Strength() << ";" << Adventurer.get_bodyarmor().get_Agility() << ";" << Adventurer.get_bodyarmor().get_Stamina() << ";" << Adventurer.get_bodyarmor().get_ItemLvl() << ";" << Adventurer.get_bodyarmor().get_Name() << ";" <<std::endl;
    playername_savefile << Adventurer.get_ring().get_Cat() << ";" << Adventurer.get_ring().get_Strength() << ";" << Adventurer.get_ring().get_Agility() << ";" << Adventurer.get_ring().get_Stamina() << ";" << Adventurer.get_ring().get_ItemLvl() << ";" << Adventurer.get_ring().get_Name() << ";" <<std::endl;
    playername_savefile.close();

}

template <class T>
T convert_loadfile2game(T a, std::string b){
                    std::istringstream tmp(b);     // b works!
                    std::string::size_type sz;     // tmp_* works!
                    std::string tmp_c,tmp_str, tmp_agi, tmp_sta, tmp_ilvl, tmp_name;
                    std::getline(tmp, tmp_c, ';');
                    std::getline(tmp, tmp_str, ';');
                    std::getline(tmp, tmp_agi,';');
                    std::getline(tmp, tmp_sta, ';');
                    std::getline(tmp, tmp_ilvl,';');
                    std::getline(tmp, tmp_name, ';');

                    char cat = tmp_c[0];
                    float str = std::stof(tmp_str);
                    float agi = std::stof(tmp_agi);
                    float sta = std::stof(tmp_sta);
                    int ilvl = std::stoi(tmp_ilvl);

                    T obj(tmp_name, str, agi, sta, ilvl);
                
return obj;
}

std::string Enter_Dungeon_dlvl_chest(Player Adventurer){
    std::string result;
    int dlevel = Adventurer.get_DungeonLevel();
    if (dlevel < 6){
        result = c_1_5Chest;
    }
    else if (dlevel< 11)
    {
        result = c_6_10Chest;
    }
    else if (dlevel< 16)
    {
        result = c_11_15Chest;
    }
    else if (dlevel< 21)
    {
        result = c_16_20Chest;
    }
    else
    {
        result = c_21_25Chest;
    }

    return result;
}



