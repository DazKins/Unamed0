#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <memory>
#include "../Buffer_Object/Standard_Buffer_Object.h"

namespace Model
{
    class Model
    {
    public:
        Model(StandardBufferObject bufferObject);

        void render();

    private:
        StandardBufferObject m_bufferObject;
    };
}

#endif // MODEL_H_INCLUDED
