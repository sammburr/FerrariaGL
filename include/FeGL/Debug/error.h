#ifndef FEGL_DEBUG_ERR
#define FEGL_DEBUG_ERR

/*
 *
 *	Terminate program with an error
 *
 */

#include <FeGL/GLFW/glfw.h>
#include <cstdlib>
#include <iostream>

// @brief Kill program and print message to output
// @params (const char*) message to print out
// @return (void)
void FeGLError(const char* _message) {
	std::cout << "\n\n<!>\n" << "Debug got an ERROR!\n" << _message << "\nStopping program...\n\n"; 

	// Kill other process
	FeGLTerminateGLFW();
	std::exit(-1);
}

#endif
