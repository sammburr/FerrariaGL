#ifndef FEGL_GLAD
#define FEGL_GLAD

/*
 *
 *	This library is used to call boiler plate on the glad library
 *
 */

#include <FeGL/Debug/status.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../../src/glad.c"

// @brief Starup glad
// @params (void)
// @return (int) status
int FeGLStartGlad() {
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return FAILURE;
	return SUCCESS;
}


#endif
