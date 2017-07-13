#version 330

in vec3 position;
in vec2 texCoord;

uniform mat4 matrix;

out vec3 pos;

void main()
{
    gl_Position = matrix * vec4 (position, 1.0);

    pos = position;
}
