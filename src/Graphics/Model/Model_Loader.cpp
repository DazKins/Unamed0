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

        StandardBufferObject bufferObject;

        bufferObject.start();

        std::vector<Vector3> vertices;
        std::vector<Vector2> textureCoords;
        std::vector<Vector3> normals;

        while (std::getline(file, curLine))
        {
            std::stringstream stream (curLine);

            unsigned int spaceCount = StringUtil::countOccurences(curLine, ' ');

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

                vertices.push_back(Vector3 (x, y, z));
            }
            else if (indicator == "vn") //Vertex normal
            {
                float xn, yn, zn;

                stream >> xn;
                stream >> yn;
                stream >> zn;

                normals.push_back(Vector3 (xn, yn, zn));
            }
            else if (indicator == "vt") //Vertex texture coordinates
            {
                float xt, yt, zt;

                stream >> xt;
                stream >> yt;
                stream >> zt;

                textureCoords.push_back(Vector3 (xt, yt, zt));
            }
            else if (indicator == "f") //Face indices
            {
                for (unsigned int i = 0; i < spaceCount; i++)
                {
                    unsigned int posInd = -1;
                    unsigned int texInd = -1;
                    unsigned int normInd = -1;

                    std::string token;

                    stream >> token;

                    unsigned int dashCount = StringUtil::countOccurences(token, '/');

                    if (dashCount == 0)
                    {
                        sscanf(token.c_str(), "%u", &posInd);
                    } else if (dashCount == 1)
                    {

                    } else if (dashCount == 2)
                    {
                        sscanf(token.c_str(), "%u/%u/%u", &posInd, &texInd, &normInd);
                    }

                    if (posInd != -1)
                    {
                        posInd--;
                        Vector3 vert = vertices[posInd];
                        bufferObject.setPosition(vert);
                    }
                    if (texInd != -1)
                    {
                        texInd--;
                        Vector2 texCoord = textureCoords[texInd];
                        bufferObject.setTextureCoord(texCoord);
                    }
                    if (normInd != -1)
                    {
                        normInd--;
                        Vector3 normal = normals[normInd];
                        bufferObject.setNormal(normal);
                    }

                    bufferObject.pushVertex();
                }
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
