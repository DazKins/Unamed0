#include "Buffer_Object.h"

BufferObject::BufferObject()
:   m_shader (Shader::getDefaultShader())
{
}

BufferObject * BufferObject::setX(GLfloat x)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_x = x;
    return this;
}

BufferObject * BufferObject::setY(GLfloat y)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_y = y;
    return this;
}

BufferObject * BufferObject::setZ(GLfloat z)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_z = z;
    return this;
}

BufferObject * BufferObject::setU(GLfloat u)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_u = u;
    return this;
}

BufferObject * BufferObject::setV(GLfloat v)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_v = v;
    return this;
}

BufferObject * BufferObject::setNX(GLfloat x)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nX = x;
    return this;
}

BufferObject * BufferObject::setNY(GLfloat y)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nY = y;
    return this;
}

BufferObject * BufferObject::setNZ(GLfloat z)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nZ = z;
    return this;
}

BufferObject * BufferObject::pushVertex()
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

BufferObject * BufferObject::pushIndex(GLuint index)
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

void BufferObject::start()
{
    m_isOpen = true;
}

void BufferObject::stop()
{
    m_isOpen = false;
}

void BufferObject::compile()
{
    constructVBOs();
}

void BufferObject::constructVBOs()
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

    GLuint vertLoc = Shader::getDefaultShader()->getAttributeLocation("position");

    if (vertLoc == -1)
    {
        std::cout << "Vertex attribute location not found" << std::endl;
    }

    glVertexAttribPointer(vertLoc,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          s_vertexSize,
                          (GLvoid*) 0);

    glEnableVertexAttribArray(vertLoc);

    GLuint texLoc = Shader::getDefaultShader()->getAttributeLocation("texCoord");

    if (texLoc == -1)
    {
        std::cout << "Texture coordinate attribute location not found (may have been discarded at compile time)" << std::endl;
    }

    glVertexAttribPointer(texLoc,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          s_vertexSize,
                          (GLvoid*) (3 * sizeof(GLfloat)));

    glEnableVertexAttribArray(texLoc);

    GLuint normLoc = Shader::getDefaultShader()->getAttributeLocation("normal");

    if (normLoc == -1)
    {
        std::cout << "Normal attribute location not found (may have been discarded at compile time)" << std::endl;
    }

    glVertexAttribPointer(normLoc,
                          3,
                          GL_FLOAT,
                          GL_TRUE,
                          s_vertexSize,
                          (GLvoid*) (5 * sizeof(GLfloat)));

    glEnableVertexAttribArray(normLoc);

    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 m_indices.size() * sizeof(GLuint),
                 m_indices.data(),
                 GL_STATIC_DRAW);
}

void BufferObject::render()
{
    Shader::getDefaultShader()->bind();

    glBindVertexArray(m_vaoID);
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
}
