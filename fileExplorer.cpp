#include <iostream>
#include <string>
#include <fstream>
#include "headers/json.hpp"
using json = nlohmann::json;

/* 
files

Desktop                         -files["Desktop"]
\_.test2.txt                    -files["Desktop"]["content"]["test2.txt"]
\_images                        -files["Desktop"]["content"]["images"]
  \_.tophat.pxl                 -files["Desktop"]["content"]["images"]["content"]["tophat.pxl"]
.test.bzz                       -files["test.bzz"]

*/


int main(int argc, char* argv[]) {
    std::ifstream f("Drive.json");
    json drvDat = json::parse(f);
    std::cout << "files\n\n";
    json files = drvDat["users"][argv[1]]["files"]["content"];
    for (auto& dir : files.items()) {
        if (files[dir.key()]["type"] != "directory") {
            std::cout << ".";       
        }
        std::cout << dir.key() << "\n";
        // checking if its a dir
        if (files[dir.key()]["type"] == "directory") {
            std::cout << "\\_isdir\n";
        }
    }

    return 0;
}