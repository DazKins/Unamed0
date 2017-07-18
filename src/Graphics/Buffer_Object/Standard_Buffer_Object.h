#ifndef STANDARD_BUFFER_OBJECT_H_INCLUDED
#define STANDARD_BUFFER_OBJECT_H_INCLUDED

#include <GL/glew.h>
#include <vector>
#include <iostream>

#include "../../Maths/GLM.h"
#include "../Shader_Program.h"

class StandardBufferObject
{
public:
    StandardBufferObject();

    StandardBufferObject * setX(GLfloat x);
    StandardBufferObject * setY(GLfloat y);
    StandardBufferObject * setZ(GLfloat z);

    StandardBufferObject * setU(GLfloat u);
    StandardBufferObject * setV(GLfloat v);

    StandardBufferObject * setNX(GLfloat x);
    StandardBufferObject * setNY(GLfloat y);
    StandardBufferObject * setNZ(GLfloat z);

    StandardBufferObject * setPosition(const Vector3& v);
    StandardBufferObject * setNormal(const Vector3& v);
    StandardBufferObject * setTextureCoord(const Vector2& v);

    StandardBufferObject * setAttribs(const Vector3& pos, const Vector2& tex, Vector3& norm);

    StandardBufferObject * pushVertex();

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

    GLuint m_vertexCount = 0;

    GLuint m_vboID = 0;
};

#endif // STANDARD_BUFFER_OBJECT_H_INCLUDED
