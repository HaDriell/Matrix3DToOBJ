#pragma once

#include "Mesh.h"
#include <string>


struct Scene
{
    std::string materialLibrary;
    std::vector<Mesh> meshes;


    void cube(float x, float y, float z, float size, const std::string& materialName);
    void save(const std::string& filename) const;
};