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

void showstats(Player Adventurer, Weapon currentweapon, Helmet currenthelmet);


//-------------------------------------------Anfang int main() ------------------------------------------

int main(){
    //Titlescreen
    system("cls");
    std::cout << c_ENTER_SCREEN << std::endl;
    getch();
    //Main Menu
    system("cls");
    int mainmenupick = 0;
    
    Player Adventurer('P',"Name", 3, 3, 3);
    Weapon currentWeapon;
    Helmet currentHelmet;
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
            pickagain = false;
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
    } while (pickagain);
        
    std::ofstream playername_savefile(Adventurer.Name + ".dat");  //create safefile and fill it with stats. 
                                                             //Str , Agi, Sta, lvl, Dungeonlvl
    playername_savefile << Adventurer.Cat << ";" << Adventurer.Strength << ";" << Adventurer.Agility << ";" << Adventurer.Stamina << ";" << Adventurer.Level <<  ";" << Adventurer.DungeonLevel << std::endl;
    playername_savefile.close();

    system("cls");
    std::cout << "\nWelcome Adventurer " << Adventurer.Name << ". Welcome to Dungeon Grind.\n" << std::endl;
    std::cout << "Your Quest is simple: Fight your way deeper and deeper through the Dungeon. \nFind treasure and become stronger than ever!" << std::endl;
    std::cout << "But first.." << std::endl;
    getch();
    system("cls");

//Starterweapons pick    
    Weapon dagger ('W',"Dull Dagger", 2, 4, 3, 1);
    Weapon sword ('W', "Broken Sword", 3, 3, 3, 1);
    Weapon greatsword ('W', "Old Greatsword", 4, 2, 3, 1);
    Weapon polearm ('W', "Rusty Polearm", 3, 2, 4, 1);
    
    Weapon picked_weapon = PickStarterWeapon(dagger, sword, greatsword, polearm);
    currentWeapon = picked_weapon;
    
    
    std::cout << "You've equiped " << currentWeapon.Name << std::endl;
    getch();
    std::ofstream save_stream(Adventurer.Name + ".dat", std::ios::app);
    save_stream << currentWeapon.Cat << ";" << currentWeapon.Strength << ";" << currentWeapon.Agility << ";" << currentWeapon.Stamina << ";" << currentWeapon.ItemLvl << ";" << currentWeapon.Name << std::endl;
    save_stream.close();


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
            // Saving Stuff
            // check all items and safe to file
            system("cls"); 
            std::exit(0);
        }
        break;
    case 2:
        {
            system("cls");
            showstats(Adventurer, currentWeapon, currentHelmet);
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

   std::cout << "Before your adventure starts, please choose one Weapon:" << std::endl;
    int side {25};
    std::cout << std::left;
    std::cout << std::setw(side) << "Item: " << std::setw(side) << "Strength:" << std::setw(side) << "Agility:" << std::setw(side) << "Stamina:" << std::setw(side) << "Itemlevel:" << std::endl;
    std::cout << std::setw(side) << dagger.Name << std::setw(side) << dagger.Strength << std::setw(side) << dagger.Agility << std::setw(side) << dagger.Stamina << std::setw(side) << dagger.ItemLvl << std::endl;
    std::cout << std::setw(side) << sword.Name << std::setw(side) << sword.Strength << std::setw(side) << sword.Agility << std::setw(side) << sword.Stamina << std::setw(side) << sword.ItemLvl << std::endl;
    std::cout << std::setw(side) << greatsword.Name << std::setw(side) << greatsword.Strength << std::setw(side) << greatsword.Agility << std::setw(side) << greatsword.Stamina << std::setw(side) << greatsword.ItemLvl << std::endl;
    std::cout << std::setw(side) << polearm.Name << std::setw(side) << polearm.Strength << std::setw(side) << polearm.Agility << std::setw(side) << polearm.Stamina << std::setw(side) << sword.ItemLvl << std::endl;

    int pick = 0;
    bool pickagain = true;
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

void showstats(Player Adventurer, Weapon currentweapon, Helmet currenthelmet){
    float maxstr = Adventurer.Strength + currentweapon.Strength + currenthelmet.Strength;
    float maxagi = Adventurer.Agility + currentweapon.Agility + currenthelmet.Agility;
    float maxsta = Adventurer.Stamina + currentweapon.Stamina + currenthelmet.Stamina;
    float maxdmg = maxstr * 2;
    float maxdef = maxagi * 1.75;
    float maxhp = maxsta * 2;
    std::cout << "Welcome " << Adventurer.Name << "."
              << "\nYour current Stats are: \n"
              << "Strength : " << maxstr << "  Your maximal Damage is : " << maxdmg
              << "\nAgility : " << maxagi << "  Your Defense is : " << maxdef
              << "\nStamina : " << maxsta << "  Your Healthpoints are : " << maxhp << "\n\n"
              << "Current Gear equiped: \n"
              << "Weapon : " << currentweapon.Name
              << "\nHelmet : " << currenthelmet.Name << std::endl;
}