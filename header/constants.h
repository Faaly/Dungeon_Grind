#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "player.h"

//Chest and NPC Names --------------------------------------
const std::string c_1_5Chest = "old and dirty";
const std::string c_6_10Chest = "aged and shabby";
const std::string c_11_15Chest = "rusty and ancient";
const std::string c_16_20Chest = "forgotten and dusty";
const std::string c_21_25Chest = "moldering and fossilized";
const std::string c_26_30Chest = "shabby and tattered";
const std::string c_31_35Chest = "damaged";
const std::string c_36_40Chest = "broken";
const std::string c_41_45Chest = "cracked";
const std::string c_46_50Chest = "rusty and wrecked";
const std::string c_51_55Chest = "bruised";
const std::string c_56_60Chest = "soiled and moldy";
const std::string c_61_65Chest = "unpolished";
const std::string c_66_70Chest = "filthy";
const std::string c_71_75Chest = "decent";
const std::string c_76_80Chest = "intact and solid";
const std::string c_81_85Chest = "reliable and robust";
const std::string c_86_90Chest = "restored and polished";
const std::string c_91_92Chest = "pristine";
const std::string c_93_94Chest = "flawless";
const std::string c_95_96Chest = "perfect";
const std::string c_97_98Chest = "excellent";
const std::string c_99Chest = "surpreme";
const std::string c_100Chest = "divine and transcendent";

const std::string c_1_5NPC = "feeble Goblin";
const std::string c_6_10NPC = "scrawny Imp";
const std::string c_11_15NPC = "tiny and frail Gnoll";
const std::string c_16_20NPC = "underdeveloped Gremlin";
const std::string c_21_25NPC = "weak Kobold";
const std::string c_26_30NPC = "wobbly Slime";
const std::string c_31_35NPC = "nasty Spider";
const std::string c_36_40NPC = "vulnerable Skeleton";
const std::string c_41_45NPC = "unarmed Lizardmen";
const std::string c_46_50NPC = "old Mummie";
const std::string c_51_55NPC = "inexperienced Cultist";
const std::string c_56_60NPC = "robust Serpent";
const std::string c_61_62NPC = "strong Orc";
const std::string c_63_64NPC = "relentless Naga";
const std::string c_65_66NPC = "resilent Ghost";
const std::string c_67_68NPC = "fierce Siren";
const std::string c_69_70NPC = "ferocious Harpy";
const std::string c_71_72NPC = "tough Troll";
const std::string c_73_74NPC = "frightening Banshee";
const std::string c_75_76NPC = "mighty Centaur";
const std::string c_77_78NPC = "devilish Satyr";
const std::string c_79_80NPC = "vigorous Ogre";
const std::string c_81_82NPC = "powerful Minotaurus";
const std::string c_83_84NPC = "invincible Warlock";
const std::string c_85_86NPC = "indomitable Wyrm";
const std::string c_87_88NPC = "unstoppable Chimera";
const std::string c_89_90NPC = "surpreme Hydra";
const std::string c_91_92NPC = "overwhelming Giant";
const std::string c_93_94NPC = "undead Lich";
const std::string c_95_96NPC = "abyssal Beholder";
const std::string c_97_98NPC = "godlike Balrog";
const std::string c_99_100NPC = "horny Succubi";

//Minotaurus, Ogre, Warlock, Shaman, Balrog, Wyrm, Chimera, Hydra, Succubi, 

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


//Loot ---------------------------------------------------------------
const std::string c_LOOT1 =
        "                 You opened the "; // ..dlvl_chest"

const std::string c_LOOT1a =
        " chest";

const std::string c_LOOT2 =
        "             and found "; // ..rng_item"

const std::string c_LOOT3 = 
        "            \nDo you wanna take the "; // ..rng_item"

const std::string c_LOOT4 =
        "            You've found and equiped "; // ..rng_item"

const std::string c_LOOT4a =
        "            You've equiped "; // ..rng_item"

const std::string c_COMPARE1 =
        "Current Item :";

const std::string c_COMPARE2 =
        "Loot:";

const std::string c_LOOT5 =
        "            You keep your current gear and move along.";






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