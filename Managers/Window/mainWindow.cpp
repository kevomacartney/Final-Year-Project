//
// Created by Kelvin Macartney on 03/02/2020.
//

#include "mainWindow.h"
#include <iostream>

Managers::Window::MainWindow::MainWindow(int x, int y) {
    this->width = x;
    this->height = y;
}

void Managers::Window::MainWindow::init(const std::string &mesh) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for macos
#endif

    this->window =glfwCreateWindow(this->width, this->height, "MIIND prot-GPU", nullptr, nullptr);

    if (this->window == nullptr) {
        glfwTerminate();

        std::cout << "ERROR::Could not create GLFW window\n";
        return;
    }

    glfwMakeContextCurrent(this->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        std::cout << "ERROR::Could not initialise GLAD \n";
        return;
    }

#if defined(__APPLE__)
    // apple's retina has twice as many pixels
    this->resizeWindow(this->width * 2, this->height * 2);
#endif

    this->initOpenGl();

    //init time
    glfwGetTime();
    std::cout << "Window initialised\n";

    // Initialise useful classes
    this->_basicCamera = std::make_shared<Camera::BasicCamera>(this, 0.001f, 200.f, this->width, this->height);
    this->_renderEngine = std::make_shared<Utilities::Rendering::RenderingEngine>(this->_basicCamera, this->window);
    this->_startUp = std::make_shared<StartUp>(this->_renderEngine);

    this->_renderEngine->init();
    this->_startUp->init(mesh);
}

void Managers::Window::MainWindow::resizeWindow(int x, int y) {
    this->width = x;
    this->height = y;

    // resize the viewport
    glViewport(0, 0, x, y);
    if (this->_basicCamera != nullptr)
        this->_basicCamera->updateViewport(x, y);
}

void Managers::Window::MainWindow::initOpenGl() {
    glViewport(0, 0, this->width, this->height);
}

void Managers::Window::MainWindow::exec() {
    // enter the matrix
    _startUp->startTheMatrix();

    std::cout << "Using: " << glGetString(GL_RENDERER);

    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

    while (!glfwWindowShouldClose(window)) {
        // If someone forgot to unbind their voa
        glBindVertexArray(0);

        glClearColor(1.f, 1.f, 1.f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        this->_renderEngine->tick();

        glfwSwapBuffers(window);
        glfwPollEvents();;
    }

    glfwTerminate();
}
