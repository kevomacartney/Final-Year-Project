//
// Created by Kelvin Macartney on 04/02/2020.
//

#ifndef MIIND_VERTEX_H
#define MIIND_VERTEX_H
#include <glm/glm.hpp>

struct Vertex{
public:
    Vertex()= default;
    explicit Vertex(glm::vec3 pos){
        Position = pos;
    }
    glm::vec3 Position{};
};


#endif //MIIND_VERTEX_H
