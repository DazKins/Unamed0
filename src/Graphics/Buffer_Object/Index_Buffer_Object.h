#ifndef INDEX_BUFFER_OBJECT_H_INCLUDED
#define INDEX_BUFFER_OBJECT_H_INCLUDED

#include <vector>
#include <GL/glew.h>
#include <iostream>

#include "../Shader_Program.h"

class IndexBufferObject
{
public:
    IndexBufferObject();

    IndexBufferObject * setX(GLfloat x);
    IndexBufferObject * setY(GLfloat y);
    IndexBufferObject * setZ(GLfloat z);

    IndexBufferObject * setU(GLfloat u);
    IndexBufferObject * setV(GLfloat v);

    IndexBufferObject * setNX(GLfloat x);
    IndexBufferObject * setNY(GLfloat y);
    IndexBufferObject * setNZ(GLfloat z);

    IndexBufferObject * pushVertex();

    IndexBufferObject * pushIndex(GLuint index);
    IndexBufferObject * pushIndices(GLuint index0, GLuint index1, GLuint index2);

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

    void constructVBOs();
};

#endif // INDEX_BUFFER_OBJECT_H_INCLUDED
