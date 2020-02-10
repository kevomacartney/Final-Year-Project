//
// Created by Kelvin Macartney on 18/12/2019.
//

#include <glm/gtc/matrix_transform.hpp>
#include "../Managers/Window/mainWindow.h"
#include "basicCamera.h"

Camera::BasicCamera::BasicCamera( Managers::Window::MainWindow *window, float closePlane, float farPlane,  int width, int height):
        position(glm::vec3(0.f, 0.f, 200.f)),
        target(glm::vec3(0.0f, 0.0f, 0.0f)),
        up(glm::vec3(0.0f, 1.0f, 0.0f))
{
    this->_height = height;
    this->_width = width;

    this->_closePlane = closePlane;
    this->_farPlane = farPlane;

    this->projectionMatrix = glm::mat4(1.f);
}

void Camera::BasicCamera::updateViewport(int w, int h) {
    this->_width = w;
    this->_height = h;
}

void Camera::BasicCamera::calculateMatrices() {
    //this->target = glm::normalize(this->target);

    // Configure the look at matrix
    this->viewMatrix = glm::lookAt(this->position,
                                   this->target,
                                   this->up); // Creates the look at matrix

    float fov = 45.0f;
    // Configure the projection matrix
    this->projectionMatrix = glm::perspective(glm::radians(fov),
            this->getAspectRatio(),
            this->_closePlane,
            this->_farPlane);
}
