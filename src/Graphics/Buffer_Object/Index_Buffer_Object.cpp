#include "Index_Buffer_Object.h"

IndexBufferObject::IndexBufferObject() { }

IndexBufferObject * IndexBufferObject::setX(GLfloat x)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_x = x;
    return this;
}

IndexBufferObject * IndexBufferObject::setY(GLfloat y)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_y = y;
    return this;
}

IndexBufferObject * IndexBufferObject::setZ(GLfloat z)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_z = z;
    return this;
}

IndexBufferObject * IndexBufferObject::setU(GLfloat u)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_u = u;
    return this;
}

IndexBufferObject * IndexBufferObject::setV(GLfloat v)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_v = v;
    return this;
}

IndexBufferObject * IndexBufferObject::setNX(GLfloat x)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nX = x;
    return this;
}

IndexBufferObject * IndexBufferObject::setNY(GLfloat y)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nY = y;
    return this;
}

IndexBufferObject * IndexBufferObject::setNZ(GLfloat z)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nZ = z;
    return this;
}

IndexBufferObject * IndexBufferObject::pushVertex()
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_data.push_back(m_x);
    m_data.push_back(m_y);
    m_data.push_back(m_z);

    m_data.push_back(m_u);
    m_data.push_back(m_v);

    m_data.push_back(m_nX);
    m_data.push_back(m_nY);
    m_data.push_back(m_nZ);

    m_vertexCount++;

    return this;
}

IndexBufferObject * IndexBufferObject::pushIndex(GLuint index)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_indices.push_back(index);

    m_indexCount++;

    return this;
}

IndexBufferObject * IndexBufferObject::pushIndices(GLuint index0, GLuint index1, GLuint index2)
{
    pushIndex(index0);
    pushIndex(index1);
    pushIndex(index2);

    return this;
}

void IndexBufferObject::start()
{
    m_isOpen = true;
}

void IndexBufferObject::stop()
{
    m_isOpen = false;
}

void IndexBufferObject::compile()
{
    if (m_isOpen)
    {
        std::cout << "Buffer object is open, cannot compile" << std::endl;
    }
    constructVBOs();
}

void IndexBufferObject::constructVBOs()
{
    glGenVertexArrays(1, &m_vaoID);
    glBindVertexArray(m_vaoID);

    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER,
                 m_data.size() * sizeof(GLfloat),
                 m_data.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(Shader::Shader_Program::VERTEX_LOCATION,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          s_vertexSize,
                          (GLvoid*) 0);

    glEnableVertexAttribArray(Shader::Shader_Program::VERTEX_LOCATION);

    glVertexAttribPointer(Shader::Shader_Program::TEXTURE_COORDINATE_LOCATION,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          s_vertexSize,
                          (GLvoid*) (3 * sizeof(GLfloat)));

    glEnableVertexAttribArray(Shader::Shader_Program::TEXTURE_COORDINATE_LOCATION);

    glVertexAttribPointer(Shader::Shader_Program::NORMAL_LOCATION,
                          3,
                          GL_FLOAT,
                          GL_TRUE,
                          s_vertexSize,
                          (GLvoid*) (5 * sizeof(GLfloat)));

    glEnableVertexAttribArray(Shader::Shader_Program::NORMAL_LOCATION);

    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 m_indices.size() * sizeof(GLuint),
                 m_indices.data(),
                 GL_STATIC_DRAW);
}

void IndexBufferObject::render()
{
    Shader::getDefaultShader()->bind();

    glBindVertexArray(m_vaoID);
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
