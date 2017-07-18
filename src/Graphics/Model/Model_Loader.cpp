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
                std::string f0, f1, f2, f3;

                stream >> f0;
                stream >> f1;
                stream >> f2;

                if (spaceCount == 4)
                    stream >> f3;

                unsigned int dashCount = StringUtil::countOccurences(f0, '/');

                if (dashCount == 0) //Vertex indices only
                {
                    unsigned int ind0, ind1, ind2;

                    sscanf(f0.c_str(), "%u", &ind0);
                    sscanf(f1.c_str(), "%u", &ind1);
                    sscanf(f2.c_str(), "%u", &ind2);

                    //bufferObject.pushIndices(ind0 - 1, ind1 - 1, ind2 - 1);

                    ind0--;
                    ind1--;
                    ind2--;

                    Vector3 vert0 = vertices[ind0];
                    Vector3 vert1 = vertices[ind1];
                    Vector3 vert2 = vertices[ind2];

                    bufferObject.setPosition(vert0);
                    bufferObject.pushVertex();

                    bufferObject.setPosition(vert1);
                    bufferObject.pushVertex();

                    bufferObject.setPosition(vert2);
                    bufferObject.pushVertex();
                } else if (dashCount == 1)
                {

                } else if (dashCount == 2)
                {
                    std::vector<std::string> comps0 = StringUtil::splitString(f0, '/');
                    std::vector<std::string> comps1 = StringUtil::splitString(f1, '/');
                    std::vector<std::string> comps2 = StringUtil::splitString(f2, '/');
                    std::vector<std::string> comps3 = StringUtil::splitString(f3, '/');

                    unsigned int len = comps0.size();

                    if (len == 3)
                    {
                        unsigned int posInd0, posInd1, posInd2;

                        sscanf(comps0[0].c_str(), "%u", &posInd0);
                        sscanf(comps1[0].c_str(), "%u", &posInd1);
                        sscanf(comps2[0].c_str(), "%u", &posInd2);

                        posInd0--;
                        posInd1--;
                        posInd2--;

                        Vector3 pos0 = vertices[posInd0];
                        Vector3 pos1 = vertices[posInd1];
                        Vector3 pos2 = vertices[posInd2];

                        unsigned int texInd0, texInd1, texInd2;

                        sscanf(comps0[1].c_str(), "%u", &texInd0);
                        sscanf(comps1[1].c_str(), "%u", &texInd1);
                        sscanf(comps2[1].c_str(), "%u", &texInd2);

                        texInd0--;
                        texInd1--;
                        texInd2--;

                        Vector2 tex0 = textureCoords[texInd0];
                        Vector2 tex1 = textureCoords[texInd1];
                        Vector2 tex2 = textureCoords[texInd2];

                        unsigned int normInd0, normInd1, normInd2;

                        sscanf(comps0[2].c_str(), "%u", &normInd0);
                        sscanf(comps1[2].c_str(), "%u", &normInd1);
                        sscanf(comps2[2].c_str(), "%u", &normInd2);

                        normInd0--;
                        normInd1--;
                        normInd2--;

                        Vector3 norm0 = normals[normInd0];
                        Vector3 norm1 = normals[normInd1];
                        Vector3 norm2 = normals[normInd2];

                        bufferObject.setAttribs(pos0, tex0, norm0)->pushVertex();
                        bufferObject.setAttribs(pos1, tex1, norm1)->pushVertex();
                        bufferObject.setAttribs(pos2, tex2, norm2)->pushVertex();

                        if (spaceCount == 4)
                        {
                            unsigned int posInd3;
                            sscanf(comps3[0].c_str(), "%u", &posInd3);
                            posInd3--;

                            unsigned int texInd3;
                            sscanf(comps3[1].c_str(), "%u", &texInd3);
                            texInd3--;

                            unsigned int normInd3;
                            sscanf(comps3[2].c_str(), "%u", &normInd3);
                            normInd3--;

                            Vector3 pos3 = vertices[posInd3];
                            Vector3 tex3 = vertices[texInd3];
                            Vector3 norm3 = vertices[normInd3];

                            bufferObject.setAttribs(pos2, tex2, norm2)->pushVertex();
                            bufferObject.setAttribs(pos3, tex3, norm3)->pushVertex();
                            bufferObject.setAttribs(pos0, tex0, norm0)->pushVertex();
                        }
                    }
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
