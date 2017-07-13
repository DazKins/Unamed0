#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "../Game_Object.h"
#include "../Maths/GLM.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

class Camera : public Game_Object
{
public:
    Camera(float fov, float aspectRatio, float zNear, float zFar);

    Matrix4 getProjectionMatrix();
    Matrix4 getViewMatrix();

    void tick(float dt);

private:
    float m_fov;
    float m_aspectRatio;
    float m_zNear;
    float m_zFar;
//  float m_zWhereverYouAre

    Matrix4 projectionMatrix;
};

#endif // CAMERA_H_INCLUDED
