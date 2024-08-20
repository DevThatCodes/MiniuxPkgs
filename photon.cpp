#include <unistd.h>
#include <iostream>
#include <string>

void draw(int width, int height) {
	std::string window = "";
	window += "/";
	for (int i=0;i<width-2;i++) {
		window += "-";
	}
	window += "\\\n";
	for (int i=0;i<height-2;i++) {
		window +="|";
		for (int j = 0;j<width-2;j++) {
			window +=" ";
		}
		window +="|\n";
	}
	window += "\\";
	for (int i=0;i<width-2;i++) {
		window += "-";
	}
	window += "/\n";
	std::cout << window;
}

int main(int argc, char *argv[]) {
	// arguments: proton width height refreshRate ramAddr
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int refreshRate = atoi(argv[3]);
	int ramAddr = atoi(argv[4]);
	std::cout << "width: " << width << "\nheight: " << height << "\n";
	if ((width < 15) || (height < 4)) {
		std::cout << "window too small! has to be atleast 4x15.\n";
		return 0;
	}
	system("clear");
	while (true) {
		system("clear");
		draw(width, height);
		std::cout << "ramAddr: " << ramAddr << "\n";
		usleep(1000/refreshRate);
	}


	return 0;
}
