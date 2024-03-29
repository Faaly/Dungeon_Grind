#include "fight.h"
#include <conio.h> // getch()
#include "constants.h"
#include <cstdlib> // rand() function
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

int action_8bit_calc(int a, int b); 
// Adds two values into one for switch case solution.

void Menu_UP(Player& Player, Enemy& Enemy);
// UI for Combat

int enemy_action(Player& Player, Enemy& Enemy);
// Enemy Pick function, defined by HP of Enemy

void enemy_triple_attack(Player& Player, Enemy& Enemy, float minDamageThreshold);
//float enemy_triple_attack(Player& Player, Enemy& Enemy, float mDT);

void enemy_choose_special_attack(Player& Player, Enemy& Enemy, float mDT);
// Checks out Player Dungeon Level and decides what special attack player will have to encounter

bool p_crit(Player& Player);
// Checks if player will do hit critical

float p_attack(Player& Player, Enemy& Enemy, float mDT, bool iCH);
// Player attac function

float p_attack_b(Player& Player, Enemy& Enemy, float mDT, double b, bool iCH);
// Player attack function with enemy block modify

float e_attack(Player& Player, Enemy& Enemy, float mDT);
// Enemy attack function

float e_attack_b(Player& Player, Enemy& Enemy, float mDT, double b);

void c_FWD();

void p_attack_message(Enemy& Enemy, float a, bool iCH);

void p_attack_b_message(Enemy& Enemy, float a, bool iCH);

