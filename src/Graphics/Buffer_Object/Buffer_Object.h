#ifndef BUFFER_OBJECT_H_INCLUDED
#define BUFFER_OBJECT_H_INCLUDED

#include <GL/glew.h>

class BufferObject
{
public:
    BufferObject * setX(GLfloat x);
    BufferObject * setY(GLfloat y);
    BufferObject * setZ(GLfloat z);

    BufferObject * setU(GLfloat u);
    BufferObject * setV(GLfloat v);

    BufferObject * setNX(GLfloat x);
    BufferObject * setNY(GLfloat y);
    BufferObject * setNZ(GLfloat z);

private:
    GLfloat m_x = 0.0f;
    GLfloat m_y = 0.0f;
    GLfloat m_z = 0.0f;

    GLfloat m_u = 0.0f;
    GLfloat m_v = 0.0f;

    GLfloat m_nX = 0.0f;
    GLfloat m_nY = 0.0f;
    GLfloat m_nZ = 0.0f;
};

#endif // BUFFER_OBJECT_H_INCLUDED
