#include "OpenGLHelper.h"

namespace OpenGLHelper
{
    void init(int width, int height)
    {
        glewInit();
        glViewport(0, 0, width, height);
        glClearColor(0.2, 0.2, 0.2, 1.0);
        glEnable(GL_DEPTH_TEST);
    }

    void setWireframeMode(bool b)
    {
        if (b)
        {
            glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
        } else
        {
            glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
        }
    }

    void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
