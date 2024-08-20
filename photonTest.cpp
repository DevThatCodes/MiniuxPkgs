#include <iostream>
#include <fstream>
#include "headers/asciiRenderer.hpp"

int main(int argc, char *argv[]) {
	std::fstream ram("ram.mpcc");
	std::string addr="";
	std::string addrId="";
	Renderer renderer;
	renderer.init(atoi(argv[1]),0,0);
	
	while (getline(ram,addr)) {
		addrId="";
		for (auto& ch : addr) {
			if (ch == ':') {
				break;
			} else {
				addrId += ch;
			}
		}
	}
	if (addrId=="") {
		addrId="-1";
	}
	addrId = std::to_string(stoi(addrId) + 1);
	std::cout << "running on " << addrId.data() << "\n";

	ram.close();
	return 0;
}
