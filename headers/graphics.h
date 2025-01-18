#ifndef GRAPHICSLOOP
#define GRAPHICSLOOP

#include <stdio.h>
#include <glad.h>
#include <gl.h>
#include <glfw3.h>
#include <string.h>
#include "engine_data.h"

#define MOV_SPEED 0.1f

int init_graphics();
void update();

#endif