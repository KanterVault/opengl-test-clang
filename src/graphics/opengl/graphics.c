#include "graphics.h"
#include "engine_data.h"

unsigned int VAO;
unsigned int VBO;
unsigned int EBO;

GLint xLoc = 0;
const void* vert_data;
int ver_size;
int ver_offset;

const void* ind_data;
int ind_size;
int ind_offset;

int init_graphics()
{
    glUseProgram(shader);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    ver_size = ((*data)->buffer_views + 0)->size;
    ver_offset = ((*data)->buffer_views + 0)->offset;
    vert_data = ((*data + 0)->bin + ver_offset);

    ind_size = ((*data)->buffer_views + 3)->size;
    ind_offset = ((*data)->buffer_views + 3)->offset;
    ind_data = ((*data + 0)->bin + ind_offset);

    glBufferData(GL_ARRAY_BUFFER, ver_size, vert_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_size, ind_data, GL_STATIC_DRAW);

    GLint locPos = glGetAttribLocation(shader, "aPos");
    glVertexAttribPointer(locPos, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(locPos);

    xLoc = glGetUniformLocation(shader, "xy");
    return 0;
}

void update()
{
    if (pressed_keys[GLFW_KEY_W]) pos.y += MOV_SPEED * time_deltaf;
    if (pressed_keys[GLFW_KEY_S]) pos.y -= MOV_SPEED * time_deltaf;
    if (pressed_keys[GLFW_KEY_A]) pos.x -= MOV_SPEED * time_deltaf;
    if (pressed_keys[GLFW_KEY_D]) pos.x += MOV_SPEED * time_deltaf;
    glUniform2f(xLoc, pos.x, pos.y);
    glUseProgram(shader);
    glBindVertexArray(VAO);
    //printf("%d\n", ind_size / sizeof(unsigned short) / 3);
    glDrawElements(GL_TRIANGLES, ver_size, GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
}






// printf("ver_size: %d\n", ver_size);
// printf("ver_offset: %d\n", ver_offset);
// printf("ind_size: %d\n", ind_size);
// printf("ind_offset: %d\n", ind_offset);
// printf("buffer_size: %d\n", ((*data)->buffers + 0)->size);

// printf("\n\n\n\n");
// for (int i = 0; i < 6; i++)
// {
//     printf("X: %f\n", *((float*)vert_data + (i * 3)));
//     printf("Y: %f\n", *((float*)vert_data + (i * 3) + 1));
//     printf("Z: %f\n\n", *((float*)vert_data + (i * 3) + 2));
// }
// printf("\n\n");
// for (int i = 0; i < 6; i++)
// {
//     printf("INDEX: %d\n", *((unsigned short*)ind_data + i));
// }
// printf("\n\n\n\n");