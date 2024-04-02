#ifndef FIGHT_H
#define FIGHT_H
#include <string>
#include <iostream>
#include "player.h"
#include "enemy.h"

void Menu_UP(Player& Player, Enemy& Enemy);

void fight(Player& Player, Enemy& Enemy);

/// @brief get the enemy action
/// @param Player 
/// @param Enemy 
/// @return 
int enemy_action(Player& Player, Enemy& Enemy);


int action_8bit_calc(int a, int b); 
// Adds two values into one for switch case solution.

void Menu_UP(Player& Player, Enemy& Enemy);
// UI for Combat

int enemy_action(Player& Player, Enemy& Enemy);
// Enemy Pick function, defined by HP of Enemy

void enemy_triple_attack(Player& Player, Enemy& Enemy, float minDamageThreshold);
//float enemy_triple_attack(Player& Player, Enemy& Enemy, float mDT);

void enemy_heal(Player& Player, Enemy& Enemy);
//Enemy Special Attack #2 Enemy heals itself a short amount of HP

//Enemy Special Attack #3 Enemy does double damage with one hit
void enemy_double_damage_attack(Player& Player, Enemy& Enemy, float mDT);

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



#endif