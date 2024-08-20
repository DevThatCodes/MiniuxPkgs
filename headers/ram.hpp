#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#ifndef RAMMANAGER
#define RAMMANAGER

class RamManager {
	private:
		std::fstream ram;
		int addrId;
		std::string addrDat;
	public:	
		int openRam(std::string path);
		int loadAddr(int addrId);
		std::string read();
		int write(std::string data);
		int closeRam();
};

#endif
