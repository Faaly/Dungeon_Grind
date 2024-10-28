#include <stdlib.h>  //console commands in c++ 4 windows
#include <iostream> // in and out stream
#include <iomanip> // text formatierung
#include <fstream> // file in and out stream
#include <sstream>
#include <string> // string (text)
#include <conio.h> // getch()
#include "header/constants.h" // Title, Main Menu, Errors
#include <vector> //Vectoren für fstreamp input
#include "header/weapon.h" // Class Weapon
#include "header/helmet.h" // Class Helmet
#include "header/player.h" // Class Player
#include "header/bodyarmor.h" // Class Bodyarmor
#include "header/ring.h" // Class Ring
#include "header/enemy.h" // Class Enemy
#include "header/fight.h" // Fight function
#include "header/loot.h" // Loot function#
#include "header/check.h" // check for savegames Dir
#include "header/highscore.h" //highscore
#include <map>





/*
            ToDo
    * Change std::endl to \n  in loop
        # because std::endl flushes the buffer which takes extra time
        //note by faaly: done in main.cpp

    * failed savegame load error leads to gamecrash. fix it!

    * Highscore Module (maybe in binary)

    * Texte nochmal fehler lesen, ggf durch deepl schicken (constants enemys a/an)

    * balancing of enemy, exp and stats of loot

    * exe file ggf mit licensen vorbereiten oder sonst wie anti-virus und defender block sicher machen

    * hash code generation einfügen für save files und highscore file to prevet manipulation/cheating

    * level 1 tutorial einfügen


    *1.2 Stats in ATK, ATK%, DEF, CRIT-Rate und CRIT-DMG sowie HP and HP% ändern!
    
*/


//create safefile and fill it with stats of the player
void savegame(Player Adventurer);

//Module to pick starter weapon for new player
Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm);

//Template for Module to loadfile into game
template <class T>
T convert_loadfile2game(T a, std::string b);

//creates highscore object
Highscoretable table;

//Template for build the item from data of loot.cpp
template <class T>
T create_loot(T a, std::string name, float str, float agi, float sta, int ilvl);

