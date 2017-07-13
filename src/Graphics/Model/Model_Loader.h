#ifndef MODEL_LOADER_H_INCLUDED
#define MODEL_LOADER_H_INCLUDED

#include "Model.h"

#include <string>
#include <fstream>

namespace Model
{
    Model loadOBJ(const std::string& path);
}

#endif // MODEL_LOADER_H_INCLUDED