void fight(Player& Player, Enemy& Enemy){
    Player.set_currentHP(Player.maxhp()); // playerHP will be current hp. So we have current hp and max hp
    Enemy.set_currentHP(Enemy.get_maxhp()); //enemyHP will be current hp. So we have current hp and max hp
    
    bool special_attack = false; //enemyspecial attack bool
    float p_result; // Result of player dmg vs enemy def
    float e_result; // Result of enemy dmg vs player def
    int playeraction = 0; //picked action-save for later fight-comparison
    int playeraction_8bit = 0;
    int enemyaction = 0; // enemy picked action-save for later fight-comp
    int enemyaction_8bit = 0;
    int bit = 0;
    int pick = 0;
    bool pickagain = true;
    const float minDamageThreshold = 0.50f; // Adjust this threshold as needed
    bool isCriticalHit;

// Important Modifier ------------------------------------------------------------------------
    double block = 0.10; // block modifier

    do //gameround loop
    {      
        do //pick loop
        {
            system("cls");
            //Enemy.show_enemystats();
            Menu_UP(Player, Enemy);
            //If Potion later available >> add (5) for Potion option
            std::cout << "What do you want to do?\n" << std::endl;
            std::cout << c_FIGHT_MENU1 
                    << c_FIGHT_WINDOW_DOWN << std::endl;
            std::cin >> pick;
            playeraction = pick;
            
            switch (pick)
            {
            case 1:
                pickagain = false;
                //Player attack
                playeraction_8bit = 1;
                break;
            case 3:
                pickagain = false;
                //Player blocks
                playeraction_8bit = 2;
                break;
            //case 5: 
            //  Potion Placeholder
            //  playeraction_8bit = 4;
            //  break;
            case 9:
                pickagain = false; // run Away
                break;
            default:
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                system("cls");
                std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
                pickagain = true;
        //     break;
            }
        } while (pickagain);
        if (pick == 9)
        {
            break; //Run Away
        }
        
        if (special_attack)
        {
            enemyaction = 4;
            enemyaction_8bit = 128; //Enemy Special Attack & Skip enemyaction roll
            special_attack = false;
        } else {
            enemyaction = enemy_action(Player, Enemy);
                if (enemyaction == 1)
                {
                    enemyaction_8bit = 16; //Enemy Attack
                } else if (enemyaction == 2)
                {
                    special_attack = true;
                    enemyaction_8bit = 32; //Enemy Special Attack preparation
                } else if (enemyaction == 3)
                {
                    enemyaction_8bit = 64; //Enemy Block
                }
        }

        bit = action_8bit_calc(playeraction_8bit, enemyaction_8bit); // convert enemyaction roll into enemyaction_8bit
        
        switch (bit)
        {
        case 17: // Both attack
            Menu_UP(Player, Enemy);
            isCriticalHit = p_crit(Player);
            p_result = p_attack(Player, Enemy, minDamageThreshold, isCriticalHit);
            Enemy.set_currentHP(Enemy.get_currentHP() - p_result);
            p_attack_message(Enemy,p_result, isCriticalHit);
            c_FWD();
            getch();
            if (Enemy.get_currentHP() > 0)// if enemy isn't dead, do:
            {
                Menu_UP(Player, Enemy);
                e_result = e_attack(Player, Enemy, minDamageThreshold);
                Player.set_currentHP(Player.get_currentHP() - e_result);
                std::cout << "The " << Enemy.get_Name() << " attacks you for " << e_result << " Damage.\n" << c_ANY_KEY << std::endl;
                c_FWD();
                getch();
            }
            
            break;

        case 18: // Player blocks, enemy attacks
            Menu_UP(Player, Enemy);
            isCriticalHit = p_crit(Player);
            e_result = e_attack_b(Player, Enemy, minDamageThreshold, block);
            Player.set_currentHP(Player.get_currentHP() - e_result);
            std::cout << "The " << Enemy.get_Name() << " attacks you.\nWhile you block the attack, " << Enemy.get_Name() << " still do " << e_result << " Damage.\n" << c_ANY_KEY << std::endl;
            c_FWD();
            getch(); 
            break;

        case 33: //Player attack, enemy PREPARES special attack
            Menu_UP(Player, Enemy);
            isCriticalHit = p_crit(Player);
            p_result = p_attack(Player, Enemy, minDamageThreshold, isCriticalHit);
            Enemy.set_currentHP(Enemy.get_currentHP() - p_result);
            p_attack_message(Enemy, p_result, isCriticalHit);
            c_FWD();
            getch();
            if (Enemy.get_currentHP() > 0)// if enemy isn't dead, do:
            {
                Menu_UP(Player, Enemy);
                std::cout << "The " << Enemy.get_Name() << " prepares his special attack.\n" << c_ANY_KEY << std::endl;
                special_attack = true;
                c_FWD();
                getch();
            }
            break;

        case 34: //Player blocks, enemy PREPARES his special attack
            Menu_UP(Player, Enemy);
            std::cout << "You are blocking,\nbut the " << Enemy.get_Name() << "still prepare his special attack.\n" << c_ANY_KEY  << std::endl;
            c_FWD();
            getch();
            break;

        case 65: // Player attacks, enemy blocks
            Menu_UP(Player, Enemy);
            isCriticalHit = p_crit(Player);
            p_result = p_attack_b(Player, Enemy, minDamageThreshold, block, isCriticalHit);
            Enemy.set_currentHP(Enemy.get_currentHP() - p_result);
            p_attack_b_message(Enemy, p_result,isCriticalHit);
            c_FWD();
            getch();
            break;
        case 66: // Player blocks, enemy blocks
            Menu_UP(Player, Enemy);
            std::cout << "Both opponents are very defensive against each other. \nNobody attacks.\n" << c_ANY_KEY << std::endl;
            c_FWD();
            getch();
            break;

        case 129: // Player attacks, enemy DOES his special attack
            Menu_UP(Player, Enemy);
            isCriticalHit = p_crit(Player);
            p_result = p_attack(Player, Enemy, minDamageThreshold, isCriticalHit);
            Enemy.set_currentHP(Enemy.get_currentHP() - p_result);
            std::cout << "You attack the " << Enemy.get_Name() << " for " << p_result << " Damage.\n" << c_ANY_KEY << std::endl;
            c_FWD();
            getch();
            if (Enemy.get_currentHP() > 0)// if enemy isn't dead, do:
            {
                Menu_UP(Player, Enemy);
                std::cout << "The  "<< Enemy.get_Name() << " does his special attack!\n" << c_ANY_KEY << std::endl;
                c_FWD();
                getch();
                enemy_choose_special_attack(Player,Enemy,minDamageThreshold);
            }
            
            break;
        
        case 130: // Player blocks/interrups enemy special attack
            Menu_UP(Player, Enemy);
            std::cout << "You block the special attack from " << Enemy.get_Name() << "\n" << c_ANY_KEY << std::endl;
            c_FWD();
            special_attack = false;
            getch();
            break;
        }

    } while (Player.get_currentHP() > 0 && Enemy.get_currentHP() > 0); //Repeat while player alive
}

int action_8bit_calc(int a, int b){
    int result = a + b;
    return result;
}

void Menu_UP(Player& Player, Enemy& Enemy){
    system("cls");
    std::cout << c_FIGHT_WINDOW_ABOVE
    << std::right << std::setw(53)  << Enemy.get_Name() << "\n"
    << std::setw(43) << std::right << "HP: " << std::left << Enemy.get_currentHP() << std::right << " / " << std::left << Enemy.get_maxhp() << std::right << "\n\n\n\n" << std::endl; 
    std::cout << Player.get_Name() << " Lv: " << Player.get_Level() << "\nHP: " << Player.get_currentHP() << " / " << Player.maxhp() << "\n"
    << c_FIGHT_WINDOW_MID << std::endl;
}

