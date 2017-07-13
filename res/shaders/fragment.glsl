#version 330

out vec4 colour;

in vec3 pos;

void main()
{
    //colour = vec4 (1.0, 0.0, 1.0, 1.0) * vec4 (pos.z + 0.1, pos.x + 0.1, pos.y + 0.1, 1.0);
    colour = vec4 (1.0, 1.0, 0.0, 1.0);
}
