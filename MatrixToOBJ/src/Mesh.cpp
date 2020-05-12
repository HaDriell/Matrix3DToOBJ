#include "Mesh.h"
#include <fstream>

void Mesh::save(const std::string& filename) const
{
    std::ofstream out;
    out.open(filename);
    if (out.is_open())
    {
        //Write vertices
        for (auto& vertex : vertices)
        {
            out << "v" << " " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl; 
        }

        //Pure esthetics
        out << std::endl;

        //Write faces
        for (int f = 0; f < triangles.size(); f += 3)
        {
            int a = triangles[f + 0] + 1;
            int b = triangles[f + 1] + 1;
            int c = triangles[f + 2] + 1;

            out << "f" << " " << a << " " << b << " " << c << std::endl;
        }
    }
}