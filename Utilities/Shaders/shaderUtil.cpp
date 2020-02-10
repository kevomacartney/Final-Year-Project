//
// Created by Kelvin Macartney on 08/12/2019.
//

#include "shaderUtil.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <utility>

Utilities::Shaders::ShaderUtil::ShaderUtil(const std::string &vertexShader, const std::string &fragmentShader)
    : _shadersCompiled(false),
    shaderDevice(0)
{
    this->vertexSrcFile = vertexShader;
    this->fragmentSrcFile = fragmentShader;
}

/**
 * Free the shader buffers with the given identifier
 * @param vertexShader The vertex shader id
 * @param fragmentShader The fragment shader id
 */
void freeShaders(int vertexShader, int fragmentShader){
    // Clear resources
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Utilities::Shaders::ShaderUtil::initShaders() {
    // Load source files from disk
    std::string vertexShaderSrc = loadSrcFile(this->vertexSrcFile);
    std::string fragmentShaderSrc = loadSrcFile(this->fragmentSrcFile);

    if(vertexShaderSrc.empty())
    {
        std::cout << "ERROR::SHADER::VERTEXSHADER\nCould not load vertices shader.. aborting " << this->vertexSrcFile << "\n";
        return;
    }

    if(fragmentShaderSrc.empty())
    {
        std::cout << "ERROR::SHADER::FRAGMENTSHADER\nCould not load vertices shader... aborting" << this->vertexSrcFile << "\n";
        return;
    }

    // Compile the shaders
    int vertexShader = compileShader(vertexShaderSrc, GL_VERTEX_SHADER);
    int fragmentShader = compileShader(fragmentShaderSrc, GL_FRAGMENT_SHADER);

    this->shaderDevice = glCreateProgram();

    // Link the shaders to the device
    glAttachShader(this->shaderDevice, vertexShader);
    glAttachShader(this->shaderDevice, fragmentShader);
    glLinkProgram(this->shaderDevice);

    int success;
    char glInfoLog[1024];

    glGetProgramiv(this->shaderDevice, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(this->shaderDevice, 1024, nullptr, glInfoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << glInfoLog << std::endl;

        // Free the resources
        glDeleteProgram(this->shaderDevice);
        freeShaders(vertexShader, fragmentShader);

        this->shaderDevice = 0;

        return;
    }

    this->_shadersCompiled = true;

    // Free resources
    freeShaders(vertexShader, fragmentShader);
}

void Utilities::Shaders::ShaderUtil::activate() {
    this->activate(nullptr);
}

void Utilities::Shaders::ShaderUtil::activate(const glm::vec3 *cameraPos)
{
    if (!this->_shadersCompiled)
        this->initShaders(); // Compile and link devices

    if (this->shaderDevice < 0)
        return;

    glUseProgram(this->shaderDevice);
}

void Utilities::Shaders::ShaderUtil::deactivate() {
    glDeleteProgram(-1);
}

std::string Utilities::Shaders::ShaderUtil::loadSrcFile(const std::string& srcFile) {
    std::ifstream shaderFile;
    shaderFile.open("Data/Shaders/" + srcFile + ".glsl");

    if (!shaderFile.is_open()) {
        std::cout << "Could not open shader file" << srcFile << "\n";
        return std::string("");
    }

    std::string line;
    std::stringstream ss;

    // Read all the line
    while (getline(shaderFile, line))
        ss << line << '\n';

    shaderFile.close();
    return ss.str();
}

int Utilities::Shaders::ShaderUtil::compileShader(const std::string& shaderSrc, int shaderType) {
    const char *src = shaderSrc.c_str();
    // Create shader buffer
    int shaderId = glCreateShader(shaderType);

    // Compile the shader source
    glShaderSource(shaderId, 1, &src, nullptr);
    glCompileShader(shaderId);


    int success;
    char glInfoLog[1024];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shaderId, 1024, nullptr, glInfoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << glInfoLog << std::endl;

        // return -1 to indicate error
        return 0;
    }

    return shaderId;
}

Utilities::Shaders::ShaderUtil::~ShaderUtil() {
    if (this->shaderDevice > 0)

        // Delete the link program
        glDeleteProgram(this->shaderDevice);
}

int Utilities::Shaders::ShaderUtil::getUniformId(const std::string& uniformName) {
    auto c = glGetUniformLocation(this->shaderDevice, uniformName.c_str());
    return c;
}

void Utilities::Shaders::ShaderUtil::updateUniformValueMtx4(const std::string& uniformName, glm::mat4 value) {
    int uniformId = getUniformId(uniformName);
    Utilities::Shaders::ShaderUtil::updateUniformValueMtx4(uniformId, value);
}

void Utilities::Shaders::ShaderUtil::updateUniformValueMtx4(int uniformId, glm::mat4 value) {
    glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(value));
}

void Utilities::Shaders::ShaderUtil::updateUniformValueVec3(const std::string &uniformName, glm::vec3 value) {
    int uniformId = getUniformId(uniformName);
    updateUniformValueVec3(uniformId, value);
}

void Utilities::Shaders::ShaderUtil::updateUniformValueVec3(int uniformId, glm::vec3 value) {
    glUniform3f(uniformId, value.x, value.y, value.z);
}

void Utilities::Shaders::ShaderUtil::updateUniformValueFloat(const std::string& uniformName, float value) {
    int uniformId = getUniformId(uniformName);
    updateUniformValueFloat(uniformId, value);
}

void Utilities::Shaders::ShaderUtil::updateUniformValueFloat(int uniformId, float value) {
    glUniform1f(uniformId, value);
}

void Utilities::Shaders::ShaderUtil::updateUniformValueBool(const std::string &uniformName, bool value) {
    int uniformId = getUniformId(uniformName);
    updateUniformValueBool(uniformId, value);

}

void Utilities::Shaders::ShaderUtil::updateUniformValueBool(int uniformId, bool value) {
    glUniform1i(uniformId, value);
}