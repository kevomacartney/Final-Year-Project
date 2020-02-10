#include <iostream>
#include "Managers/Window/mainWindow.h"

Managers::Window::MainWindow *mainWindow = new Managers::Window::MainWindow(1600, 1200);

void onWindowResize(GLFWwindow *window, int w, int h){
    mainWindow->resizeWindow(w, h);
}

int main() {
    std::cout << "Kelvin Macartney: MIIND GPU Implementation!" << std::endl;

    mainWindow->init("Data/Meshes/MeshData.mesh");

    // subscribe to resize event
    glfwSetFramebufferSizeCallback(mainWindow->window, onWindowResize);

    mainWindow->exec();

    delete mainWindow;
    mainWindow = nullptr;
    return 0;
}
