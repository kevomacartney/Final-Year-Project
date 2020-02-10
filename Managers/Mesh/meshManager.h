#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <vector>
#include <string>
#include "../../Utilities/GlObjs/vertex.h"
#include "../../defines.h"
#include "../../Mesh/meshBlock.h"

namespace Managers::Meshes {
    class MeshManager {
    public:
        MeshManager();

        void loadMesh(const std::string &dir);

        // Retrieves the mesh
        std::vector<Vertex> getMesh();

    private:
        static std::vector<std::string> splitLine(const std::string &line, const char &token);

        std::vector<MeshBlock> *_meshBlocks{};

        PRECISION getType(const std::string &value);
    };
}

#endif // FILEMANAGER_H
