#include <iostream>
#include <Platform/WindowConfig.h>

int main(int argc, char* argv[]) {
	WindowConfig cfg;
	cfg.SetTitle("Hello, Scylla")
	   .SetSize({800, 600});

	std::cout << cfg.Size().x << " " << cfg.Size().y << std::endl;

	return 0; 
}