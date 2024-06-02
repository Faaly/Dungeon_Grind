#include "../header/check.h"

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
