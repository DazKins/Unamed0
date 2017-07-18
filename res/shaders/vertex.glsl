#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

uniform mat4 matrix;

out vec3 pass_pos;

void main()
{
    gl_Position = matrix * vec4 (position, 1.0);

    pass_pos = position;
}
