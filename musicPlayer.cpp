#include <iostream>
#include <string>
#include <fstream>
#include "headers/json.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    std::ifstream f("Drive.json");
    json drvDat = json::parse(f);
    std::cout << "Mosquito\n";
    std::string filePath;
    std::cout << "path to sound> ";
    std::cin >> filePath;
    std::cout << (std::string) drvDat["users"][argv[1]]["dsplName"] + "\n";

    return 0;
}