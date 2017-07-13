#ifndef OPENGLHELPER_H_INCLUDED
#define OPENGLHELPER_H_INCLUDED

#include <GL/glew.h>

namespace OpenGLHelper
{
    void init(int width, int height);
    void setWireframeMode(bool b);
    void clear();
}

#endif // OPENGLHELPER_H_INCLUDED
