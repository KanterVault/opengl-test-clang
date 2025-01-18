#include "shader_compillers.h"

char infoLog[512];
int success;

int compileVS()
{
    struct FILE_CONTENT fc = read_file("shaders/vert.glsl");
    if (fc.return_code != (enum FileReadErrors)NOT_ERRORS)
    {
        printf("File error: %d", fc.return_code);
        return fc.return_code;
    }
    VS = glCreateShader(GL_VERTEX_SHADER);
    const GLchar *shPtr = (const GLchar*)fc.contentPtr;
    glShaderSource(VS, 1, &shPtr, NULL);
    glCompileShader(VS);
    //free(fc.contentPtr);
    glGetShaderiv(VS, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(VS, 512, NULL, infoLog);
        printf("Vertex shader error: %s\n.", infoLog);
        return -1;
    }
    return 0;
}

int compileFS()
{
    struct FILE_CONTENT fc = read_file("shaders/frag.glsl");
    if (fc.return_code != (enum FileReadErrors)NOT_ERRORS)
    {
        printf("File error: %d", fc.return_code);
        return fc.return_code;
    }
    FS = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar *shPtr = (const GLchar*)fc.contentPtr;
    glShaderSource(FS, 1, &shPtr, NULL);
    glCompileShader(FS);
    //free(fc.contentPtr);
    glGetShaderiv(FS, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(FS, 512, NULL, infoLog);
        printf("Fragment shader error: %s\n.", infoLog);
        return -1;
    }
    return 0;
}

int compileProgram()
{
    shader = glCreateProgram();
    glAttachShader(shader, VS);
    glAttachShader(shader, FS);
    glLinkProgram(shader);
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader, 512, NULL, infoLog);
        printf("Shader program error: %s\n.", infoLog);
        return -1;
    }
    return 0;
}

int init_shaders()
{
    if (compileVS() != 0)
    {
        printf("Compile VS error.\n");
        return -1;
    }
    if (compileFS() != 0)
    {
        printf("Compile FS error.\n");
        return -1;
    }
    if (compileProgram() != 0)
    {
        printf("Compile program error.\n");
        return -1;
    }
}