#include "Model_Loader.h"

#include <iostream>

namespace Model
{
    Model loadOBJ(const std::string& path)
    {
        std::ifstream file ("res/models/" + path + ".obj");

        if (!file.is_open())
        {
            std::cout << "Error loading model: " << path << std::endl;
        }

        std::string curLine;

        BufferObject bufferObject;

        bufferObject.start();

        while (std::getline(file, curLine))
        {
            const char * lineChars = curLine.c_str();

            char firstChar = lineChars[0];

            if (firstChar == 'v')
            {
                char bogus;
                float x, y, z;
                std::sscanf(lineChars, "%c %f %f %f", &bogus, &x, &y, &z);
                bufferObject.setX(x)->setY(y)->setZ(z);
                bufferObject.pushVertex();
            } else if (firstChar == 'f')
            {
                char bogus;
                unsigned int v0, v1, v2;
                std::sscanf(lineChars, "%c %u %u %u", &bogus, &v0, &v1, &v2);
                bufferObject.pushIndex(v0 - 1)->pushIndex(v1 - 1)->pushIndex(v2 - 1);
            }
        }

        bufferObject.stop();

        bufferObject.compile();

        return Model(&bufferObject);
    }
}
