#include <iostream>
#include <string>

int main() {
    std::string arg;
    std::cout << "pkg url> ";
    std::cin >> arg;
    if (arg == "update") {
        system("rm miniux.o");
        system("wget https://github.com/DevThatCodes/Miniux/releases/download/v0.04b-alpha/miniux.o");
    } else if (arg == "remove") {
        std::cout << "pkg name> ";
        std::cin >> arg;
        std::string cmd = "rm pkgs/" + arg + ".min";
        system(cmd.c_str());
    } else {
        std::string cmd = "cd pkgs && wget " + arg + " && chmod +x " + arg + ".min";
        system(cmd.c_str());
    }

    return 0;
}