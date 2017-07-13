#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <memory>
#include "../Buffer_Object.h"

namespace Model
{
    class Model
    {
    public:
        Model(BufferObject * bufferObject);

        void render();

    private:
        BufferObject * m_bufferObject;
    };
}

#endif // MODEL_H_INCLUDED
