#include <iostream>
#include <string>
#include <fstream>
#include "headers/json.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    std::ifstream f("Drive.json");
    json drvDat = json::parse(f);
    std::cout << "files\n";
    

    return 0;
}