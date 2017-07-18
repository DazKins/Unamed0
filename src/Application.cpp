#include "Application.h"

Application::Application()
:   m_testModel (Model::loadOBJ("wolf"))
{
    m_camera = std::make_unique<Camera> (toRadians(90.0), (float) Display::getWidth() / Display::getHeight(), 0.001, 10000.0);

    m_testBO.start();

    m_testBO.setX(-0.5)->setY(-0.5)->setZ(-1.0)->pushVertex();
    m_testBO.setX(0.5)->setY(-0.5)->setZ(-1.0)->pushVertex();
    m_testBO.setX(0.5)->setY(0.5)->setZ(-1.0)->pushVertex();
    m_testBO.setX(-0.5)->setY(0.5)->setZ(-1.0)->pushVertex();

    m_testBO.pushIndex(0)->pushIndex(1)->pushIndex(2);
    m_testBO.pushIndex(2)->pushIndex(3)->pushIndex(0);

    m_testBO.stop();

    m_testBO.compile();
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

    m_testBO.render();

    m_testModel.render();
}
