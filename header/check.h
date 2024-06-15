#ifndef CHECK_H
#define CHECK_H
#include <sys/stat.h>
#include <sys/types.h>

bool DirIsThere(const char* path);

int DataDir_Error();

void CreateDir();

bool data_armor_check(bool &a);
bool data_helmet_check(bool &a);
bool data_prefix_g_check(bool &a);
bool data_prefix_l_check(bool &a);
bool data_prefix_m_check(bool &a);
bool data_ring_check(bool &a);
bool data_weapon_check(bool &a);

#endif