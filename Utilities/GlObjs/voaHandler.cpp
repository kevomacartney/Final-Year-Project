//
// Created by Kelvin Macartney on 22/12/2019.
//

#include "voaHandler.h"
#include <utility>

std::shared_ptr<Utilities::GlObjs::VoaModel> Utilities::GlObjs::VoaHandler::loadData(const std::vector<int>& indices, const std::vector<Vertex>& vertices) {
    // Create a voa&
    auto voa = createVoa();
    glBindVertexArray(voa);

    if (!indices.empty())
        // Load indices into ebo
        loadElementBufferData(indices);

    // Load the vertices data into the buffer
    loadVertexAttributeBufferData(vertices);

    int vertexCount = indices.empty() ? vertices.size() : indices.size();
    // Calculates the number of indices
    return std::make_shared<Utilities::GlObjs::VoaModel>(voa, vertexCount, !indices.empty());
}

unsigned int Utilities::GlObjs::VoaHandler::createVoa() {
    // Create a the VOA
    unsigned int v = 0;
    glGenVertexArrays(1, &v);

    return v;
}

unsigned int Utilities::GlObjs::VoaHandler::createVbo() {
    // Create a buffer for the vertices data
    unsigned int v = 0;
    glGenBuffers(1, &v);

    return v;
}

void Utilities::GlObjs::VoaHandler::loadElementBufferData(const std::vector<int> &idx) {
    unsigned int ebo = createVbo();

    // bind ebo to start loading data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, idx.size() * sizeof(unsigned int), &idx[0], GL_STATIC_DRAW);
}

void Utilities::GlObjs::VoaHandler::loadVertexAttributeBufferData(std::vector<Vertex> vertices) {
    // Create a vbo
    auto vbo = createVbo();

    // Bind vbo and load the data
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, PRECISION_GL, GL_FALSE, sizeof(Vertex), nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}