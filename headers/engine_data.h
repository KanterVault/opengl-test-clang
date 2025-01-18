#ifndef ENGINE_DATA_SRC
#define ENGINE_DATA_SRC

#include "stdio.h"
#include "stdlib.h"
#include "vectors.h"
#include "cgltf.h"

#define MAX_GLTF_FILES 10

extern unsigned char pressed_keys[1000];
extern double time_delta;
extern double time_deltaf;
extern double fps;

extern struct vector2f pos;

extern unsigned int shader;
extern unsigned int VS;
extern unsigned int FS;

extern cgltf_data** data;
extern int gltf_count;

void init_data();
int add_gltf_data(cgltf_data* data_ptr);
void delete_data();

#endif