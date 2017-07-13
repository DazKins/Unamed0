#ifndef SHADER_PROGRAM_H_INCLUDED
#define SHADER_PROGRAM_H_INCLUDED

#include <GL/glew.h>
#include <string>

#include "../Maths/GLM.h"

namespace Shader
{
    class Shader_Program
    {
    public:
        Shader_Program (const std::string& vertexPath, const std::string& fragmentPath);

        GLuint getAttributeLocation (const std::string& attribute);

        void setUniformFloat (const std::string& name, GLfloat val);
        void setUniformMatrix4 (const std::string& name, Matrix4 val);

        void bind ();
        void unbind ();

    protected:
        int getUniformLocation (const std::string& name);

    private:
        GLuint m_programID;
    };

    Shader_Program * getDefaultShader();
}

#endif // SHADER_PROGRAM_H_INCLUDED
