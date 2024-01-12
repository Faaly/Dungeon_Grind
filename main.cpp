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




//create safefile and fill it with stats of the player
void savegame(Player Adventurer);

//Module to pick starter weapon for new player
Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm);

//Template for Module to loadfile into game
template <class T>
T convert_loadfile2game(T a, std::string b);

//Function that checks Dungeonlevel of Player to generate chest
std::string Enter_Dungeon_dlvl_chest(Player Adventurer);
std::string Enter_Dungeon_dlvl_npc(Player Adventurer);
//-------------------------------------------BEGIN int main() ------------------------------------------
//------------------------------------------------------------------------------------------------------

int main(){
    do{ 
        //Titlescreen
        system("cls");
        std::cout << c_ENTER_SCREEN << std::endl;
        getch();

        //Main Menu - Player can pick out of 3 options. Start new Game - Load game - exit game
        system("cls");
        int mainmenupick = 0; //Variable for std::cin
        Player Adventurer;
        std::string player_name;
        Weapon currentWeapon;
        Helmet currentHelmet;
        Bodyarmor currentArmor;
        Ring currentRing;

        bool pickagain = true; //failsafe if insert wrong input
        do
        {
            std::cout << c_MAIN_MENU << std::endl;
            std::cin >> mainmenupick;

            std::string playername;
            switch (mainmenupick)
            {
            //Player decides to exit game
            case 3: 
                {
                system("cls"); 
                std::exit(0);
                }
                break;
            //Player decides to load gamefile. He inserts his charname via std::cin
            case 2: 
                {
                std::ifstream inFile;
                std::string DATA;
                std::string savefile;
                std::cout << "What file should be loaded?" << std::endl;
                std::cin.ignore ( 100 , '\n' );
                std::getline(std::cin, savefile);
                inFile.open(savefile + ".dat");
                //File doesn't exist - Error 404
                if (!inFile)
                {
                    std::cout << c_ERROR_404 << std::endl;
                }
                
                //File is open due reasons - Error 001
                if (!inFile.is_open())
                {
                    std::cout << c_ERROR_001 << savefile << ".dat" << std::endl;
                    return 1;
                }
                
                //File is found and data is loaded into stringstream. Loaded in dedicated parts of the Player.
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

                //File is getting closed and Player is moved into Camp-Menu
                inFile.close();
                std::cout << "Savefile successfully loaded.\n\n"
                        << c_ANY_KEY << std::endl;
                getch();
                pickagain = false;
                }
                break;
            //Player starts a new game and needs to name his character via std::cin
            case 1:
                {    
                system("cls");
                std::cout << c_TUTORIALHELPER_01 << "\nPlease name your Adventurer :" << std::endl;
                std::cin.ignore ( 100 , '\n' );
                std::getline(std::cin, playername);
                Adventurer = Player(playername);
                pickagain = false;

                //Short Story Part
                system("cls");
                std::cout << c_TUTORIALHELPER_01 << "\n\nWelcome Adventurer " << Adventurer.get_Name() << ". Welcome to Dungeon Grind.\n" << std::endl;
                std::cout << "Your Quest is simple: Fight your way deeper and deeper through the Dungeon. \nFind treasure and become stronger than ever!" << std::endl;
                std::cout << "But first..\n\n\n" << std::endl;
                std::cout << c_ANY_KEY;
                getch();
                system("cls");

            //Player has to pick one out of four starter-weapons   
                Weapon dagger ("Dull Dagger", 2, 4, 3, 1);
                Weapon sword ("Broken Sword", 3, 3, 3, 1);
                Weapon greatsword ("Old Greatsword", 4, 2, 3, 1);
                Weapon polearm ("Rusty Polearm", 3, 2, 4, 1);
                
                Weapon picked_weapon = PickStarterWeapon(dagger, sword, greatsword, polearm);
                Adventurer.set_weapon(picked_weapon);
                
                //Player has picked a weapon. The Game saves and player is put into Camp-Menu
                std::cout << "You've equiped " << Adventurer.get_weapon().get_Name() << "\n\n\n"<< c_ANY_KEY << std::endl;
                getch();
                savegame(Adventurer);

                }
                break;
            default: 
            //Players input is garbage and the menu is reloaded.
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                system("cls");
                std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
            }
        } while (pickagain);

        //Camp-Menu
        //Player has to pick out of three options: To save and exit the game, 
        // to view his stats of his character or to start a dungeon (Play the actual game)
        pickagain = true;
        int hubmenu = 0;
        do
        {
            system("cls");
            std::cout << c_TUTORIALHELPER_01 << c_HUB_MENU << std::endl;
            std::cin >> hubmenu;

            switch (hubmenu)
            {
            case 3: //save the game and exit the game
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
                    //check if player has equip
                    //show all items w/ stats

                    //count all stats together and show. Show damage, Hp and defense too
                    std::cout << "\n" << c_ANY_KEY << std::endl;
                    getch();
                }
                break;
            case 1: // Play the game
                {
                    //Create Enemy
                    Enemy Enemy1(Adventurer);
                    system("cls");
                    //Storypart - Telling the player which level they are and what enemy they can expect,
                    // also what kind of treasure chest they can expect.
                    std::cout << c_TUTORIALHELPER_01 << c_ENTER_DUNGEON_pt1 << Adventurer.get_DungeonLevel() << ".\n" 
                            << c_ENTER_DUNGEON_pt2 << Enemy1.get_Name() << "\n" 
                            << c_ENTER_DUNGEON_pt3 << Enter_Dungeon_dlvl_chest(Adventurer) << c_ENTER_DUNGEON_pt4
                            << "\n\n\n         " << c_ANY_KEY;
                    getch();


                    //Enemy1.show_enemystats();
                    fight(Adventurer, Enemy1);
                     
                    if (Enemy1.get_currentHP() <= 0 )  // YOU WIN
                    {
                        system("cls");
                        Adventurer.set_DungeonLevel(Adventurer.get_DungeonLevel() + 1); // Player DungeonLevel increase
                        std::cout << c_TUTORIALHELPER_01 << "         You have beat the " << Enemy1.get_Name() << ".\n"
                        << "                CONGRATULATIONS!\n\n\n" 
                        << "         You are entering Sub-Level " << Adventurer.get_DungeonLevel() <<
                           "\n              in this Dungeon." <<  std::endl; // 
                        getch();

                        //if player is Level 1, they need 100 XP to get level 2. Level 1 will be tutorial level.
                        if (Adventurer.get_Level() == 1)
                        {
                            int erfahrung = 101;
                            Adventurer.gainExp(erfahrung);
                        }   
                        else 
                        {
                            int erfahrung = 75 * (Adventurer.get_DungeonLevel() -1 ) * 1.25;
                            std::cout << "       You'll receive " << erfahrung << " Experience" << std::endl;
                            getch();
                            Adventurer.gainExp(erfahrung);
                            
                        }
                    } 
                    else if (Adventurer.get_currentHP() <= 0) //YOU LOSE
                    {
                        system("cls");
                        pickagain = false;
                        std::cout << "                    You died" << std::endl;
                        //Pimp this You died stuff like in dark souls.
                        getch();      
                        break;
                    }
                    
                    //you win

             
            //Bug#1 solving via put Exp recieving here
                     // insert const text here
    

            //  Kampf UI erstelle 
                    
                
            //Loot erstellen
                }
                break;
            default:
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                system("cls");
                std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
            }
        } while (pickagain);   
    } while (1 == 1);
    return 0;
}

