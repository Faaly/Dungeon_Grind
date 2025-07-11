#include "../header/check.h"
#include "../header/constants.h"
#include "../header/utility.h"
#include <fstream>
#include <iostream>
#include <limits>

// std::string buildnumber(){
//     std::time_t t = std::time(nullptr); //grabs current date
//     std::tm now = *std::localtime(&t); //converts into local time
//     std::ostringstream datestream;
//     datestream  << (now.tm_year + 1900) //year because it starts at 1900 and counts upwards
//                 << std::setw(2) << std::setfill('0') << (now.tm_mon + 1) //Month (0based thats why +1) 
//                 << std::setw(2) << std::setfill('0') << now.tm_mday;

//     return datestream.str();
// };

namespace fs = std::filesystem;
std::vector<std::string> listSaveGames(const std::string& Dir){
    
    std::vector<std::string> saveGames;
    clearScreen();
    std::cout << "\n\n\nAvailble Save Files:\n\n";

    int i = 1;
    for (const auto& entry : fs::directory_iterator(Dir)) {
        if(entry.is_regular_file() && entry.path().extension() == ".dat") {
            std::cout <<"(" << i << ") " << entry.path().filename().string() << "\n\n";
            std::string filename = entry.path().stem().string();
            saveGames.push_back(filename);
            i++;
        }
    }
    return saveGames;
}

std::string chooseSaveGames(const std::vector<std::string>& saveGames){
    if (saveGames.empty()) //File doesn't exist - Error 404
    {
        std::cout << c_ERROR_404 << std::endl;
        return "";
    }

    int choice = 0;
    std::cout << "What file should be loaded?\nPlease enter the number of the adventurer \nto load your game-file:" << std::endl;
    
    while (true) {
        if (std::cin >> choice && choice >= 1 && choice <= static_cast<int>(saveGames.size())) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return saveGames[choice - 1];
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
            std::cout << c_ERROR_002 << std::endl;
        }
    }
}

bool DirIsThere(const char* path) {
    struct stat info;
    if (stat(path, &info) != 0) {
        return false;
    }
    return (info.st_mode & S_IFDIR) != 0;
}

void CreateDir() {
    const char* path = "savegames";

    if (DirIsThere(path) == false) {
        mkdir(path);
    }
}

int DataDir_Error() {
    const char* path = "data";

    if (DirIsThere(path) == false) {
        return 1;
    }
    else {
        return 2;
    }
}

bool data_armor_check(bool &a)
{
    std::ifstream armor;
    armor.open("data/armor.dat");
    if (!armor)
    {
            return a = false;
    }
    return a = true;
}

bool data_helmet_check(bool &a)
{
    std::ifstream helmet;
    helmet.open("data/helmet.dat");
    if (!helmet)
    {
            return a = false;
    }
    return a = true;
}

bool data_prefix_g_check(bool &a)
{
    std::ifstream prefix_g;
    prefix_g.open("data/prefix_g.dat");
    if (!prefix_g)
    {
            return a = false;
    }
    return a = true;
}

bool data_prefix_l_check(bool &a)
{
    std::ifstream prefix_l;
    prefix_l.open("data/prefix_l.dat");
    if (!prefix_l)
    {
            return a = false;
    }
    return a = true;
}

bool data_prefix_m_check(bool &a)
{
    std::ifstream prefix_m;
    prefix_m.open("data/prefix_m.dat");
    if (!prefix_m)
    {
            return a = false;
    }
    return a = true;
}

bool data_ring_check(bool &a)

{
    std::ifstream ring;
    ring.open("data/ring.dat");
    if (!ring)
    {
            return a = false;
    }
    return a = true;
}
bool data_weapon_check(bool &a)
{
    std::ifstream weapon;
    weapon.open("data/weapon.dat");
    if (!weapon)
    {
            return a = false;
    }
    return a = true;
}

bool highscore_check(bool &a)
{
    std::ifstream hsfile;
    hsfile.open("data/highscore.dat");
    if (!hsfile)
    {
            return a = false;
    }
    return a = true;
}