#version 410 core

in vec3 aPos;
out vec4 inVert;
uniform vec2 xy;

void main()
{
    gl_Position = vec4(aPos.x + xy.x, aPos.y + xy.y, aPos.z, 1.0);
    inVert = gl_Position;
}