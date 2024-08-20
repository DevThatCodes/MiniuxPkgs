#include <iostream>
#include <vector>
#include "asciiRenderer.hpp"

void Renderer::init(int shade, int width, int height) {
	std::vector<int> rowConstructor;
	for (int h=0;h<height;h++) {
		rowConstructor.push_back(shade);
	}
	for (int w=0;w<width;w++) {
		gBuffer.push_back(rowConstructor);	
	}
		
}
