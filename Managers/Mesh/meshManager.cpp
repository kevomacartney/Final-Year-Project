#include "meshManager.h"

#include <exception>
#include <sstream>
#include <iostream>


Managers::Meshes::MeshManager::MeshManager() = default;

void Managers::Meshes::MeshManager::loadMesh(const std::string& dir)
{
    // open file
    std::ifstream file;
    file.open(dir);

    this->_meshBlocks = new std::vector<MeshBlock>();

    if (file.is_open()) {
            std::cout << "Successfully loaded mesh file\n";
        } else {
        std::cout << "Failed to open the file!\n";
        throw std::exception();
    }

    size_t i = 0;

    MeshBlock block;

    while (!file.eof()){
        i++;

        std::string line;
        getline(file, line);

        if(i < 3)
            continue;

        if(line == "closed"){
            // add the current block, then create a new one
            this->_meshBlocks->push_back(block);
            block = MeshBlock();
            continue;
        }
        if(line == "end")
            continue;

        std::vector<PRECISION> lineData;
        for (const auto& var : Managers::Meshes::MeshManager::splitLine(line, ' ')){
            lineData.push_back(this->getType(var));
        }

        // Add the lines to the block
        block.Lines->push_back(lineData);
    }

    file.close();
}

std::vector<std::string> Managers::Meshes::MeshManager::splitLine(const std::string &line, const char &token) {

    std::vector <std::string> strings;
    std::stringstream stream(line);
    std::string intermediate;

    // Tokenizing w.r.t. space ' '
    while(getline(stream, intermediate, token))
    {
        strings.push_back(intermediate);
    }

    return strings;
}

PRECISION Managers::Meshes::MeshManager::getType(const std::string &value) {
    return CONVERT_TO_PRECISION(value);
}

std::vector<Vertex> Managers::Meshes::MeshManager::getMesh() {
    std::vector<Vertex> vertices{};

    for(auto mesh : *this->_meshBlocks)
    {
        for (u_long i = 0; i < mesh.Lines->size(); i+=2) {
            for (u_long j = 0; j < mesh.Lines->at(i).size(); ++j) {
                Vertex v;
                v.Position = mesh.GetIntegralCurve(i, j);
                vertices.push_back(v);
            }
        }
    }

    return vertices;
}
