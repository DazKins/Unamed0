#include "Standard_Buffer_Object.h"

StandardBufferObject::StandardBufferObject() { }

StandardBufferObject * StandardBufferObject::setX(GLfloat x)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_x = x;
    return this;
}

StandardBufferObject * StandardBufferObject::setY(GLfloat y)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_y = y;
    return this;
}

StandardBufferObject * StandardBufferObject::setZ(GLfloat z)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_z = z;
    return this;
}

StandardBufferObject * StandardBufferObject::setPosition(const Vector3& v)
{
    setX(v.x);
    setY(v.y);

    return setZ(v.z);
}

StandardBufferObject * StandardBufferObject::setU(GLfloat u)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_u = u;
    return this;
}

StandardBufferObject * StandardBufferObject::setV(GLfloat v)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_v = v;
    return this;
}

StandardBufferObject * StandardBufferObject::setNX(GLfloat x)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nX = x;
    return this;
}

StandardBufferObject * StandardBufferObject::setNY(GLfloat y)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nY = y;
    return this;
}

StandardBufferObject * StandardBufferObject::setNZ(GLfloat z)
{
    if (!m_isOpen)
    {
        std::cout << "ERROR: Buffer Object is not open!" << std::endl;
        return nullptr;
    }

    m_nZ = z;
    return this;
}

StandardBufferObject * StandardBufferObject::setNormal(const Vector3& v)
{
    setNX(v.x);
    setNY(v.y);
    return setNZ(v.z);
}

StandardBufferObject * StandardBufferObject::setTextureCoord(const Vector2& v)
{
    setU(v.x);
    return setV(v.y);
}

StandardBufferObject * StandardBufferObject::setAttribs(const Vector3& pos, const Vector2& tex, Vector3& norm)
{
    setPosition(pos);
    setTextureCoord(tex);
    return setNormal(norm);
}

StandardBufferObject * StandardBufferObject::pushVertex()
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

void StandardBufferObject::render()
{
    Shader::getDefaultShader()->bind();

    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void StandardBufferObject::start()
{
    m_isOpen = true;
}

void StandardBufferObject::stop()
{
    m_isOpen = false;
}

void StandardBufferObject::compile()
{
    if (m_isOpen)
    {
        std::cout << "Buffer object is open, cannot compile" << std::endl;
        return;
    }

    glGenBuffers(1, &m_vboID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glBufferData(GL_ARRAY_BUFFER, s_vertexSize * m_vertexCount, m_data.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(Shader::Shader_Program::VERTEX_LOCATION,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          s_vertexSize,
                          (GLvoid*) 0);

    glEnableVertexAttribArray(Shader::Shader_Program::VERTEX_LOCATION);
}
