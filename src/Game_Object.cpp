#include "Game_Object.h"

Game_Object::Game_Object() { }

Game_Object::Game_Object(const Vector3& position)
:   m_position (position)
{ }

Game_Object::Game_Object(const Vector3& position, const Vector3& rotation)
:   m_position (position)
,   m_rotation (rotation)
{ }

Vector3* Game_Object::getPosition()
{
    return &m_position;
}

Vector3* Game_Object::getRotation()
{
    return &m_rotation;
}
