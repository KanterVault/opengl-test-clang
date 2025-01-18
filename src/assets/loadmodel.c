#include "loadmodel.h"

int load_models()
{
    cgltf_options options = {0};
    cgltf_data* data = NULL;
    cgltf_result result = cgltf_parse_file(&options, "models/triangle.glb", &data);
    if (result == cgltf_result_success)
    {
        add_gltf_data(data);
        printf("Loaded gltf data.\n");
    }
    else
    {
        return result;
    }
    return 0;
}