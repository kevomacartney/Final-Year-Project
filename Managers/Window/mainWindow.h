//
// Created by Kelvin Macartney on 03/02/2020.
//

#ifndef MIIND_MAINWINDOW_H
#define MIIND_MAINWINDOW_H
#include "../../Utilities/Rendering/renderingEngine.h"
#include "../../Camera/basicCamera.h"
#include "../../startUp.h"
#include <GLFW/glfw3.h>
#include <memory.h>

namespace Managers::Window {
    class MainWindow {
    public:
        MainWindow(int x, int y);

        // Initialize the window and OpenGL
        void init(const std::string &mesh);

        // Starts executing the main program
        void exec();

        // Callback method when window is resized
        void resizeWindow(int x, int y);

        GLFWwindow *window{nullptr};

        ~MainWindow() = default;

    protected:
        std::shared_ptr<StartUp> _startUp{nullptr};
        std::shared_ptr<Camera::BasicCamera> _basicCamera{};
        std::shared_ptr<Utilities::Rendering::RenderingEngine> _renderEngine{};
    private:
        int width{1}, height{1};

        // Initialises OpenGl
        void initOpenGl();
    };
}


#endif //MIIND_MAINWINDOW_H
