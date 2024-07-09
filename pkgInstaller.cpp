#include <iostream>
#include <string>

int main() {
    std::string arg;
    std::cout << "pkg url> ";
    std::cin >> arg;
    std::string cmd = "cd pkgs && wget " + arg;
    system(cmd.c_str());

    return 0;
}