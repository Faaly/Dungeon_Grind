#include <stdlib.h>  //console commands in c++ 4 windows
#include <iostream> // in and out stream
#include <iomanip> // text formatierung
#include <fstream> // file in and out stream
#include <string> // string (text)
#include <conio.h> // getch()
#include "constants.h" // Title, Main Menu, Errors
#include "weapon.h" // Class Weapon
#include "helmet.h"
#include "player.h"

Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm);

int main(){

    //Titlescreen
    system("cls");
    std::cout << c_ENTER_SCREEN << std::endl;
    getch();
    //Main Menu
    system("cls");
    int MainMenuPick = 0;
    
    Player Adventurer("Name", 0, 0, 0);
    bool PickAgain = true;
    do
    {
        std::cout << c_MAIN_MENU << std::endl;
        std::cin >> MainMenuPick;

        std::string playername;
        switch (MainMenuPick)
        {
        case 3:
            {
            std::exit(0);
            }
            break;
        case 2:
            {
            std::ifstream inFile;
            std::string DATA;
            std::string savefile;
            std::cout << "What file should be loaded?" << std::endl;
            //std::cin.clear();
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
            while (getline(inFile, DATA , ';'))
            {
                std::cout << DATA << " - "; //
            }
            std::cout << "Loading feature not build in yet.  \n :P " << std::endl;
            inFile.close();
            std::exit(0);
            }
            break;
        case 1:
            {    
            system("cls");
            std::cout << "\nPlease name your Adventurer :" << std::endl;
            //std::cin.clear();
            std::cin.ignore ( 100 , '\n' );
            std::getline(std::cin, playername);
            Adventurer.Name = playername;
            PickAgain = false;
            }
            break;
        default: 
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            system("cls");
            std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
                //std::exit(0);
            
            //break;
        }
    } while (PickAgain);
        
    std::ofstream playername_savefile(Adventurer.Name + ".dat");  //create safefile and fill it with stats. 
                                                             //Str , Agi, Sta, lvl, Dungeonlvl
    playername_savefile << Adventurer.Strength << ";" << Adventurer.Agility << ";" << Adventurer.Stamina << ";" << Adventurer.Level <<  ";" << Adventurer.DungeonLevel << std::endl;
    playername_savefile.close();

    system("cls");
    std::cout << "\nWelcome Adventurer " << Adventurer.Name << ". Welcome to Dungeon Grind." << std::endl;
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
    
    std::cout << "You've equiped " << picked_weapon.Name << std::endl;
    std::ofstream save_stream(Adventurer.Name + ".dat", std::ios::app);
    save_stream << picked_weapon.Strength << ";" << picked_weapon.Agility << ";" << picked_weapon.Stamina << ";" << picked_weapon.ItemLvl << ";" << picked_weapon.Name << std::endl;
    save_stream.close();


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

Weapon PickStarterWeapon(Weapon dagger, Weapon sword, Weapon greatsword, Weapon polearm){

    Weapon choosed_weapon;

   std::cout << "Before your adventure starts, please choose one Weapon:" << std::endl;
    int side {25};
    std::cout << std::left;
    std::cout << std::setw(side) << "Item: " << std::setw(side) << "Strength:" << std::setw(side) << "Agility:" << std::setw(side) << "Stamina:" << std::setw(side) << "Itemlevel:" << std::endl;
    std::cout << std::setw(side) << dagger.Name << std::setw(side) << dagger.Strength << std::setw(side) << dagger.Agility << std::setw(side) << dagger.Stamina << std::setw(side) << dagger.ItemLvl << std::endl;
    std::cout << std::setw(side) << sword.Name << std::setw(side) << sword.Strength << std::setw(side) << sword.Agility << std::setw(side) << sword.Stamina << std::setw(side) << sword.ItemLvl << std::endl;
    std::cout << std::setw(side) << greatsword.Name << std::setw(side) << greatsword.Strength << std::setw(side) << greatsword.Agility << std::setw(side) << greatsword.Stamina << std::setw(side) << greatsword.ItemLvl << std::endl;
    std::cout << std::setw(side) << polearm.Name << std::setw(side) << polearm.Strength << std::setw(side) << polearm.Agility << std::setw(side) << polearm.Stamina << std::setw(side) << sword.ItemLvl << std::endl;

    int pick = 0;
    bool PickAgain = true;
    do
    {
        std::cout << "Which weapon do you want?" << std::endl;
        std::cout << "(1) - " << dagger.Name << std::endl
                  << "(2) - " << sword.Name << std::endl
                  << "(3) - " << greatsword.Name << std::endl
                  << "(4) - " << polearm.Name << std::endl;
        std::cin >> pick;
        switch (pick)
        {
        case 1:
            choosed_weapon = dagger;
            PickAgain = false;
            break;
        case 2:
            choosed_weapon = sword;
            PickAgain = false;
            break;
        case 3:
            choosed_weapon = greatsword;
            PickAgain = false;
            break;
        case 4:
            choosed_weapon = polearm;
            PickAgain = false;
            break;
        
        default:
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            system("cls");
            std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
       //     break;
        }
    } while (PickAgain);

    return choosed_weapon;
}
