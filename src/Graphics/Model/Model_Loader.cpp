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
            std::stringstream stream (curLine);

            std::string indicator = "#";

            stream >> indicator;

            if (indicator == "#") //Comment
            {
                continue;
            }
            else if (indicator == "mtllib") //Location of .mtl material library
            {

            }
            else if (indicator == "usemtl") //Set current active material
            {

            }
            else if (indicator == "o") //Define new object mesh
            {

            }
            else if (indicator == "v") //Vertex coordinates
            {
                float x, y, z;

                stream >> x;
                stream >> y;
                stream >> z;

                bufferObject.setX(x)->setY(y)->setZ(z);
                bufferObject.pushVertex();
            }
            else if (indicator == "vn") //Vertex normal
            {

            }
            else if (indicator == "vt") //Vertex texture coordinates
            {

            }
            else if (indicator == "f") //Face indices
            {
                unsigned int ind0, ind1, ind2;

                stream >> ind0;
                stream >> ind1;
                stream >> ind2;

                bufferObject.pushIndex(ind0 - 1)->pushIndex(ind1 - 1)->pushIndex(ind2 - 1);
            }
            else if (indicator == "s") //Smooth shading toggle
            {

            }

            stream.clear();
        }

        bufferObject.stop();

        bufferObject.compile();

        return Model(bufferObject);
    }
}
