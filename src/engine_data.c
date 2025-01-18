#include "engine_data.h"

unsigned char pressed_keys[1000];
double time_delta = 0.0;
double time_deltaf = 0.0;
double fps = 60.0;

struct vector2f pos = { 0.0, 0.0 };

unsigned int shader;
unsigned int VS;
unsigned int FS;

cgltf_data** data;
int gltf_count;

void init_data()
{
    gltf_count = 0;
    data = malloc(sizeof(cgltf_data*) * MAX_GLTF_FILES);
    for (int i = 0; i < MAX_GLTF_FILES; i++) *(data + i) = malloc(sizeof(cgltf_data));
}

int add_gltf_data(cgltf_data* data_ptr)
{
    printf("Added new gltf data. Id: %d\n", gltf_count);
    if (gltf_count >= MAX_GLTF_FILES - 1) return -1;
    *(data + gltf_count) = data_ptr;
    gltf_count++;
    return 0;
}

void delete_data()
{
    for (int i = 0; i < MAX_GLTF_FILES; i++) free(*(data + i));
    free(data);
}
