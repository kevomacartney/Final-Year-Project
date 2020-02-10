//
// Created by Kelvin Macartney on 22/12/2019.
//

#ifndef MIIND_PROTOTYPE_VOAHANDLER_H
#define MIIND_PROTOTYPE_VOAHANDLER_H

#include "glad/glad.h"
#include "../../defines.h"
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <memory>
#include <vector>

#include "vertex.h"
#include "voaModel.h"

namespace Utilities::GlObjs {
    // Handles VOA objects
    class VoaHandler {
    public:
        static std::shared_ptr<Utilities::GlObjs::VoaModel> loadData(const std::vector<int> &indices,
                                                                     const std::vector<Vertex> &vertices);

    private:
        // Create a new Vertex Object Array buffer
        static unsigned int createVoa();

        // Create a new Vertex Buffer Object
        static unsigned int createVbo();

        // Loads indices into the an Element  buffer
        static void loadElementBufferData(const std::vector<int> &idx);

        // Loads the specified vertices object into vertices buffer
        static void loadVertexAttributeBufferData(std::vector<Vertex> vertices);
    };
}


#endif //MIIND_PROTOTYPE_VOAHANDLER_H
