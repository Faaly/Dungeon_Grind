#ifndef CHECK_H
#define CHECK_H
#include <sys/stat.h>
#include <sys/types.h>

bool DirIsThere(const char* path);

void CreateDir();

#endif