int enemy_action(Player& Player, Enemy& Enemy){
    int action;
    float healthRatio = Enemy.get_currentHP() / Enemy.get_maxhp();
    if (healthRatio > 0.8) {
        action = 1; //High health, full attack
    } else if (healthRatio > 0.4) {
        action = (rand() % 2) + 1; // Medium health, 50% chance to block, 50% chance to attack
    } else {
        action = (rand() % 3) + 1; // Low health, 33% chance to block, 33% chance to attack, 33% chance for special attack
    }
    return action;
}


void enemy_triple_attack(Player& Player, Enemy& Enemy, float minDamageThreshold){
    float triple_attack_value = 0.50;
    int max_damage;
    float e_result;
    max_damage = std::max(1.0, (Enemy.get_maxdmg() - Player.maxdef()) * triple_attack_value); 
    std::srand(static_cast<float>(std::time(nullptr)));
    system("cls");
    Menu_UP(Player, Enemy);
    std::cout << "The " << Enemy.get_Name() <<  " hits you three times in a row as a special attack!\n" << c_ANY_KEY << std::endl;
    c_FWD();
    getch();
    for (size_t i = 0; i < 3; i++)
    {
        system("cls");
        Menu_UP(Player, Enemy);
        e_result = (rand() % max_damage) + 1; 
        e_result = std::round(std::max(minDamageThreshold, e_result) * 100.0) / 100.0;
        Player.set_currentHP(Player.get_currentHP() - e_result);
        std::cout << "The " << Enemy.get_Name() << " attacks you for " << e_result << " Damage.\n" << c_ANY_KEY << std::endl;
        c_FWD();
        getch();
    }   
                        
}


void enemy_choose_special_attack(Player& Player, Enemy& Enemy, float mDT){
    if (Player.get_DungeonLevel() < 6){
        enemy_triple_attack(Player, Enemy, mDT);
    } else if (Player.get_DungeonLevel() < 11){
        // enemy_heal
    } else if (Player.get_DungeonLevel() < 15){
        // enemy_double_damage 
    }
}






bool p_crit(Player& Player){
    bool isCriticalHit = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) < (Player.critrate() / 100.0);
    return isCriticalHit;  
}

float p_attack(Player& Player, Enemy& Enemy, float mDT, bool iCH){
    float damageMultiplier = iCH ? 2.0f : 1.0f; //If Player hits critical, damage will be doubled
    float p_result;
    p_result = (Player.maxdmg() - Enemy.get_maxdef()) * damageMultiplier; 
    p_result = std::round(std::max(mDT, p_result) * 100.0) / 100.0;
    return p_result;
}

float p_attack_b(Player& Player, Enemy& Enemy, float mDT, double b, bool iCH){
    float damageMultiplier = iCH ? 2.0f : 1.0f; //If Player hits critical, damage will be doubled
    float p_result;
    p_result = ((Player.maxdmg() - Enemy.get_maxdef()) * damageMultiplier) * b; 
    p_result = std::round(std::max(mDT, p_result) * 100.0) / 100.0;
    return p_result;
}

float e_attack(Player& Player, Enemy& Enemy, float mDT){
    float e_result;
    e_result =  Enemy.get_maxdmg() - Player.maxdef(); 
    e_result = std::round(std::max(mDT, e_result) * 100.0) / 100.0;
    return e_result;
}

float e_attack_b(Player& Player, Enemy& Enemy, float mDT, double b){
    float e_result;
    e_result = (Enemy.get_maxdmg() - Player.maxdef()) * b; 
    e_result = std::round(std::max(mDT, e_result) * 100.0) / 100.0;
    return e_result;
}

void c_FWD(){
std::cout << c_FIGHT_WINDOW_DOWN << std::endl;   
}

void p_attack_message(Enemy& Enemy, float a, bool iCH){
    if (iCH)
    {
        std::cout << "You attack the " << Enemy.get_Name() << " \nCRITICAL for " << a << " Damage.\n" << c_ANY_KEY << std::endl;
    } else 
    {
        std::cout << "You attack the " << Enemy.get_Name() << " \nfor " << a << " Damage.\n" << c_ANY_KEY << std::endl;
    }
    
}

void p_attack_b_message(Enemy& Enemy, float a, bool iCH){
    if (iCH)
    {
        std::cout << "You attack the " << Enemy.get_Name() << "." << "\nBut " << Enemy.get_Name() << " blocks your attack. \nYou still do " << a << " CRITICAL Damage.\n" << c_ANY_KEY <<  std::endl;
    } else
    {
        std::cout << "You attack the " << Enemy.get_Name() << "." << "\nBut " << Enemy.get_Name() << " blocks your attack. \nYou still do " << a << " Damage." << c_ANY_KEY << std::endl;
    }
    
}