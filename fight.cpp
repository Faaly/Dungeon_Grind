#include "fight.h"
#include <conio.h> // getch()
#include "constants.h"
#include <cstdlib> // rand() function


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


void fight(Player& Player, Enemy& Enemy){
    Player.set_currentHP(Player.maxhp()); // playerHP will be current hp. So we have current hp and max hp
    Enemy.set_currentHP(Enemy.get_maxhp()); //enemyHP will be current hp. So we have current hp and max hp
    
    bool special_attack = false; //enemyspecial attack bool
    float p_result; // Result of player dmg vs enemy def
    float e_result;
    int playeraction = 0; //picked action-save for later fight-comparison
    int enemyaction = 0;
    int pick = 0;
    bool pickagain = true;
    bool p_block = false;
    bool e_block = false;

    do
    {
  
        
        do
        {
            system("cls");
            Enemy.show_enemystats();
            std::cout << "Enemy HP: " << Enemy.get_currentHP() << " / " << Enemy.get_maxhp() << std::endl;
            std::cout << "Player HP: " << Player.get_currentHP() << " / " << Player.maxhp() << std::endl;
            //If Potion later available >> add (5) for Potion option
            std::cout << "\nWhat do you want to do?\n" << std::endl;
            std::cout << "(1) - " << "Attack" << std::endl
                    << "(3) - " << "Block (Not working)"<< std::endl
                    << "(9) - " << "Run Away (bugged)" << std::endl;
            std::cin >> pick;
            playeraction = pick;
            
            switch (pick)
            {
            case 1:
                //std::cout << "Result: " << result << std::endl;
                std::cout << "player choose attack" << std::endl;
                //std::cout << "Enemy HP: " << Enemy.get_currentHP() << std::endl;
                pickagain = false;
                getch();
                break;
            case 3:
                pickagain = false;
                std::cout << "player choose block" << std::endl;
                p_block = true;
                getch();
                break;
            //case 5: 
            //  Potion Placeholder
            //  break;
            case 9:
                pickagain = false; // run Away
                break;
            default:
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                system("cls");
                std::cout << "\n" << c_ERROR_002 << "\n" << std::endl;
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
            //do special attack and skip enemy action
            
        } else {
            enemyaction = enemy_action(Player, Enemy);
                if (enemyaction == 1)
                {
                    //enemy attack
                    
                } else if (enemyaction == 2)
                {
                    special_attack = true;
                    
                    
                } else if (enemyaction == 3)
                {
                    e_block = true;
                    //enemy block
                }
        }
        std::cout << "Enemy choose " << enemyaction << "." << std::endl;
        getch(); 
        //fight comparison

        if (playeraction == 1)
        {
            if (e_block) // enemy blocks while player attacks
            {
                p_result = (Player.maxdmg() - Enemy.get_maxdef()) * 0.10 ; // Block reduces dmg via 90%
                p_result = std::max(0.0f, p_result);
                Enemy.set_currentHP(Enemy.get_currentHP() - p_result);
                std::cout << "You attack the " << Enemy.get_Name() << "." << "But " << Enemy.get_Name() << " blocks your attack. You still do " << p_result << " Damage." << std::endl;
                e_block = false;
                getch();
                if (Enemy.get_currentHP() < 0)// if enemy dead, stop
                {
                    break;
                } 
            } else if(enemyaction == 4){
                p_result = Player.maxdmg() - Enemy.get_maxdef();
                p_result = std::max(0.0f, p_result);
                Enemy.set_currentHP(Enemy.get_currentHP() - p_result);
                std::cout << "You attack the " << Enemy.get_Name() << " for " << p_result << " Damage." << std::endl;
                getch();
                if (Enemy.get_currentHP() < 0)// if enemy dead, stop
                {
                    break;
                }
                std::cout << "Enemy uses special attack" << std::endl;
                special_attack = false;
                //enemy special attack
                getch();
            } else {
                p_result = Player.maxdmg() - Enemy.get_maxdef(); // Both attack
                p_result = std::max(0.0f, p_result);
                Enemy.set_currentHP(Enemy.get_currentHP() - p_result);
                std::cout << "You attack the " << Enemy.get_Name() << " for " << p_result << " Damage." << std::endl;
                getch();
                if (Enemy.get_currentHP() < 0)// if enemy dead, stop
                {
                    break;
                }

            }
            
        }

        if (p_block && enemyaction == 4)
        {
            std::cout << "Player blocks special attack from enemy" << std::endl;
            special_attack = false;
            getch();
        }

        if (enemyaction == 1) 
        {
            if (p_block)
            {
                e_result = (Enemy.get_maxdmg() - Player.maxdef()) * 0.10; // Block reduces dmg via 90%
                e_result = std::max(0.0f, e_result);
                Player.set_currentHP(Player.get_currentHP() - e_result);
                std::cout << "The " << Enemy.get_Name() << " attacks you. While you block the attack, " << Enemy.get_Name() << " still do " << e_result << " Damage." << std::endl;
                getch();
                p_block = false;
            } else {
                e_result = Enemy.get_maxdmg() - Player.maxdef();
                e_result = std::max(0.0f, e_result);
                Player.set_currentHP(Player.get_currentHP() - e_result);
                std::cout << "The " << Enemy.get_Name() << " attacks you for " << e_result << " Damage." << std::endl;
                getch();
            }

        } else if (p_block && e_block) // both parties block
        {
            std::cout << "Both opponents are very defensive against each other. Nobody attacks."<< std::endl;
            p_block = false;
            e_block = false;
            getch();
        }
        
        if (Enemy.get_currentHP() < 0)
        {
            //you win

            std::cout << "You have beat the " << Enemy.get_Name() << ".\n"
                      << "           CONGRATULATIONS!" << std::endl; // insert const text here
            //Bug#1 solving via put Exp recieving here
            getch();
            break;
        }
    //std::cout << Player.get_Name() << ": " <<  playeraction << std::endl;
    //std::cout << Enemy.get_Name() << ": " << enemy_action(Player, Enemy) << std::endl;
    } while (Player.get_currentHP() > 0); //Repeat while player alive
}


/*std::cout  << "You're going to attack " << Enemy.get_Name() 
                          << " with your " << Player.get_weapon().get_Name() << std::endl;
                          enemyHP = Player.maxdmg() - Enemy.get_maxdef(Player);*/
