#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "ram.hpp"

int RamManager::openRam(std::string path) {
	if (std::filesystem::exists(path)) {
		ram.open(path);
	} else { return 1; }
	return 0;
}

int RamManager::closeRam() {
	ram.close();
}

int loadAddr(int addrIdParam) {
	if (addrIdParam >= 0) {
		addrId = addrIdParam;
		return 0;
	} else {
		addrId = -1;
		return 1;
	}
}
