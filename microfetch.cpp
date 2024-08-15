#include <iostream>
#include <string>
#include <fstream>
#include "headers/json.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    std::ifstream f("Drive.json");
    json drvDat = json::parse(f);
    std::cout << "\n  user: " << argv[1] << "\n";
    std::cout << "  Miniux distro: " << drvDat["osName"] << "\n";
    std::cout << "  Drive Size: "  << round(((float) std::filesystem::file_size("Drive.json")/1000)*10)/10 << " KB\n";
    int pkgs = 0;
    float pkgsSize = 0;
    for (auto& package : std::filesystem::recursive_directory_iterator("pkgs")) {
        //check if file is a package
        std::string pkgNm = package.path().string();
        if (package.is_regular_file() && pkgNm.substr(pkgNm.size()-4) == ".min") {
            pkgs++;
            pkgsSize+=package.file_size();
        }
    }
    std::cout << "  Packages: " << pkgs << "\n";
    std::cout << "  Packages Size: " << round((pkgsSize / 1000000)*10)/10 << " MB\n\n";
	f.close();
    return 0;
}