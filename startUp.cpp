//
// Created by Kelvin Macartney on 03/02/2020.
//

#include "startUp.h"
#include "Utilities/Rendering/renderModel.h"
#include <utility>
#include <vector>

StartUp::StartUp(std::shared_ptr<Utilities::Rendering::RenderingEngine> renderEngine) {
    this->_renderEngine = std::move(renderEngine);

    this->_meshRender = std::make_unique<Utilities::Rendering::MeshRenderer>();
    this->_meshManager = std::make_unique<Managers::Meshes::MeshManager>();
    this->_voaHandler = std::make_unique<Utilities::GlObjs::VoaHandler>();
    this->_shaderUtil = std::make_shared<Utilities::Shaders::ShaderUtil>("vertexShader", "fragmentShader");
}


void StartUp::init(const std::string& mesh) {
    this->_meshManager->loadMesh(mesh); // Loads the mesh from file
    this->_shaderUtil->initShaders(); // Initialise shaders
    this->_renderEngine->registerRenderer(this->_meshRender);

    this->_initialised = true;
}

void StartUp::startTheMatrix() {
    if (!this->_initialised)
        return;

    auto vertices = this->_meshManager->getMesh(); // Retrieve the mesh as an array of vertices

    Vertex v(glm::vec3(-0.5, -0.5, 0.0));
    Vertex v2(glm::vec3(0.5, -0.5, 0.0));
    Vertex v3(glm::vec3(0.0, 0.5, 0.0));

    std::vector<Vertex> vs;
    vs.push_back(v);
    vs.push_back(v2);
    vs.push_back(v3);

    // Load the meshes into GPU
    this->_shaderUtil->activate();
    auto voaModel = this->_voaHandler->loadData(std::vector<int>(), vertices);
    this->_shaderUtil->deactivate();

    this->_meshRender->registerMesh(std::make_shared<Utilities::Rendering::RenderModel>(this->_shaderUtil, voaModel));
}
