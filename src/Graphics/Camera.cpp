#include "Camera.h"

#include <iostream>

const float MAX_X_ROT = toRadians(90.0);

Camera::Camera(float fov, float aspectRatio, float zNear, float zFar)
:   m_fov (fov)
,   m_aspectRatio (aspectRatio)
,   m_zNear (zNear)
,   m_zFar (zFar)
{
    projectionMatrix = glm::perspective(m_fov, m_aspectRatio, m_zNear, m_zFar);
}

Matrix4 Camera::getProjectionMatrix()
{
    return projectionMatrix;
}

Matrix4 Camera::getViewMatrix()
{
    Matrix4 id;

    id = glm::rotate(id, -getRotation()->x, Vector3 (1.0, 0.0, 0.0));
    id = glm::rotate(id, -getRotation()->y, Vector3 (0.0, 1.0, 0.0));
    id = glm::rotate(id, -getRotation()->z, Vector3 (0.0, 0.0, 1.0));

    id = glm::translate(id, -(*getPosition()));

    return id;
}

sf::Vector2i oldMouseGlobalPos;

void Camera::tick(float dt)
{
    float speed = dt;

    Vector3 * pos = getPosition();
    Vector3 * rot = getRotation();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //pos->z += (-cos(rot->y) * cos(rot->x)) * speed;
        //pos->x += (-sin(rot->y) * cos(rot->x)) * speed;
        //pos->y += sin(rot->x) * speed;
        pos->z += -cos(rot->y) * speed;
        pos->x += -sin(rot->y) * speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        pos->z += sin(rot->y) * speed;
        pos->x += -cos(rot->y) * speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //pos->z += (cos(rot->y) * cos(rot->x)) * speed;
        //pos->x += (sin(rot->y) * cos(rot->x)) * speed;
        //pos->y += -sin(rot->x) * speed;
        pos->z += cos(rot->y) * speed;
        pos->x += sin(rot->y) * speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        pos->z += -sin(rot->y) * speed;
        pos->x += cos(rot->y) * speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        pos->y += dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        pos->y -= dt;
    }

    float rotSpeed = 0.001;

    sf::Vector2i curMouseGlobalPos = sf::Mouse::getPosition();

    sf::Vector2i dif = curMouseGlobalPos - oldMouseGlobalPos;

    rot->y -= dif.x * rotSpeed;
    rot->x -= dif.y * rotSpeed;

    if (rot->x > MAX_X_ROT)
        rot->x = MAX_X_ROT;

    if (rot->x < -MAX_X_ROT)
        rot->x = -MAX_X_ROT;

    sf::Mouse::setPosition({800, 800});

    oldMouseGlobalPos = sf::Mouse::getPosition();
}
