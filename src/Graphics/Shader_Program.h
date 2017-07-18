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
        const static int VERTEX_LOCATION = 0;
        const static int TEXTURE_COORDINATE_LOCATION = 1;
        const static int NORMAL_LOCATION = 2;

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

        static unsigned int s_curBoundShader;
    };

    Shader_Program * getDefaultShader();
}

extern Shader::Shader_Program def;

#endif // SHADER_PROGRAM_H_INCLUDED
