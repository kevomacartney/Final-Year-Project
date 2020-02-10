//
// Created by Kelvin Macartney on 08/12/2019.
//

#ifndef MIIND_PROTOTYPE_SHADERUTIL_H
#define MIIND_PROTOTYPE_SHADERUTIL_H

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

namespace Utilities::Shaders {
    class ShaderUtil {
    public:
        /**
         *
         * @param vertexShader Vertex shader glsl filename without file extension
         * @param fragmentShader Fragment shader filename without file extension
         */
        ShaderUtil(const std::string &vertexShader, const std::string &fragmentShader);

        ~ShaderUtil();

        void activate();

        /**
         * Will activate this shader device
         */
        void activate(const glm::vec3 *cameraPos);

        /**
         * Will deactivate this shader device
         */
        void deactivate();

        unsigned int getDeviceId() {
            return this->shaderDevice;
        }

        void setDeviceId(unsigned int dID) {
            this->shaderDevice = dID;
        }

        /**
         * Retrieves the uniform id with the given name of the device linked to the shader
         * @return Uniform id
         */
        int getUniformId(const std::string &uniformName);

        /**
         * Sets the value provided to the uniform with the given name
         * @param uniformName The name of the uniform to update
         * @param value The value
         */
        void updateUniformValueMtx4(const std::string &uniformName, glm::mat4 value);

        /**
         * Sets the value provided to the uniform with the given name
         * @param uniformName The name of the uniform to update
         * @param value The value
         */
        void updateUniformValueVec3(const std::string &uniformName, glm::vec3 value);

        /**
         * Sets the value provided to the uniform with the given id
         * @param uniformId Uniform id
         * @param value The value
         */
        static void updateUniformValueVec3(int uniformId, glm::vec3 value);

        /**
         * Sets the value provided to the uniform with the given id
         * @param uniformId Uniform id
         * @param value The value
         */
        static void updateUniformValueMtx4(int uniformId, glm::mat4 value);

        /**
         * Sets the value provided to the uniform with the given name
         * @param uniformName The name of the uniform to update
         * @param value The value
         */
        void updateUniformValueFloat(const std::string &uniformName, float value);

        /**
         * Sets the value provided to the uniform with the given id
         * @param uniformId Uniform id
         * @param value The value
         */
        static void updateUniformValueFloat(int uniformId, float value);

        /**
          * Sets the value provided to the uniform with the given name
          * @param uniformName The name of the uniform to update
          * @param value The value
          */
        void updateUniformValueBool(const std::string &uniformName, bool value);

        /**
         * Sets the value provided to the uniform with the given id
         * @param uniformId Uniform id
         * @param value The value
         */
        static void updateUniformValueBool(int uniformId, bool value);

        /**
         * Compiles shader source files and links to shader devices
         */
        void initShaders();


    protected:
        unsigned int shaderDevice{};

        std::string vertexSrcFile;
        std::string fragmentSrcFile;

    private:
        bool _shadersCompiled{};

        /**
         * Does shader compilation from the specified source and returns the shader id
         * @param vertexShaderSrc The shader source
         * @param shaderType The opengl shader type
         * @return shader id or -1 when failure
         */
        static int compileShader(const std::string &shaderSrc, int shaderType);

        /**
         * Loads the src file from disk
         * @param srcFile The shader source file without extension
         * @return The file content
         */
        static std::string loadSrcFile(const std::string &srcFile);
    };
}

#endif //MIIND_PROTOTYPE_SHADERUTIL_H
