#include "../header/loot.h"
#include "../header/player.h"
#include <fstream>
#include <vector>
#include <conio.h> // getch()
#include "../header/constants.h"
#include <cstdlib> // rand() function
#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <ctime>


//Function that random picks a number for the Item-Type
//1 Weapon
//2 Breastplate
//3 Helmet
//4 Ring
std::string rng_loot_class_picker(){
    std::string itemtype;
    int a = (rand() % 4) + 1;
    switch (a)
    {
    case 1:
        itemtype = "weapon";
        break;
    case 2:
        itemtype = "armor";
        break;
    case 3:
        itemtype = "helmet";
        break;
    case 4:
        itemtype = "ring";
        break;
    }
    return itemtype; 
}

int loot_class_int_converter(std::string a){
    int xy;

    if (a == "weapon")
    {
        xy = 1;
    } else if (a == "armor")
    {
        xy = 2;
    } else if (a == "helmet")
    {
        xy = 3;
    } else if (a == "ring")
    {
        xy = 4;
    }
    
    
    

    return xy;
}

//Function that checks DLevel of Player to sort quality of item
std::string dlvl_item_qual_check(Player& Player){
    std::string prefix;
    if (Player.get_DungeonLevel() < 16){
        prefix = "prefix_l"; // low
    }
    else if (Player.get_DungeonLevel() < 31){
        prefix = "prefix_m"; // mid
    }
    else {
        prefix = "prefix_g"; // good
    }           
    return prefix;
}

//Function that picks suffix from rng to loot.h
std::string suffix_picker(){
    std::string suffix;
    int a = (rand() % 7) + 1;
    switch (a)
    {
    case 1:
        suffix = suffix_str;
        break;
    case 2:
        suffix = suffix_agi;
        break;
    case 3:
        suffix = suffix_sta;
        break;
    case 4:
        suffix = suffix_bal;
        break;
    case 5:
        suffix = suffix_str_sta;
        break;
    case 6:
        suffix = suffix_str_agi;
        break;
    case 7:
        suffix = suffix_agi_sta;
        break;
    }

    return suffix;
}

//Function that generates prefix stats
void prefix_attributes(std::string prefix_item_quality, float& str, float& agi, float& sta, int& prefix_item_qual_modifer){
    if (prefix_item_quality == "prefix_l")
    {
        str = str + (rand() % C_prefix_l);
        agi = agi + (rand() % C_prefix_l);
        sta = sta + (rand() % C_prefix_l);
        prefix_item_qual_modifer  = 3;
    } else if (prefix_item_quality == "prefix_m")
    {
        str = str + (rand() % C_prefix_m);
        agi = agi + (rand() % C_prefix_m);
        sta = sta + (rand() % C_prefix_m);
        prefix_item_qual_modifer  = 7;
    } else if (prefix_item_quality == "prefix_g")
    {
        str = str + (rand() % C_prefix_g);
        agi = agi + (rand() % C_prefix_g);
        sta = sta + (rand() % C_prefix_g);
        prefix_item_qual_modifer  = 11;
    }
}

//Function that gives stats based on suffix and prefix
void suffix_attributes(std::string suffix, float& str, float& agi, float& sta, int a){
    if (suffix == suffix_str)
    {
        str = str + (rand() % a);
    } else if (suffix == suffix_agi)
    {
        agi = agi + (rand() % a);
    } else if (suffix == suffix_sta)
    {
        sta = sta + (rand() % a);
    } else if (suffix == suffix_str_agi)
    {
        str = str + (rand() % a);
        agi = agi + (rand() % a);
    } else if (suffix == suffix_str_sta)
    {
        str = str + (rand() % a);
        sta = sta + (rand() % a);
    } else if (suffix == suffix_agi_sta)
    {
        agi = agi + (rand() % a);
        sta = sta + (rand() % a);
    } else if (suffix == suffix_bal)
    {
        str = str +(rand() % a) * 0.50;
        int str_int = str;
        str = str_int;
        agi = agi + (rand() % a) * 0.50;
        int agi_int = agi;
        agi = agi_int;
        sta = sta + (rand() % a) * 0.50; 
        int sta_int = sta;
        sta = sta_int;
    }
}

//Function to import name out of *.dat file
std::string import_itemname_data(const std::string& filename){
    std::ifstream file("data/" + filename + ".dat");
    std::vector<std::string> names;

    if (file.is_open()){ //check if file is open
        std::string name;

        //read each line and store it in the names vector
        while (std::getline(file, name)){ 
            names.push_back(name);
        }
        file.close();
    
    
        if (!names.empty()){
            int randomIndex = rand() % names.size();
            return names[randomIndex];
        }
    } else {
        std::cerr << c_ERROR_001 << filename << std::endl;
    }

    return "";
}

std::string itemname_builder(std::string item_type, std::string prefix_item_quality, std::string suffix){
    std::string prefix = import_itemname_data(prefix_item_quality);
    std::string itemname = import_itemname_data(item_type);
    std::string name = prefix + " " + itemname + suffix;
    return name;
}

std::string capitalize_Item_Name(std::string& item_name){

    std::string result = item_name;

    result[0] = std::toupper(result[0]);

    return result;
}


bool already_equip_check(std::string itemtype, Player& Player){
    //bool PlayerHasAlreadyEquipmentOnSlot;
    const std::string noItemEquiped = "None";
    std::string playerItemName;

    if (itemtype == "helmet")
    {
        playerItemName = Player.get_helmet().get_Name();
        // player.helmet = "helm"
        // helm != "none"
        // true

        // player.helmet = "none"
        // none != none
        // false
        return Player.get_helmet().get_Name() != noItemEquiped;
        //if (playerItemName == noItemEquiped)
        //{
        //    return PlayerHasAlreadyEquipmentOnSlot = false;
        //}
    } 
    else if (itemtype == "ring")
    {
        playerItemName = Player.get_ring().get_Name();
        return Player.get_ring().get_Name() != noItemEquiped;
    } 
    else if(itemtype == "armor")
    {
        playerItemName = Player.get_bodyarmor().get_Name();
        return Player.get_bodyarmor().get_Name() != noItemEquiped;
    } //else PlayerHasAlreadyEquipmentOnSlot = true;

    return true;
}