#include <iostream>
#include <string>
#include <fstream>
#include "headers/json.hpp"
#include "headers/moleculeMaker.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    std::ifstream f("Drive.json");
    json drvDat = json::parse(f);
    json saveDat = drvDat["users"][argv[1]]["files"];
    std::string cwd = argv[2];
    std::string savePathArg;
    std::cout << "enter savePath: " + cwd +"> ";
    std::cin >> savePathArg;
    system("clear");
    std::vector<std::string> savePath = {};
    std::string cfod; // current file or dir
    for (auto& ch : savePathArg) {
        if (ch=='/') {
            savePath.push_back(cfod);
            cfod = "";
        } else {
            cfod += ch;
        }
    }
    savePath.push_back(cfod); // TODO: there is probably a better way of doing this, but its 10pm and im tired
    cfod = "";
    for (auto& dir : savePath) {
        saveDat = saveDat[dir]["content"];
        if (dir == savePath.back()) {
            // if statement will get here if successfully found file. saveDat will equal the content of saveFile
            std::cout << "welcome to " << dir.erase(dir.size()-4, 4) << "\n";
            std::cout << "what do you want to do:\n(e)lement maker \n(m)olecule maker\n> ";
            std::string arg;
            std::cin >> arg;
            system("clear");
            if (arg == "m") {
                MoleculeMaker mm;
                std::string newSaveDat = mm.run(saveDat);
            }
        }
	f.close();
    return 0;
    }
}