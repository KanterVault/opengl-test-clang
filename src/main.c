#define CGLTF_IMPLEMENTATION
#include "main.h"
#include "loadmodel.h"
#include "engine_data.h"
#include "shader_compillers.h"
#include "material.h"
#include "graphics.h"
#include "inputs.h"

GLFWwindow* window;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int delete()
{
    delete_data();
    glfwDestroyWindow(window);
    glfwTerminate();
    return -1;
}

int main(void)
{
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    //Fullscreen
    // GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    // const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    // window = glfwCreateWindow(mode->width, mode->height, "Simple example", monitor, NULL);

    //Windowed
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD.\n");
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }
    glfwSwapInterval(1);
    float ratio;
    int width, height;
    double last_time = 0.0;
    double current_time = 0.0;
    double counter = 0.0;
    char title_src[36];

    init_data();
    if (init_shaders() != 0)
    {
        printf("Init shaders error.\n");
        return delete();
    }
    if (load_models() != 0)
    {
        printf("Models not loaded.\n");
        return delete();
    }
    if (init_graphics() != 0)
    {
        printf("Init error.\n");
        return delete();
    }
    while (!glfwWindowShouldClose(window))
    {
        current_time = glfwGetTime();
        time_delta = (current_time - last_time) * 10.0;
        time_deltaf = (float)time_delta;
        last_time = current_time;
        if (counter < current_time)
        {
            counter += 0.05;
            if (time_delta < 0.0001) time_delta = 0.0001;
            fps = 10.0 / time_delta;
            sprintf(title_src, "3D Engine FPS: %3d (%2.4fms)", (int)fps, time_delta);
            glfwSetWindowTitle(window, (const char*)title_src);
            glfwGetFramebufferSize(window, &width, &height);
            ratio = width / (float) height;
            glViewport(0, 0, width, height);
        }
        glClear(GL_COLOR_BUFFER_BIT);
        update();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}