//----------------------------------------ENDE int main() -------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------


//Module to pick starter weapon for new player
Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm){

    Weapon choosed_weapon;

   std::cout << c_TUTORIALHELPER_05 << "Before your adventure starts, please choose one Weapon:\n" << std::endl;
    int side {25};
    std::cout << std::left;
    std::cout << "Item: " << std::setw(side) << "Strength:" << std::setw(side) << "Agility:" << std::setw(side) << "Stamina:\n" << std::endl;
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


//create safefile and fill it with stats of the player
void savegame(Player Adventurer){
    std::ofstream playername_savefile(Adventurer.get_Name() + ".dat");  
    playername_savefile << Adventurer.get_Cat() << ";" << Adventurer.get_Strength() << ";" << Adventurer.get_Agility() << ";" << Adventurer.get_Stamina() << ";" << Adventurer.get_Level() <<  ";" << Adventurer.get_DungeonLevel() << ";" << Adventurer.get_Exp() << ";" << std::endl;
    playername_savefile << Adventurer.get_weapon().get_Cat() << ";" << Adventurer.get_weapon().get_Strength() << ";" << Adventurer.get_weapon().get_Agility() << ";" << Adventurer.get_weapon().get_Stamina() << ";" << Adventurer.get_weapon().get_ItemLvl() << ";" << Adventurer.get_weapon().get_Name() << ";" <<std::endl;
    playername_savefile << Adventurer.get_helmet().get_Cat() << ";" << Adventurer.get_helmet().get_Strength() << ";" << Adventurer.get_helmet().get_Agility() << ";" << Adventurer.get_helmet().get_Stamina() << ";" << Adventurer.get_helmet().get_ItemLvl() << ";" << Adventurer.get_helmet().get_Name() << ";" <<std::endl;
    playername_savefile << Adventurer.get_bodyarmor().get_Cat() << ";" << Adventurer.get_bodyarmor().get_Strength() << ";" << Adventurer.get_bodyarmor().get_Agility() << ";" << Adventurer.get_bodyarmor().get_Stamina() << ";" << Adventurer.get_bodyarmor().get_ItemLvl() << ";" << Adventurer.get_bodyarmor().get_Name() << ";" <<std::endl;
    playername_savefile << Adventurer.get_ring().get_Cat() << ";" << Adventurer.get_ring().get_Strength() << ";" << Adventurer.get_ring().get_Agility() << ";" << Adventurer.get_ring().get_Stamina() << ";" << Adventurer.get_ring().get_ItemLvl() << ";" << Adventurer.get_ring().get_Name() << ";" <<std::endl;
    playername_savefile.close();

}

//Template for Module to loadfile into game
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

//Function that checks Dungeonlevel of Player to generate chest
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



