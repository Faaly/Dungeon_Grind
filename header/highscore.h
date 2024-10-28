#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <string>
#include <iostream>
#include <vector>

class Highscore {
public:
    std::string hs_Name;
    int hs_dlvl;
    int hs_plvl;

    Highscore() : hs_Name(""), hs_dlvl(0), hs_plvl(0) {}

    Highscore(std::string name, int dlvl, int plvl)
        : hs_Name(name), hs_dlvl(dlvl), hs_plvl(plvl) {}

    bool operator<(const Highscore& other) const;

};

class Highscoretable {
private: 
    std::vector<Highscore> highscores;


public:

void addHighscore(const Highscore& score);

void sortHighscore();

void displayHighscores() const;

void save2File(const std::string& filename);

void loadFromFile(const std::string& filename);
};



#endif