//
// Created by Kelvin Macartney on 03/02/2020.
//

#ifndef MIIND_DEFINES_H
#define MIIND_DEFINES_H
#include <string>
#include <glad/glad.h>

// precision to be used
#ifndef PRECISION
#define PRECISION float
#define PRECISION_GL GL_FLOAT

// Conversion method
#define CONVERT_TO_PRECISION(str) std::stod(str)
#endif

#endif //MIIND_DEFINES_H
