#pragma once

#include "Mesh.h"
#include <string>


struct Scene
{
    std::string materialLibrary;
    std::vector<Mesh> meshes;

    void sphere(float x, float y, float z, float radius, const std::string& materialName);
    void cube(float x, float y, float z, float size, const std::string& materialName);
    void save(const std::string& filename) const;
};