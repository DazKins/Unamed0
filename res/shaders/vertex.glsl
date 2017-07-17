#version 330

in vec3 position;
in vec3 normal;
in vec2 texCoord;

uniform mat4 matrix;

void main()
{
    gl_Position = matrix * vec4 (position, 1.0);
}
