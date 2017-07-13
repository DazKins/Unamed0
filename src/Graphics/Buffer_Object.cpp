#include "Buffer_Object.h"

BufferObject::BufferObject(Shader::Shader_Program * shader)
{
    m_shader = shader;
}

BufferObject* BufferObject::setX(float x)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_x = x;
    return this;
}

BufferObject* BufferObject::setY(float y)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_y = y;
    return this;
}

BufferObject* BufferObject::setZ(float z)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_z = z;
    return this;
}

BufferObject* BufferObject::setU(float u)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_u = u;
    return this;
}

BufferObject* BufferObject::setV(float v)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_v = v;
    return this;
}

BufferObject* BufferObject::pushVertex()
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

    m_vertexCount++;

    return this;
}

BufferObject* BufferObject::pushIndex(int index)
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

    GLuint vertLoc = m_shader->getAttributeLocation("position");

    glVertexAttribPointer(vertLoc,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          5 * sizeof(GLfloat),
                          (GLvoid*) 0);

    glEnableVertexAttribArray(vertLoc);

    GLuint texLoc = m_shader->getAttributeLocation("texCoord");

    glVertexAttribPointer(texLoc,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          5 * sizeof(GLfloat),
                          (GLvoid*) (3 * sizeof(GLfloat)));

    glEnableVertexAttribArray(texLoc);

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
    m_shader->bind();

    glBindVertexArray(m_vaoID);
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
}
