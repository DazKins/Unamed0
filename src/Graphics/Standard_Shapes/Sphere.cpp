#include "Sphere.h"

BufferObject Standard_Shapes::sphere (float radius)
{
    BufferObject ret;

    ret.start();

    int verticalSubdivides = 16;
    int horizontalSubdivides = 16;

    //Top point
    ret.setX(0.0)->setY(radius)->setZ(0.0);
    ret.pushVertex();

    //Bottom point
    ret.setX(0.0)->setY(-radius)->setZ(0.0);
    ret.pushVertex();

    for (int i = 1; i < verticalSubdivides; i++)
    {
        float phi = ((float) i / verticalSubdivides) * toRadians(180.0);

        for (int j = 0; j < horizontalSubdivides; j++)
        {
            float theta = ((float) j / horizontalSubdivides) * toRadians(360.0);

            float x = radius * cos(theta) * sin(phi);
            float y = radius * cos(phi);
            float z = radius * sin(theta) * sin(phi);

            ret.setX(x)->setY(y)->setZ(z);
            ret.pushVertex();
        }
    }


    for (int j = 0; j < horizontalSubdivides; j++)
    {
        int belowX = j;
        int belowY = 0;
        int belowInd = belowX + belowY * horizontalSubdivides + 2;

        int belowNextX = betterMod(j + 1, horizontalSubdivides);
        int belowNextY = belowY;
        int belowNextInd = belowNextX + belowNextY * horizontalSubdivides + 2;

        ret.pushIndex(0)->pushIndex(belowNextInd)->pushIndex(belowInd);

        int aboveX = j;
        int aboveY = verticalSubdivides - 2;
        int aboveInd = aboveX + aboveY * horizontalSubdivides + 2;

        int aboveNextX = betterMod(j + 1, horizontalSubdivides);
        int aboveNextY = aboveY;
        int aboveNextInd = aboveNextX + aboveNextY * horizontalSubdivides + 2;

        ret.pushIndex(aboveInd)->pushIndex(aboveNextInd)->pushIndex(1);
    }

    for (int i = 0; i < verticalSubdivides - 2; i++)
    {
        for (int j = 0; j < horizontalSubdivides; j++)
        {
            int thisX = j;
            int thisY = i;
            int thisInd = thisX + thisY * horizontalSubdivides + 2;

            int prevX = betterMod((thisX - 1), horizontalSubdivides);
            int prevY = thisY;
            int prevInd = prevX + prevY * horizontalSubdivides + 2;

            int belowX = thisX;
            int belowY = thisY + 1;
            int belowInd = belowX + belowY * horizontalSubdivides + 2;

            int belowNextX = betterMod((belowX + 1), horizontalSubdivides);;
            int belowNextY = belowY;
            int belowNextInd = belowNextX + belowNextY * horizontalSubdivides + 2;

            ret.pushIndex(thisInd)->pushIndex(belowInd)->pushIndex(prevInd);
            ret.pushIndex(thisInd)->pushIndex(belowNextInd)->pushIndex(belowInd);
        }
    }

    ret.stop();

    ret.compile();

    return ret;
}
