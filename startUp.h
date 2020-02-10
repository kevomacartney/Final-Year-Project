//
// Created by Kelvin Macartney on 03/02/2020.
//

#ifndef MIIND_STARTUP_H
#define MIIND_STARTUP_H
#include <memory>
#include "Managers/Mesh/meshManager.h"
#include "Utilities/GlObjs/voaHandler.h"
#include "Utilities/Shaders/shaderUtil.h"
#include "Utilities/Rendering/renderingEngine.h"
#include "Utilities/Rendering/meshRenderer.h"
#include <glad/glad.h>

class StartUp {
public:
    explicit StartUp(std::shared_ptr<Utilities::Rendering::RenderingEngine> renderEngine);
    void init(const std::string& mesh);

    void startTheMatrix();
private:
    std::unique_ptr<Managers::Meshes::MeshManager> _meshManager;
    std::unique_ptr<Utilities::GlObjs::VoaHandler> _voaHandler;
    std::shared_ptr<Utilities::Shaders::ShaderUtil> _shaderUtil;

    std::shared_ptr<Utilities::Rendering::MeshRenderer> _meshRender;
    std::shared_ptr<Utilities::Rendering::RenderingEngine> _renderEngine;
    bool _initialised{false};
};


#endif //MIIND_STARTUP_H
