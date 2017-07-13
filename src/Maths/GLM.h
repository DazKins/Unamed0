#ifndef GLM_H_INCLUDED
#define GLM_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

typedef glm::mat4 Matrix4;
typedef glm::mat3 Matrix3;
typedef glm::mat2 Matrix2;

typedef glm::vec4 Vector4;
typedef glm::vec3 Vector3;
typedef glm::vec2 Vector2;

float toRadians (float a);

int betterMod (int d, int m);

#endif // GLM_H_INCLUDED
