#ifndef LOOT_H
#define LOOT_H
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ring.h"
#include "bodyarmor.h"
#include "helmet.h"
#include <cctype>


const int C_prefix_l = 2;
const int C_prefix_m = 5;
const int C_prefix_g = 10;

//const float C_dlvl_modifier = 1.25;

const int C_suffix = 5;
const float C_suffix_modifier = 1.25;


//Function that random picks a number for the Item-Type
std::string rng_loot_class_picker();

int loot_class_int_converter(std::string a);

//Function that checks DLevel of Player to sort quality of item
std::string dlvl_item_qual_check(Player& Player);

//Function to import name out of *.dat file
std::string import_itemname_data(const std::string& filename);

std::string suffix_picker();

void prefix_attributes(std::string prefix_item_quality, float& str, float& agi, float& sta, int& prefix_item_qual_modifer);

void suffix_attributes(std::string suffix, float& str, float& agi, float& sta, int a);

std::string itemname_builder(std::string item_type, std::string prefix_item_quality, std::string suffix);

std::string capitalize_Item_Name(std::string& item_name);

bool already_equip_check(std::string itemtype, Player& Player);


const std::string suffix_str = " of Strength"; //Only str
const std::string suffix_agi = " of Agility"; //Only agi
const std::string suffix_sta = " of Stamina"; //Only sta
const std::string suffix_bal = " of Balance"; //balanced
const std::string suffix_str_sta = " of Vitality"; //str + sta
const std::string suffix_str_agi = " of Bravery"; //str + agi
const std::string suffix_agi_sta = " of Dexterity"; //agi + sta




#endif