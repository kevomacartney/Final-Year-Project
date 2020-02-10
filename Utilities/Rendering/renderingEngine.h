//
// Created by Kelvin Macartney on 18/12/2019.
//

#ifndef MIIND_PROTOTYPE_RENDERINGENGINE_H
#define MIIND_PROTOTYPE_RENDERINGENGINE_H
#include "renderer.h"
#include "../Camera/basicCamera.h"
#include <memory>
#include <vector>


namespace Utilities::Rendering {
    class RenderingEngine {
    public:
        RenderingEngine(std::shared_ptr<Camera::BasicCamera> camera , GLFWwindow *window);

        ~RenderingEngine() = default;

        // Renders all objects in the scene
        void tick();

        // Initialises the render engine
        void init();

        // Update viewport dimensions
        void updateViewport(int w, int h);

        // Registers a renderer to be rendered
        void registerRenderer(std::shared_ptr<BaseRenderer> renderer);

    protected:
        std::shared_ptr<Camera::BasicCamera> _camera{};

        std::vector<std::shared_ptr<BaseRenderer>> renders{};
        long long ticks{0};

    private:
        GLFWwindow *_window;
    };
}

#endif //MIIND_PROTOTYPE_RENDERINGENGINE_H
