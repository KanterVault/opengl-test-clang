#version 410 core

in vec4 inVert;
out vec4 FragColor;
void main()
{
    //FragColor = vec4(1.0f, inVert.y, inVert.z, 1.0f);
    FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}