#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include <cmath>
#include <GL/glew.h>

#include "../Buffer_Object/Index_Buffer_Object.h"
#include "../../Maths/GLM.h"

namespace Standard_Shapes
{
    IndexBufferObject sphere (float radius);
}

#endif // SPHERE_H_INCLUDED
