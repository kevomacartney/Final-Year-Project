//
// Created by Kelvin Macartney on 09/02/2020.
//

#include "meshRenderer.h"
#include <utility>

void Utilities::Rendering::MeshRenderer::render(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPos) {
    this->_renderModel->ShaderUtil->activate();
    glBindVertexArray(this->_renderModel->VoaModel->getId());

    if (this->_renderModel->VoaModel->isIndex())
        glDrawElements(GL_TRIANGLES, this->_renderModel->VoaModel->getVertexCount(), GL_UNSIGNED_INT, 0);
    else
        glDrawArrays(GL_LINE_STRIP, 0, this->_renderModel->VoaModel->getVertexCount());

    this->copyMatrices(viewMatrix, projectionMatrix);

    this->_renderModel->ShaderUtil->deactivate();
    glBindVertexArray(0);
}

void Utilities::Rendering::MeshRenderer::registerMesh(std::shared_ptr<Utilities::Rendering::RenderModel> renderModel) {
    this->_renderModel = std::move(renderModel);
}

void Utilities::Rendering::MeshRenderer::copyMatrices(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) {
    this->_renderModel->ShaderUtil->updateUniformValueMtx4("view", viewMatrix);
    this->_renderModel->ShaderUtil->updateUniformValueMtx4("projection", projectionMatrix);
    glm::mat4 m(1.f);
    m = glm::translate(m, glm::vec3(0, -20, 0));
    m = glm::scale(m, glm::vec3(0.18f));
    this->_renderModel->ShaderUtil->updateUniformValueMtx4("model", m);
}
