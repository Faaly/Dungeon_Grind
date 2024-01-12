#ifndef FIGHT_H
#define FIGHT_H
#include <string>
#include <iostream>
#include "player.h"
#include "enemy.h"

void Menu_UP(Player& Player, Enemy& Enemy);

void fight(Player& Player, Enemy& Enemy);

int enemy_action(Player& Player, Enemy& Enemy);


#endif