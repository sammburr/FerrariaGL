#include <FeGL/fegl.h>

//TODO: Intergrate debuger
#include <iostream>

int main(void) {
	FeGL Engine;
	return 0;
}

void FeGL::AppStart() {

	// Set a screen clear color
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

}

void FeGL::AppUpdate(float _delta) {

	clearScreen();
}

void FeGL::AppInput(int _type, int _key, int _action, double _mouseX, double _mouseY) {

	std::cout << _mouseX << "," << _mouseY << std::endl;

}
