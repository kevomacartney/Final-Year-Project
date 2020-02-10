//
// Created by Kelvin Macartney on 18/12/2019.
//

#include "renderingEngine.h"

#include <utility>
#include "iostream"
Utilities::Rendering::RenderingEngine::RenderingEngine(std::shared_ptr<Camera::BasicCamera> camera, GLFWwindow *window)
{
    this->_camera = std::move(camera);
    this->_window = window;
}

void Utilities::Rendering::RenderingEngine::tick() {
    ++this->ticks; // Increment the ticks

    // Update the view matrices
    _camera->calculateMatrices();

//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Invoke all the renderers
    for(const auto& r : this->renders){
        r->render(this->_camera->getViewMatrix(), this->_camera->getProjectionMatrix(), _camera->getPosition());
    }
}

void Utilities::Rendering::RenderingEngine::init() {
    this->_camera->calculateMatrices();
}

void Utilities::Rendering::RenderingEngine::updateViewport(int w, int h) {
    this->_camera->updateViewport(w, h);
}

void Utilities::Rendering::RenderingEngine::registerRenderer(std::shared_ptr<BaseRenderer> r) {
    // add the renderer
    this->renders.push_back(r);
}
