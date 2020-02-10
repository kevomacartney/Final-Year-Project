//
// Created by Kelvin Macartney on 22/12/2019.
//

#include "voaModel.h"
#include <glad/glad.h>

Utilities::GlObjs::VoaModel::VoaModel(unsigned int id, int vertexCount, bool indexed) {
    this->_voaId = id;
    this->_vertexCount = vertexCount;
    this->indexed = indexed;
}


unsigned int Utilities::GlObjs::VoaModel::getId() {
    return this->_voaId;
}

int Utilities::GlObjs::VoaModel::getVertexCount() {
    return this->_vertexCount;
}

bool Utilities::GlObjs::VoaModel::isIndex() {
    return this->indexed;
}

Utilities::GlObjs::VoaModel::~VoaModel() {
    //glDeleteVertexArrays(1, &this->getId());
}

