#ifndef FEGL
#define FEGL

/*
 *
 *	Welcome to the FeGL engine.
 *	The purpose of this library is to handle boiler plate and annoying GL objects for both
 *	OpenGL (using Glad for C++) and GLFW.
 *
 */

#include <FeGL/glad/glad.h>
#include <FeGL/GLFW/glfw.h>
#include <FeGL/Debug/status.h>
#include <FeGL/Debug/error.h>

#define KEY_INPUT 	1301
#define MOUSE_INPUT	1302


// @brief The main class where all end user calls and functions are made available, (not including debugging which is an optional branch of this library)
class FeGL {

	private:
		// @brief Initalises the GLFW library and context window for the application
		// @params (void)
		// @return (void)
		void startGLFW();
		// @brief Initalises Glad to provide OpenGL calls
		void startGlad();

		static void FeGLKeyInputFun(GLFWwindow*, int, int, int, int);
		static void FeGLCursorInputFun(GLFWwindow*, double, double);

	public:
		// @brief Constructor initalises all components of the library and begins application calls
		// @params (void)
		FeGL();
		// @brief This is a user defined function (void FeGL::AppStart() {...definitions...}) called at the beggining of an application using FeGL.
		// @params (void)
		// @return (void)
		void AppStart();
		// @brief This is a user defined function (void FeGL::UpdateApp(float) {...definitions...}) called every application tick.
		// @params (float) delta, the calculated time between the current and preivous frame
		// @return (void)
		void AppUpdate(float);
		// @brief User defined function giving user access to inputs from GLFW (keyboard and mouse)
		// @params (int) input type (KEY_INPUT|MOUSE_INPUT), (int) key (KEY_x), (int) action (KEY_PRESS | KEY_RELEASE | KEY_REPEAT)), (double) mouse xpos, (double) mouse ypos
		// @return (void)
		static void AppInput(int, int, int, double, double);

};

// @brief Key callback function for use by GLFW to call user defined function AppInput
// @params (GLFWkeyfun)
// @return (void)
void FeGL::FeGLKeyInputFun(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods) {
	AppInput(KEY_INPUT, _key, _action, 0.0d, 0.0d);
}


// @brief Mouse callback function for use by GLFW to call user defined function AppInput
// @params (GLFWkeyfun)
// @return (void)
void FeGL::FeGLCursorInputFun(GLFWwindow* _window, double _xpos, double _ypos) {
	AppInput(MOUSE_INPUT, 0, 0, _xpos, _ypos);
}

/*
 *	Definitons for class: FeGL
 */

FeGL::FeGL() {
	// Start by initalising external libraries
	startGLFW();
	startGlad();
	// Call AppStart
	AppStart();
	// Init glViewport
	glViewport(0, 0, 800, 600);
	// Start main loop (dictated by GLFW)
	// TODO: calculate delta
	while(!FeGLShouldWindowClose()) {
		// Call AppUpdate
		AppUpdate(0.0f);
		// Poll GLFW events
		FeGLPollGLFWEvents();
	}
}

void FeGL::startGLFW() {
	// Initalise GLFW
	if(FeGLStartGLFW() == FAILURE)
		FeGLError("Failed to start GLFW!");
	// Create window
	if(FeGLCreateWindow(800, 600, "Hello") == FAILURE)
		FeGLError("Failed to create a GLFW window!");
	// Add GLFW input callbacks
	FeGLAttachInputCallbacks(FeGLKeyInputFun,FeGLCursorInputFun);
}

void FeGL::startGlad() {
	// Initalise Glad
	if(FeGLStartGlad() == FAILURE)
		FeGLError("Failed to start Glad!");
}

/*
 *	Helper functions
 */

// @brief Clear buffer GL buffer bits
// @params (void)
// @return (void)
void clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
#endif
