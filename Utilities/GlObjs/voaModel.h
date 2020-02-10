//
// Created by Kelvin Macartney on 22/12/2019.
//

#ifndef MIIND_PROTOTYPE_VOAMODEL_H
#define MIIND_PROTOTYPE_VOAMODEL_H

namespace Utilities::GlObjs {
    // Represents a single VOA object
    class VoaModel {
    public:
        VoaModel(unsigned int id, int vertexCount, bool indexed);

        // Retrieves the VOA id
        unsigned int getId();

        // Retrieves the vertices count
        int getVertexCount();

        // Gets a boolean indicating if EBO was used for this model
        bool isIndex();

        ~VoaModel();

    private:
        unsigned int _voaId{};
        int _vertexCount{};
        bool indexed{false};
    };
}

#endif //MIIND_PROTOTYPE_VOAMODEL_H
