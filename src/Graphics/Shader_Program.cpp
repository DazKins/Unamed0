#include "Shader_Program.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace Shader
{
    Shader_Program::Shader_Program(const std::string& vertexPath, const std::string& fragmentPath)
    {
        std::string vertexCode;
        std::string fragmentCode;

        std::ifstream vertexShaderFile;
        std::ifstream fragmentShaderFile;

        vertexShaderFile.open("res/shaders/" + vertexPath + ".glsl");
        fragmentShaderFile.open("res/shaders/" + fragmentPath + ".glsl");

        std::stringstream vertexShaderStream;
        std::stringstream fragmentShaderStream;

        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexCode = vertexShaderStream.str();
        fragmentCode = fragmentShaderStream.str();

        const char* vertexShaderCode = vertexCode.c_str();
        const char* fragmentShaderCode = fragmentCode.c_str();

        GLint status;
        GLchar infoLog[512];

        GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexID, 1, &vertexShaderCode, nullptr);
        glCompileShader(vertexID);

        glGetShaderiv(vertexID, GL_COMPILE_STATUS, &status);
        if (status == 0)
        {
            glGetShaderInfoLog(vertexID, 512, nullptr, infoLog);
            std::cout << "Error compiling vertex shader: " << std::endl << infoLog << std::endl;
        }

        GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentID, 1, &fragmentShaderCode, nullptr);
        glCompileShader(fragmentID);

        glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &status);
        if (status == 0 )
        {
            glGetShaderInfoLog(fragmentID, 512, nullptr, infoLog);
            std::cout << "Error compiling fragment shader: " << std::endl << infoLog << std::endl;
        }

        m_programID = glCreateProgram();
        glAttachShader(m_programID, vertexID);
        glAttachShader(m_programID, fragmentID);
        glLinkProgram(m_programID);

        glGetProgramiv(m_programID, GL_LINK_STATUS, &status);
        if (status == 0)
        {
            glGetProgramInfoLog(m_programID, 512, nullptr, infoLog);
            std::cout << "Error linking program: " << std::endl << infoLog << std::endl;
        }

        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
    }

    GLuint Shader_Program::getAttributeLocation(const std::string& attribute)
    {
        return glGetAttribLocation(m_programID, attribute.c_str());
    }

    void Shader_Program::bind()
    {
        glUseProgram(m_programID);
    }

    void Shader_Program::unbind()
    {
        glUseProgram(0);
    }

    int Shader_Program::getUniformLocation (const std::string& name)
    {
        return glGetUniformLocation(m_programID, name.c_str());
    }

    void Shader_Program::setUniformFloat (const std::string& name, GLfloat val)
    {
        int loc = getUniformLocation(name);
        bind();
        glUniform1f(loc, val);
    }

    void Shader_Program::setUniformMatrix4 (const std::string& name, Matrix4 val)
    {
        int loc = getUniformLocation(name);
        bind();
        glUniformMatrix4fv(loc, 1, false, glm::value_ptr(val));
    }

    Shader_Program * getDefaultShader()
    {
        static Shader_Program ret ("vertex", "fragment");
        return &ret;
    }
}