//Function that checks Dungeonlevel of Player to generate chest
std::string Enter_Dungeon_dlvl_chest(Player Adventurer);
std::string Enter_Dungeon_dlvl_npc(Player Adventurer);
//-------------------------------------------BEGIN int main() ------------------------------------------
//------------------------------------------------------------------------------------------------------
int main(){

    //checks if data folder is there. if not, crash game with error
    if (DataDir_Error() == 1)
    {
        std::cout << c_ERROR_003;
        getch();
        return 0;
    }

    //checks if files inside of data folder are there. --
    bool files_in_data = true;
    data_armor_check(files_in_data);
    data_helmet_check(files_in_data);
    data_prefix_g_check(files_in_data);
    data_prefix_l_check(files_in_data);
    data_prefix_m_check(files_in_data);
    data_ring_check(files_in_data);
    data_weapon_check(files_in_data); 
    if (files_in_data == false){  // -- if not, crash game with error
        std::cout << c_ERROR_004;
        getch();
        return 0;

    }

    //Checks if savegames folder does exist. If not, creates new savegames folder
    CreateDir();


    do{ 
        //Titlescreen
        system("cls");
        std::cout << c_ENTER_SCREEN << std::endl;
        getch();

        //Main Menu - Player can pick out of 3 options. Start new Game - Load game - exit game
        
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
            system("cls");
            std::cout << c_MAIN_MENU << std::endl;
            std::cin >> mainmenupick;

            std::string playername;
            switch (mainmenupick)
            {
            //Player decides to exit game
            case 4: 
                {
                system("cls"); 
                std::exit(0);
                }
                break;
            case 3:
                {
                    table.loadFromFile(highscorefile);
                    system("cls");
                    std::cout << c_HS_01 << "\n" << c_FIGHT_WINDOW_ABOVE << "\n" << c_HS_02 << "\n";
                    table.displayHighscores();
                    std::cout << "\n\n" << c_ANY_KEY;
                    getch();
                    break;
                    
                }
            //Player decides to load gamefile. He inserts his charname via std::cin
            //Charname will be also name for file in savegame folder
            case 2: 
                {
                std::ifstream inFile;
                std::string DATA;
                std::string savefile;
                std::cout << "What file should be loaded?\nPlease enter the exact name of the adventurer \nto load your game-file:" << std::endl;
                std::cin.ignore ( 100 , '\n' );
                std::getline(std::cin, savefile);
                inFile.open("savegames/" + savefile + ".dat");
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
                        //Adventurer.show_playerstats();
                    } // Check Category. Sort attributes and names.
                    if(type == "W"){
                        currentWeapon = convert_loadfile2game(currentWeapon, DATA);
                        //currentWeapon.show_weaponstats();
                        Adventurer.set_weapon(currentWeapon);
                    }
                    if(type == "H"){
                        currentHelmet = convert_loadfile2game(currentHelmet, DATA);
                        //currentHelmet.show_helmetstats();
                        Adventurer.set_helmet(currentHelmet);
                    }
                    if(type == "B"){
                        currentArmor = convert_loadfile2game(currentArmor, DATA);
                        //currentArmor.show_armorstats();
                        Adventurer.set_bodyarmor(currentArmor);
                    }
                    if(type == "R"){
                        currentRing = convert_loadfile2game(currentRing, DATA);
                        //currentRing.show_ringstats();
                        Adventurer.set_ring(currentRing);
                    }
                }

                //File is getting closed and Player is moved into Camp-Menu*
                inFile.close();
                std::cout << "\nSavefile successfully loaded.\n\n"
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
                std::cout << "Your Quest is simple: Fight your way deeper and deeper through the dungeon. \nFind treasure and become stronger than ever!" << std::endl;
                std::cout << "But first..\n\n\n" << std::endl;
                std::cout << c_ANY_KEY;
                getch();
                system("cls");

            //Player has to pick one out of four starter-weapons   
                Weapon dagger ("Dull Dagger", 2, 4, 3, 1);
                Weapon sword ("Broken Sword", 3, 3, 3, 1);
                Weapon greatsword ("Old Greatsword", 4, 2, 3, 1);
                Weapon polearm ("Rusty Polearm", 3, 2, 4, 1);
                
                //Function that shows some stats of the weapons. Switchcase via cin gives weapon to player
                Weapon picked_weapon = PickStarterWeapon(dagger, sword, greatsword, polearm); 
                Adventurer.set_weapon(picked_weapon);
                
                //Player has picked a weapon. The Game saves and player is put into Camp-Menu*
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
                std::cout << "\n" << c_ERROR_002 << "\n";
            }
        } while (pickagain);

        //#######  Camp-Menu ######
        //Player has to pick out of three options: To save and exit the game, 
        // to view his stats of his character or to start a dungeon (Play the actual game)
        pickagain = true;
        int hubmenu = 0;
        do
        {
            system("cls"); //Hubmenu check
            std::cout << c_TUTORIALHELPER_01 << c_HUB_MENU << std::endl;
            std::cin >> hubmenu;

            switch (hubmenu)
            {
            case 3: //save the game andd exit the game
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
                    
                    //Function that declears the treasure chest name by player dlvl
                    std::string Dungeonchest = Enter_Dungeon_dlvl_chest(Adventurer); 
                    //Enemy1.show_enemystats();
                    //getch();
                    fight(Adventurer, Enemy1); //whole fight function - > fight.cpp
                     
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
                            //Player getting exp if he is > level 1
                            int erfahrung = 50 * (Adventurer.get_DungeonLevel() -1 ) * 1.25; 
                            std::cout << "       You'll receive " << erfahrung << " Experience" << std::endl;
                            Adventurer.gainExp(erfahrung);
                        }

                        std::cout << std::endl;

                        //Create loot class items. This part generates the loot items after defeating the enemy.
                        Weapon loot_weapon;
                        Helmet loot_helmet;
                        Bodyarmor loot_armor;
                        Ring loot_ring;
                        
                        float loot_str = 0;
                        float loot_agi = 0;
                        float loot_sta = 0;  
                        int loot_ilvl = 1;
                        int prefix_item_qual_modifer = 0;
                        std::string lootname;
                        std::string lootclass1 = rng_loot_class_picker(); //Itemclass will be picked rng
                        std::string prefix1 = dlvl_item_qual_check(Adventurer); //item quality picked by dlvl
                        std::string suffix1 = suffix_picker(); //rng item suffix pick
                        prefix_attributes(prefix1,loot_str, loot_agi, loot_sta, prefix_item_qual_modifer); //prefix attributes will be generated rng
                        lootname = itemname_builder(lootclass1, prefix1, suffix1); //item will be build -> loot.cpp
                        
                        //Sorts data of item into specific class, depending on the lootclass name
                        if (lootclass1 == "weapon"){
                            loot_weapon = create_loot(loot_weapon, lootname, loot_str, loot_agi, loot_sta, loot_ilvl);
                        }
                        if (lootclass1 == "helmet"){
                            loot_helmet = create_loot(loot_helmet, lootname, loot_str, loot_agi, loot_sta, loot_ilvl);
                        }
                        if (lootclass1 == "armor"){
                            loot_armor = create_loot(loot_armor, lootname, loot_str, loot_agi, loot_sta, loot_ilvl);
                        }
                        if (lootclass1 == "ring"){
                            loot_ring = create_loot(loot_ring, lootname, loot_str, loot_agi, loot_sta, loot_ilvl);
                        }
                        
                        system("cls");
                        
                        // asking the player what item they have found. (what item was generated)
                        std::cout << c_TUTORIALHELPER_05 <<c_LOOT1 << Dungeonchest << c_LOOT1a << "\n      "
                                  << c_LOOT2 << capitalize_Item_Name(lootname) << std::endl;
                        
                        //checks if player has already equiped an item on specific slot.
                        if (already_equip_check(lootclass1, Adventurer) == false){
                           std::cout << c_LOOT4 << lootname << "\n";
                            //if false, function puts item to player and maybe show some stats of it
                            switch (loot_class_int_converter(lootclass1))
                            {
                            case 2:
                                Adventurer.set_bodyarmor(loot_armor);
                                break;
                            case 3:
                                Adventurer.set_helmet(loot_helmet);
                                break;
                            case 4:
                                Adventurer.set_ring(loot_ring);
                            case 1:
                                break;
                            }

                        } else {
                            // if player has already equiped an item on specific slot--
                            // game will show his already equiped item and new found item. --
                            // game will show both stats for player to compare.
                            bool B_Loot_Pick_again = true; //Failsafe if wront input
                            do
                            {
                                
                                int Loot_Pick = 0;
                                std::cout << c_COMPARE2 << std::endl; //loot
                                if (lootclass1 == "weapon")
                                {
                                loot_weapon.show_compare();
                                std::cout << "\n" << c_COMPARE1 << std::endl; //current item equiped
                                Adventurer.get_weapon().show_compare();
                                } else if (lootclass1 == "armor")
                                {
                                loot_armor.show_compare();
                                std::cout << "\n" << c_COMPARE1 << std::endl; 
                                Adventurer.get_bodyarmor().show_compare();
                                } else if (lootclass1 == "helmet")
                                {
                                loot_helmet.show_compare();
                                std::cout << "\n" << c_COMPARE1 << std::endl; 
                                Adventurer.get_helmet().show_compare();
                                } else if (lootclass1 == "ring")
                                {
                                loot_ring.show_compare();
                                std::cout << "\n" << c_COMPARE1 << std::endl; 
                                Adventurer.get_ring().show_compare();
                                }
                                
                                //Player gets asked what to do. take new item or keep curret gear
                                std::cout << "\n" << c_LOOT3 << capitalize_Item_Name(lootname) << "?\n" <<
                                
                                "(1) Take new item\n" <<
                                "(3) Keep current equipment!\n";
                                std::cin >> Loot_Pick;
                                switch (Loot_Pick) //if player picks item, new item will set to player class
                                {
                                    case 1:
                                    if (lootclass1 == "weapon")
                                    {
                                        Adventurer.set_weapon(loot_weapon);
                                    }
                                    if (lootclass1 == "armor")
                                    {
                                        Adventurer.set_bodyarmor(loot_armor);
                                    }
                                    if (lootclass1 == "helmet")
                                    {
                                        Adventurer.set_helmet(loot_helmet);
                                    }
                                    if (lootclass1 == "ring")
                                    {
                                        Adventurer.set_ring(loot_ring);
                                    }                                        
                                        std::cout << c_LOOT4a << capitalize_Item_Name(lootname) << "\n\n\n" << c_ANY_KEY << std::endl;
                                        B_Loot_Pick_again = false;
                                        break;
                                    case 3: //player keeps current gear
                                        std::cout << c_LOOT5 << "\n\n\n" << c_ANY_KEY << std::endl;
                                        B_Loot_Pick_again = false;
                                        break;
                                    default: //Player input was garbage, menu is reloaded
                                        std::cin.clear();
                                        std::cin.ignore(INT_MAX, '\n');
                                        system("cls");
                                        std::cout << "\n" << c_ERROR_002 << "\n";
                                }

                            } while (B_Loot_Pick_again);
                                                

                        }

                        getch();
                    } 
                    else if (Adventurer.get_currentHP() <= 0) //YOU LOSE - game ends and player will start at titlescreen
                    {
                        system("cls");
                        table.loadFromFile(highscorefile);
                        table.addHighscore(Highscore(Adventurer.get_Name(), Adventurer.get_DungeonLevel(), Adventurer.get_Level()));
                        table.save2File(highscorefile);
                        pickagain = false;
                        std::cout << "                    You died" << std::endl;
                        //Pimp this You died stuff like in dark souls.
                        //Highscore entry
                        getch();      
                        break;
                    }
                    
                }
                break;
            default: //Main menu fail safe if player input is garbage- Main Menu will be reloaded
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                system("cls");
                std::cout << "\n" << c_ERROR_002 << "\n";
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


