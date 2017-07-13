#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include "Maths/GLM.h"

class Game_Object
{
public:
    Game_Object();
    Game_Object(const Vector3& position);
    Game_Object(const Vector3& position, const Vector3& rotation);

    Vector3 * getPosition();
    Vector3 * getRotation();

private:
    Vector3 m_position;
    Vector3 m_rotation;
};

#endif // GAME_OBJECT_H_INCLUDED
