#pragma once

#include <string>
#include <vector>
#include "Vector3.h"

struct Mesh
{
    std::string material;
    std::vector<Vector3> vertices;
    std::vector<unsigned int> triangles;

    void save(const std::string& filename) const;
};