#ifndef MODEL_LOADER_H_INCLUDED
#define MODEL_LOADER_H_INCLUDED

#include "Model.h"
#include "../../Util/StringUtil.h"
#include "../../Maths/GLM.h"
#include "../Shader_Program.h"
#include "../Buffer_Object/Standard_Buffer_Object.h"

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

namespace Model
{
    Model loadOBJ(const std::string& path);
}

#endif // MODEL_LOADER_H_INCLUDED
