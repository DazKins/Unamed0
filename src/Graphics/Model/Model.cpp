#include "Model.h"

namespace Model
{
    Model::Model(BufferObject bufferObject)
    :   m_bufferObject (bufferObject)
    {
    }

    void Model::render()
    {
        m_bufferObject.render();
    }
}
