//
// Created by Kelvin Macartney on 09/02/2020.
//

#ifndef MIIND_MESHRENDERER_H
#define MIIND_MESHRENDERER_H
#include <memory>
#include "renderer.h"
#include "renderModel.h"

namespace Utilities::Rendering {
    class MeshRenderer : public BaseRenderer {
    public:
        MeshRenderer() = default;
        ~MeshRenderer() = default;
        void render(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPos) override;

        void registerMesh(std::shared_ptr<Utilities::Rendering::RenderModel> renderModel);
    private:
        std::shared_ptr<Utilities::Rendering::RenderModel> _renderModel{nullptr};

        void copyMatrices(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
    };
}


#endif //MIIND_MESHRENDERER_H
