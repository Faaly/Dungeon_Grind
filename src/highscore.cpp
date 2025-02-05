#include "../header/highscore.h"
#include "../header/constants.h"
#include <string>
#include <vector>
#include <algorithm> //for std::sort
#include <iostream>
#include <fstream>
#include <iomanip> // text formatierung



//function for highscore system to sort all the entries.
    bool Highscore::operator<(const Highscore& other) const {
        if (hs_dlvl != other.hs_dlvl) {
            return hs_dlvl > other.hs_dlvl; //highest dlvl first
        }
        return hs_plvl > other.hs_plvl; //highest playerlvl first
    };


    void Highscoretable::addHighscore(const Highscore& score) {
        highscores.push_back(score);
        sortHighscore();
    }

    void Highscoretable::sortHighscore() {
        std::sort(highscores.begin(), highscores.end());
        if (highscores.size() > 10) {
            highscores.resize(10);
        }
    }

    void Highscoretable::displayHighscores() const {
        int rank = 1;
        for (const auto& score : highscores) {
            std::cout  << std::left <<  "  " << std::setw(2) << rank << std::setw(3) << " - " << std::setw(17) <<  score.hs_Name 
            << std::setw(6) << score.hs_dlvl
            << std::setw(9) << " ---  " << score.hs_plvl << "\n";
            rank++;
        }
    };


    void Highscoretable::save2File(const std::string& filename) {
        std::ofstream file("data/" + filename);
        if (!file) {
            std::cerr << c_ERROR_404;
            return;
        }

        for (const auto& score : highscores) {
            file << score.hs_Name << " " << score.hs_dlvl << " " << score.hs_plvl << "\n";
        }

        file.close();
    }


    void Highscoretable::loadFromFile(const std::string& filename) {
        std::ifstream file("data/" + filename);
        if (!file) {
            std::ofstream file("data/" + filename);
            file << "Haneko" << " " << "20" << " " << "20" << "\n";
            file << "Nime" << " " << "19" << " " << "19" << "\n";
            file << "Hecki" << " " << "18" << " " << "18" << "\n";
            file << "Bits" << " " << "17" << " " << "17" << "\n";
            file << "Iotalion" << " " << "16" << " " << "16" << "\n";
            file << "Lykary" << " " << "15" << " " << "15" << "\n";
            file << "Minn" << " " << "14" << " " << "14" << "\n";
            file << "Tikory" << " " << "13" << " " << "13" << "\n";
            file << "Jacki" << " " << "12" << " " << "12" << "\n";
            file << "Loranna" << " " << "11" << " " << "11" << "\n";

            file.close();

            return;
        }

        highscores.clear();//clear current list to fill it with new data from file

        std::string name;
        int dlvl, plvl;
        while (file >> name >> dlvl >> plvl) { //reads line by line
            highscores.emplace_back(name, dlvl, plvl);
            sortHighscore();//sort after load
        }
        file.close();

    }

// if player dies, save player name, level and dungeonlevel in file
