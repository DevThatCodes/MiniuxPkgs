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
    std::string cwd = argv[2];
    json files = drvDat["users"][argv[1]]["files"];
    system("clear");
    std::cout << "files: " + cwd + "\n\n";
    if (cwd != "/") {
        std::cout << "cwd is not root\n";
    }
    int dirs = 0;
    for (auto& dir : files.items()) {
        if (files[dir.key()]["type"] != "directory") {
            std::cout << ".";       
        } else if (files[dir.key()]["type"] == "directory") {
            std::cout << dirs << ",";
            dirs++;
        }
        std::cout << dir.key() << "\n";
    }

    return 0;
}