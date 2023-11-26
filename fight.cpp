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
    

    do
    {
        int playeraction = 0; //picked action-save for later fight-comparison
        int enemyaction = 0;
        int pick = 0;
        bool pickagain = true;
        
        do
        {
            system("cls");
            //If Potion later available >> add (5) for Potion option
            std::cout << "\nWhat do you want to do?\n" << std::endl;
            std::cout << "(1) - " << "Attack " << Enemy.get_Name() << std::endl
                    << "(3) - " << "Block " << Enemy.get_Name() << std::endl
                    << "(9) - " << "Run Away" << std::endl;
            std::cin >> pick;
            playeraction = pick;
            float result;
            switch (pick)
            {
            case 1:
                result = Player.maxdmg() - Enemy.get_maxdef(); 
                std::cout << "Result: " << result << std::endl;
                Enemy.set_currentHP(Enemy.get_currentHP() - result);
                std::cout << "Enemy HP: " << Enemy.get_currentHP() << std::endl;
                getch();
                pickagain = false;
                break;
            case 3:
                pickagain = false;
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
        
        //Enemy Action here
        //fight comparison
        if (pick == 9)
        {
            break; //Run Away
        }
        
        if (Enemy.get_currentHP() < 0)
        {
            break;
        }
    std::cout << Player.get_Name() << ": " <<  playeraction << std::endl;
    std::cout << Enemy.get_Name() << ": " << enemy_action(Player, Enemy) << std::endl;
    bool special_attack = false; //special attack bool

    } while (Player.get_currentHP() > 0); //Player dead
}


/*std::cout  << "You're going to attack " << Enemy.get_Name() 
                          << " with your " << Player.get_weapon().get_Name() << std::endl;
                          enemyHP = Player.maxdmg() - Enemy.get_maxdef(Player);*/
