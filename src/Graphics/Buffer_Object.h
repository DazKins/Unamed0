#ifndef BUFFER_OBJECT_H_INCLUDED
#define BUFFER_OBJECT_H_INCLUDED

#include <vector>
#include <GL/glew.h>
#include <iostream>

#include "Shader_Program.h"

class BufferObject
{
public:
    BufferObject(Shader::Shader_Program * shader = Shader::getDefaultShader());

    BufferObject* setX(float x);
    BufferObject* setY(float y);
    BufferObject* setZ(float z);

    BufferObject* setU(float u);
    BufferObject* setV(float v);

    BufferObject* pushVertex();

    BufferObject* pushIndex(int index);

    void render();
    void start();
    void stop();
    void compile();

private:
    bool m_isOpen;

    GLfloat m_x = 0.0f;
    GLfloat m_y = 0.0f;
    GLfloat m_z = 0.0f;

    GLfloat m_u = 0.0f;
    GLfloat m_v = 0.0f;

    std::vector<GLfloat> m_data;
    std::vector<GLuint> m_indices;

    GLuint m_vertexCount = 0;
    GLuint m_indexCount = 0;
    GLuint m_vboCount = 0;

    GLuint m_vaoID = 0;

    Shader::Shader_Program * m_shader;

    void constructVBOs();
};

#endif // BUFFER_OBJECT_H_INCLUDED
