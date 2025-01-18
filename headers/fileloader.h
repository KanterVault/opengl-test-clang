#ifndef SHADER_LOADER
#define SHADER_LOADER

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

#define SLASH_CHAR (char)'\\'
#define FILE_PATH_SIZE (sizeof(char) * 200)
#define FILE_BUFF_SIZE (sizeof(char) * 1024)

enum FileReadErrors
{
    NOT_ERRORS,
    FILE_NOT_OPEN,
    FSEEK_ERROR,
    GET_FILE_SIZE_ERROR,
    MEMORY_NOT_ALLOC,
    FILE_NOT_CLOSED
};

struct FILE_CONTENT
{
    enum FileReadErrors return_code;
    char *contentPtr;
    GLint file_size;
};

struct FILE_CONTENT read_file(char *path);

#endif