#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "Graphics/Buffer_Object/Standard_Buffer_Object.h"
#include "Graphics/Buffer_Object/Index_Buffer_Object.h"
#include "Graphics/Shader_Program.h"
#include "Graphics/Camera.h"
#include "Graphics/Standard_Shapes/Sphere.h"
#include "Display.h"
#include "Maths/GLM.h"
#include "Graphics/Model/Model.h"
#include "Graphics/Model/Model_Loader.h"

#include <memory>

class Application
{
public:
    Application();

    void tick(float dt);
    void render();

private:
    Model::Model m_testModel;
    IndexBufferObject m_testBO;
    std::unique_ptr<Camera> m_camera;
};

#endif // APPLICATION_H_INCLUDED
