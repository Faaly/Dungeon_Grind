#include "../header/check.h"
#include <fstream>

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