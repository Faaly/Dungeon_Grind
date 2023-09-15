/*#include <fstream>
#include <iostream>
#include <string>

int main(){
std::ifstream inFile;
//float str;
//float agi;
//float sta;
//int lvl;
//int dlvl;
std::string DATA;
std::string savefile;
std::cout << "What file should be loaded?" << std::endl;
std::getline(std::cin, savefile);
inFile.open(savefile + ".dat");
if (!inFile)
{
    std::cout << "Error 404" << std::endl;
}
if (!inFile.is_open())
{
    std::cout << "Error : Failed to open " << savefile << std::endl;
    return 1;
}

std::cout << "Print Data from file : " << savefile << ".dat" << std::endl;
while (getline(inFile, DATA , ';'))
{
    std::cout << DATA << std::endl;
}


    

inFile.close();

    return 0;
}
*/