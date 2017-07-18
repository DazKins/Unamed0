#version 330

out vec4 colour;

in vec3 pass_pos;

void main()
{
    colour = vec4 (1.0, 1.0, 0.0, 1.0) * vec4(pass_pos, 1.0);
}
