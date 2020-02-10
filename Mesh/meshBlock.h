#ifndef MESHBLOCK_H
#define MESHBLOCK_H

#include <glm/glm.hpp>
#include <vector>
#include <stdexcept>

class MeshBlock
{
public:
    MeshBlock(){
        Lines = new std::vector<std::vector<PRECISION>>();
    }

    /**
     * @brief GetBlock Retrieves the kth Line
     * @param kthBlock The block index
     * @return The Kth block location
     */
    const std::vector<PRECISION>* GetLine(size_t kthLine)
    {
        return &Lines->at(kthLine);
    }

    /**
     * @brief GetIntergralCurve Retrieves the intergral curve of the Kth pair
     * @param kthPair The start of the Kth vLine and wLine pair
     * @param step The ith step into the line
     * @return The vector containing the it's value
     */
    glm::vec3 GetIntegralCurve(size_t kthPair, size_t step)
    {
        if((kthPair + 1 % 2) == 0)
            throw std::invalid_argument( "Line number cannot be even");

        // Get the vLine and wLine
        auto xLine = GetLine(kthPair);
        auto yLine = GetLine(kthPair + 1);

        return glm::vec3(xLine->at(step), yLine->at(step), 0);
    }

    std::vector<std::vector<PRECISION>> *Lines;
};
#endif // MESHBLOCK_H
