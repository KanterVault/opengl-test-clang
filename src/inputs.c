#include "inputs.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (action == GLFW_PRESS)
    {
        pressed_keys[key] = 1;
    }
    if (action == GLFW_RELEASE)
    {
        pressed_keys[key] = 0;
    }
}