#ifndef SHADERCOMPILLERS
#define SHADERCOMPILLERS

#include <glad.h>
#include "fileloader.h"
#include "engine_data.h"

extern char infoLog[512];
extern int success;

int compileVS();
int compileFS();
int compileProgram();
int init_shaders();

#endif