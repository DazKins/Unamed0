#ifndef BUFFER_OBJECT_H_INCLUDED
#define BUFFER_OBJECT_H_INCLUDED

#include <vector>
#include <GL/glew.h>
#include <iostream>

#include "Shader_Program.h"

class BufferObject
{
public:
    BufferObject();

    BufferObject * setX(GLfloat x);
    BufferObject * setY(GLfloat y);
    BufferObject * setZ(GLfloat z);

    BufferObject * setU(GLfloat u);
    BufferObject * setV(GLfloat v);

    BufferObject * setNX(GLfloat x);
    BufferObject * setNY(GLfloat y);
    BufferObject * setNZ(GLfloat z);

    BufferObject * pushVertex();

    BufferObject * pushIndex(GLuint index);

    void render();
    void start();
    void stop();
    void compile();

private:
    const static GLuint s_vertexSize = 8 * sizeof(GLfloat);

    bool m_isOpen;

    GLfloat m_x = 0.0f;
    GLfloat m_y = 0.0f;
    GLfloat m_z = 0.0f;

    GLfloat m_u = 0.0f;
    GLfloat m_v = 0.0f;

    GLfloat m_nX = 0.0f;
    GLfloat m_nY = 0.0f;
    GLfloat m_nZ = 0.0f;

    std::vector<GLfloat> m_data;
    std::vector<GLuint> m_indices;

    GLuint m_vertexCount = 0;
    GLuint m_indexCount = 0;

    GLuint m_vaoID = 0;

    Shader::Shader_Program * m_shader;

    void constructVBOs();
};

#endif // BUFFER_OBJECT_H_INCLUDED
