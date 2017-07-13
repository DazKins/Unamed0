#include "Application.h"

Application::Application()
:   m_testModel (Model::loadOBJ("bunny"))
{
    m_camera = std::make_unique<Camera> (toRadians(90.0), (float) Display::getWidth() / Display::getHeight(), 0.001, 10000.0);
}

void Application::tick(float dt)
{
    m_camera->tick(dt);
}

void Application::render()
{
    Matrix4 projMat = m_camera->getProjectionMatrix();
    Matrix4 viewMat = m_camera->getViewMatrix();

    Shader::getDefaultShader()->setUniformMatrix4("matrix", projMat * viewMat);

    Shader::getDefaultShader()->bind();

    m_testModel.render();
}
