#ifndef FEGL_GLFW
#define FEGL_GLFW

#include <GLFW/glfw3.h>
#include <FeGL/Debug/status.h>

/*
 *
 *	This library is used to call boiler plate on the GLFW library
 *
 */

// Publically accessable GLFWwindow*
// TODO: Make more elgant for application using more than one window.
GLFWwindow* window;

// @brief Startup GLFW library
// @params (void)
// @return (int) status code
int FeGLStartGLFW() {
	if(!glfwInit())
		return FAILURE;
	// Set hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return SUCCESS;
}
// @brief Create window context
// @params (unsigned int) width, (unsigned int) height, (const char*) title for window
// @return (int) status code
int FeGLCreateWindow(unsigned int _width, unsigned int _height, const char* _title) {
	window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if(!window)
		return FAILURE;
	// Make this window the current context, TODO: see above for multiple contexts
	glfwMakeContextCurrent(window);
	return SUCCESS;
}
// @brief Call the termination function in GLFW to clean up
// @params (void)
// @return (void)
void FeGLTerminateGLFW() {
	glfwTerminate();
}
// @brief Test if glfw says window should close
// @params (void)
// @return (bool)
bool FeGLShouldWindowClose() {
	return glfwWindowShouldClose(window);
}
// @brief Poll GLFW events
// @params (void)
// @return (void)
void FeGLPollGLFWEvents() {
	glfwPollEvents();
	// Also swap buffers TODO: put in a more sensible place
	glfwSwapBuffers(window);
}
// @brief Attach input callback functions
// @parans (void(* GLFWkeyfun)) callback for key press, (void*( GLFWmousebuttonfun)) callback for mouse movement
// @return (void)
void FeGLAttachInputCallbacks(void(* _keyCallback)(GLFWwindow*, int, int, int, int) , void(* _mouseCallback)(GLFWwindow*, double, double)) {
	glfwSetKeyCallback(window, _keyCallback);
	glfwSetCursorPosCallback(window, _mouseCallback);
}
#endif
