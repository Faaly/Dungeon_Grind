#ifndef TITLESCREEN_H
#define TITLESCREEN_H
#include "player.h"

//Chest and NPC Names --------------------------------------
const std::string c_1_5Chest = "old and dirty";
const std::string c_6_10Chest = "aged and shabby";
const std::string c_11_15Chest = "rusty and ancient";
const std::string c_16_20Chest = "forgotten and dusty";
const std::string c_21_25Chest = "moldering and fossilized";

const std::string c_1_5NPC = "feeble Goblin";
const std::string c_6_10NPC = "scrawny Imp";
const std::string c_11_15NPC = "tiny and frail Gnoll";
const std::string c_16_20NPC = "underdeveloped Gremlin";
const std::string c_21_25NPC = "weak Kobold";        


//Error Messages -------------------------------------------
const std::string c_ERROR_404 = "Error 404 : File not found";
const std::string c_ERROR_001 = "Error 001 : Failed to open file : - ";
const std::string c_ERROR_002 = "Error 002 : Wrong input - Try again.";


//Any Key & other input -------------------------------------------------
const std::string c_ANY_KEY = "                      Press any key \n";
const std::string c_PLAYER_INPUT_NUMBER = "What do you want to do? \n";


//Title Screen -------------------------------------------
const std::string c_ENTER_SCREEN = 
        "\n"
        "\n"
        "     _______                                    \n" 
        "     |  __  |                                    \n"
        "     | |  | |_   _ _ __    __ _  ___  ____ _ ___     \n"
        "     | |  | | | | | '_ | / _` | / _ |/  _  || '_ |  \n"
        "     | |__| | |_| | | | | (_| |/  _/ | (_) || | | | \n"
        "     |_____/|__,|_|_| |_|__,  ||____||____/||_| |_| \n"
        "                          __/ | \n"
        "                         |___/  \n"
        "                         GRIND \n"
        "\n"
        ""
        "                      Press Any Key \n"
        "\n"
        "\n"
        "\n"
        "                       By Faaly \n";


//MainMenu Screen -------------------------------------------
const std::string c_MAIN_MENU =
        "\n"
        "\n"
        "\n"
        "What would you like to do?\n"
        "\n"
        "(1) New Game\n"
        "\n"
        "(2) Load Savefile\n"
        "\n"
        "(3) Exit\n"
        "\n"
        "\n"
        "\n";


//Hub-Menu------------------------------
const std::string c_HUB_MENU =
        "\n"
        "\n"
        "\n"
        "What would you like to do?\n"
        "\n"
        "(1) Grind a Dungeon\n\n"
        "(2) View my stats\n\n"
        "(3) Save & Exit\n\n"
        "\n"
        "\n"
        "\n";


//Enter-Dungeon Level-------------------------------
const std::string c_ENTER_DUNGEON_pt1 =  
        "                     You have entered Dungeonlevel ";

const std::string c_ENTER_DUNGEON_pt2 = 
        "                  While you go deeper into the darkness\n"
        "                 of this floor, you see a ";

const std::string c_ENTER_DUNGEON_pt3 = 
        "                 in front of a ";

const std::string c_ENTER_DUNGEON_pt4 = 
        " treasure chest. \n" 
        "           It seems the creature want to defend their belongings.\n\n"
        "                            Prepare to fight!";


//Fight ----------------------------------------------------------

const std::string c_FIGHT_WINDOW_ABOVE =
        "#####################################################\n"
        "#                                                   #\n";

const std::string c_FIGHT_WINDOW_MID =
        "#                                                   #\n"
        "#####################################################\n"
        "#                                                   #";

const std::string c_FIGHT_WINDOW_DOWN =
        "\n"
        "#                                                   #\n"
        "#####################################################\n";


//Tutorial Helper -----------------------------------------------------
const std::string c_TUTORIALHELPER_01 =
        "  ______\n"
        "<| o  o |>\n"
        " |______| \n"
        "\n"
        "\n";

const std::string c_TUTORIALHELPER_02 =
        "  ______\n"
        "<| >  < |>\n"
        " |__~~__| \n"
        "\n"
        "\n";

const std::string c_TUTORIALHELPER_03 =
        "  ______\n"
        "<| ^  ^ |>\n"
        " |______| \n"
        "\n"
        "\n";

const std::string c_TUTORIALHELPER_04 =
        "  ______\n"
        "<| x  x |>\n"
        " |__ww__| \n"
        "\n"
        "\n";

const std::string c_TUTORIALHELPER_05 =
        "  ______\n"
        "<| U  U |>\n"
        " |__--__| \n"
        "\n"
        "\n";

//Fight Menu ---------------------------------------------------------
const std::string c_FIGHT_MENU1 =
        "(1) Attack\n"
        "(3) Block\n" 
        "(9) Run Away";


#endif