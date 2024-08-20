#include <iostream>
#include <vector>
#include <string>
#ifndef ASCIIRENDERER
#define ASCIIRENDERER

class Renderer {
	private:
		std::vector<std::vector<int>> gBuffer;
		std::string shades = " .,:ilwW";
	public:	
		void drawChar(int shade, int x, int y);
		void init(int shade, int width, int height);
};
#endif
