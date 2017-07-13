#include "GLM.h"

float toRadians(float a)
{
    return glm::radians(a);
}

int betterMod (int d, int m)
{
    int r = d % m;

    if (r < 0)
        r = m + r;

    return r;
}
