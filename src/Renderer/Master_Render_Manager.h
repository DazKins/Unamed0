#ifndef MASTER_RENDER_MANAGER_H_INCLUDED
#define MASTER_RENDER_MANAGER_H_INCLUDED

#include "Simple_Renderer.h"

namespace Renderer
{
    class MasterRenderer
    {
    public:
        MasterRenderer();

    private:
        Simple_Renderer m_simpleRenderer;
    };

}

#endif // MASTER_RENDER_MANAGER_H_INCLUDED
