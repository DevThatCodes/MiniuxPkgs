#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#include "moleculeMaker.hpp"
using json = nlohmann::json;

std::string MoleculeMaker::run(std::string saveData) {
    std::vector<std::vector<std::string>> elements;
    std::vector<std::string> atomMaker; // atomName:atomSymbol:valenceElect:fullValenceElect-
    std::string dat;
    for (auto& ch : saveData) {
        if (ch == ':') {
            atomMaker.push_back(dat);
            dat = "";
        } else if (ch == '-') {
            atomMaker.push_back(dat);
            elements.push_back(atomMaker);
            atomMaker = {};
            dat = "";
        } else {
            dat += ch;
        }
    }
    for (auto& element : elements) {
        std::cout << element[0] << "\n";
    }
    return saveData;
}