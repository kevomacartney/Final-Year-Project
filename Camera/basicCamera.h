//
// Created by Kelvin Macartney on 18/12/2019.
//

#ifndef MIIND_PROTOTYPE_BASICCAMERA_H
#define MIIND_PROTOTYPE_BASICCAMERA_H

#include <glm/glm.hpp>

namespace Managers::Window {
    class MainWindow ;
}
namespace Camera {
    class BasicCamera {
    public:
        explicit BasicCamera( Managers::Window::MainWindow *window, float closePlane, float farPlane, int width, int height);

        ~BasicCamera() = default;

        // Gets the view-matrix
        glm::mat4 getViewMatrix(){
            return this->viewMatrix;
        }

        // Gets the projection-matrix
        glm::mat4 getProjectionMatrix(){
            return this->projectionMatrix;
        }

        void setUP(glm::vec3 up_){
            this->up = up_;
        }

        // Gets the up vector
        glm::vec3 getUp(){
            return this->up;
        }

        // Gets the target vector
        glm::vec3 getDirection(){
            return this->target;
        }

        // Gets the position vector
        glm::vec3 getPosition(){
            return this->position;
        }

        // Sets the position vector
        void setPosition(glm::vec3 pos){
            if(pos.y < 0)
                return;

            position = pos;
        }
        // Calculates the view matrix
        void calculateMatrices();

        // Update the viewport height and width
        void updateViewport(int w, int h);

    protected:
        // Position of the camera
        glm::vec3 position{};

        // The target the camera points
        glm::vec3 target{};
        // The up target of the camera
        glm::vec3 up{};

        // View matrix of the camera view
        glm::mat4 viewMatrix{};
        // The projection matrix
        glm::mat4 projectionMatrix{};

        // Last mouse positions
        double lastPosX{1}, lastPostY{1};

        // Retrieves the aspect ratio of the viewport
        float getAspectRatio(){
            return (float)(this->_width / this->_height);
        }

    private:
        // The height and width of the window
        int _height{}, _width{};
        // Close and far plane of the pyramid
        float _closePlane{}, _farPlane{};

        // Pitch and yaw for the mouse
        double pitch{0.0f}, yaw{-90.0f};
        double sensitivity{0.1};

        bool _firstMouse{true};

    };
}


#endif //MIIND_PROTOTYPE_BASICCAMERA_H
