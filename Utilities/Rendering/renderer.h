//
// Created by Kelvin Macartney on 22/12/2019.
//

#ifndef MIIND_PROTOTYPE_BASERENDERER_H
#define MIIND_PROTOTYPE_BASERENDERER_H
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include <GLFW/glfw3.h>

class BaseRenderer{
public:
    virtual void render(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPos) = 0;
};

#endif //MIIND_PROTOTYPE_BASERENDERER_H