//create safefile and fill it with stats of the player
void savegame(Player Adventurer){
    std::ofstream playername_savefile("savegames/" + Adventurer.get_Name() + ".dat");  
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
                    //std::string::size_type sz;     // tmp_* works!
                    std::string tmp_c,tmp_str, tmp_agi, tmp_sta, tmp_ilvl, tmp_name;
                    std::getline(tmp, tmp_c, ';');
                    std::getline(tmp, tmp_str, ';');
                    std::getline(tmp, tmp_agi,';');
                    std::getline(tmp, tmp_sta, ';');
                    std::getline(tmp, tmp_ilvl,';');
                    std::getline(tmp, tmp_name, ';');

                    //char cat = tmp_c[0];
                    float str = std::stof(tmp_str);
                    float agi = std::stof(tmp_agi);
                    float sta = std::stof(tmp_sta);
                    int ilvl = std::stoi(tmp_ilvl);

                    T obj(tmp_name, str, agi, sta, ilvl);
                
return obj;
}

template <class T>
T create_loot(T a, std::string name, float str, float agi, float sta, int ilvl){

    T loot(name, str, agi, sta, ilvl);

    return loot;
}

//Function that checks Dungeonlevel of Player to generate chest
std::string Enter_Dungeon_dlvl_chest(Player Adventurer){
    std::string result;
    int dlevel = Adventurer.get_DungeonLevel();

    //Calculates the range based on dlevel
    //int range = ((dlevel - 1) / 5) * 5 + 1;
    
    if (dlevel < 6)
    {
        result = c_1_5Chest;
    }
    else if (dlevel < 11)
    {
        result = c_6_10Chest;
    }
    else if (dlevel < 16)
    {
        result = c_11_15Chest;
    }
    else if (dlevel < 21)
    {
        result = c_16_20Chest;
    }
    else if (dlevel < 26)
    {
        result = c_21_25Chest;
    }
    else if (dlevel < 31)
    {
        result = c_26_30Chest;
    }
    else if (dlevel < 36)
    {
        result = c_31_35Chest;
    }
    else if (dlevel < 41)
    {
        result = c_36_40Chest;
    }
    else if (dlevel < 46)
    {
        result = c_41_45Chest; 
    }
    else if (dlevel < 51)
    {
        result = c_46_50Chest;
    }
    else if (dlevel < 56)
    {
        result = c_51_55Chest;
    }
    else if (dlevel < 61)
    {
        result = c_56_60Chest;
    }
    else if (dlevel < 66)
    {
        result = c_61_65Chest;
    }
    else if (dlevel < 71)
    {
        result = c_66_70Chest;
    }
    else if (dlevel < 76)
    {
        result = c_71_75Chest;
    }
    else if (dlevel < 81)
    {
        result = c_76_80Chest;
    }
    else if (dlevel < 86)
    {
        result = c_81_85Chest; 
    }
    else if (dlevel < 91)
    {
        result = c_86_90Chest; 
    }
    else if (dlevel < 93)
    {
        result = c_91_92Chest;
    }
    else if (dlevel < 95)
    {
        result = c_93_94Chest;
    }
    else if (dlevel < 97)
    {
        result = c_95_96Chest;
    }
    else if (dlevel < 99)
    {
        result = c_97_98Chest;
    }
    else if (dlevel == 99)
    {
        result = c_99Chest;
    }
    else
    {
        result = c_100Chest;
    }


    return result;
}



