#include <iostream>
#include <string>
#include <fstream>
#include "headers/json.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    std::ifstream f("Drive.json");
    json drvDat = json::parse(f);
    std::string cwd = argv[2];
    system("clear");
    std::cout << "Welcome to atomio\n";
    std::string savePath;
    std::cout << "enter savePath: " + cwd +"> ";
    std::cin >> savePath;
    return 0;
}