#include "Scene.h"
#include <fstream>
#include <iostream>
#include "Vector3.h"


void Scene::sphere(float x, float y, float z, float radius, const std::string& materialName)
{
    Vector3 position = Vector3(x, y, z);

    Mesh& mesh = meshes.emplace_back();
    mesh.material = materialName;

    mesh.vertices.push_back(Vector3());

    //12 Points of the Icosahedron (from https://people.sc.fsu.edu/~jburkardt/data/obj/icosahedron.obj)
    mesh.vertices.push_back(position + radius * Vector3(0, -0.525731, 0.850651));
    mesh.vertices.push_back(position + radius * Vector3(0.850651, 0, 0.525731));
    mesh.vertices.push_back(position + radius * Vector3(0.850651, 0, -0.525731));
    mesh.vertices.push_back(position + radius * Vector3(-0.850651, 0, -0.525731));
    mesh.vertices.push_back(position + radius * Vector3(-0.850651, 0, 0.525731));
    mesh.vertices.push_back(position + radius * Vector3(-0.525731, 0.850651, 0));
    mesh.vertices.push_back(position + radius * Vector3(0.525731, 0.850651, 0));
    mesh.vertices.push_back(position + radius * Vector3(0.525731, -0.850651, 0));
    mesh.vertices.push_back(position + radius * Vector3(-0.525731, -0.850651, 0));
    mesh.vertices.push_back(position + radius * Vector3(0, -0.525731, -0.850651));
    mesh.vertices.push_back(position + radius * Vector3(0, 0.525731, -0.850651));
    mesh.vertices.push_back(position + radius * Vector3(0, 0.525731, 0.850651));
    
    //20 faces of the Icosahedron
    mesh.triangles.push_back(2); mesh.triangles.push_back(3); mesh.triangles.push_back(7);
    mesh.triangles.push_back(2); mesh.triangles.push_back(8); mesh.triangles.push_back(3);
    mesh.triangles.push_back(4); mesh.triangles.push_back(5); mesh.triangles.push_back(6);
    mesh.triangles.push_back(5); mesh.triangles.push_back(4); mesh.triangles.push_back(9);
    mesh.triangles.push_back(7); mesh.triangles.push_back(6); mesh.triangles.push_back(12);
    mesh.triangles.push_back(6); mesh.triangles.push_back(7); mesh.triangles.push_back(11);
    mesh.triangles.push_back(10); mesh.triangles.push_back(11); mesh.triangles.push_back(3);
    mesh.triangles.push_back(11); mesh.triangles.push_back(10); mesh.triangles.push_back(4);
    mesh.triangles.push_back(8); mesh.triangles.push_back(9); mesh.triangles.push_back(10);
    mesh.triangles.push_back(9); mesh.triangles.push_back(8); mesh.triangles.push_back(1);
    mesh.triangles.push_back(12); mesh.triangles.push_back(1); mesh.triangles.push_back(2);
    mesh.triangles.push_back(1); mesh.triangles.push_back(12); mesh.triangles.push_back(5);
    mesh.triangles.push_back(7); mesh.triangles.push_back(3); mesh.triangles.push_back(11);
    mesh.triangles.push_back(2); mesh.triangles.push_back(7); mesh.triangles.push_back(12);
    mesh.triangles.push_back(4); mesh.triangles.push_back(6); mesh.triangles.push_back(11);
    mesh.triangles.push_back(6); mesh.triangles.push_back(5); mesh.triangles.push_back(12);
    mesh.triangles.push_back(3); mesh.triangles.push_back(8); mesh.triangles.push_back(10);
    mesh.triangles.push_back(8); mesh.triangles.push_back(2); mesh.triangles.push_back(1);
    mesh.triangles.push_back(4); mesh.triangles.push_back(10); mesh.triangles.push_back(9);
    mesh.triangles.push_back(5); mesh.triangles.push_back(9); mesh.triangles.push_back(1);
}

void Scene::cube(float x, float y, float z, float size, const std::string& materialName)
{
    Vector3 position = Vector3(x, y, z);
    float halfSize = size / 2.0f;

    Mesh& mesh = meshes.emplace_back();
    mesh.material = materialName;

    //Front panel (4 vertices)
    mesh.vertices.push_back(position + Vector3(-halfSize, -halfSize, -halfSize));
    mesh.vertices.push_back(position + Vector3(+halfSize, -halfSize, -halfSize));
    mesh.vertices.push_back(position + Vector3(+halfSize, +halfSize, -halfSize));
    mesh.vertices.push_back(position + Vector3(-halfSize, +halfSize, -halfSize));
    //Back panel (4 vertices)
    mesh.vertices.push_back(position + Vector3(-halfSize, +halfSize, +halfSize));
    mesh.vertices.push_back(position + Vector3(+halfSize, +halfSize, +halfSize));
    mesh.vertices.push_back(position + Vector3(+halfSize, -halfSize, +halfSize));
    mesh.vertices.push_back(position + Vector3(-halfSize, -halfSize, +halfSize));
    
    //Faces
    mesh.triangles.push_back(0); mesh.triangles.push_back(2); mesh.triangles.push_back(1); //face front
    mesh.triangles.push_back(0); mesh.triangles.push_back(3); mesh.triangles.push_back(2);
    mesh.triangles.push_back(2); mesh.triangles.push_back(3); mesh.triangles.push_back(4); //face top
    mesh.triangles.push_back(2); mesh.triangles.push_back(4); mesh.triangles.push_back(5);
    mesh.triangles.push_back(1); mesh.triangles.push_back(2); mesh.triangles.push_back(5); //face right
    mesh.triangles.push_back(1); mesh.triangles.push_back(5); mesh.triangles.push_back(6);
    mesh.triangles.push_back(0); mesh.triangles.push_back(7); mesh.triangles.push_back(4); //face left
    mesh.triangles.push_back(0); mesh.triangles.push_back(4); mesh.triangles.push_back(3);
    mesh.triangles.push_back(5); mesh.triangles.push_back(4); mesh.triangles.push_back(7); //face back
    mesh.triangles.push_back(5); mesh.triangles.push_back(7); mesh.triangles.push_back(6);
    mesh.triangles.push_back(0); mesh.triangles.push_back(6); mesh.triangles.push_back(7); //face bottom
    mesh.triangles.push_back(0); mesh.triangles.push_back(1); mesh.triangles.push_back(6);
}

void Scene::save(const std::string& filename) const
{
    std::ofstream out;
    out.open(filename);

    if (!out.is_open())
    {
        std::cout << "Can't open file : " << filename << std::endl;
        return;
    }
    out << "#Scene generated by MatrixToOBJ" << std::endl;
    out << "#Feel free to provide a mtllib for this file" << std::endl;
    out << "mtllib " << materialLibrary << std::endl;

    unsigned int IndexOffset = 1; // OBJ indexing starts at 1... why ?!
    for (int i = 0; i < meshes.size(); i++)
    {
        //Spacing Esthetics
        out << std::endl;

        auto& mesh = meshes[i];

        //Mesh Vertices
        for (auto& vertex : mesh.vertices)
        {
            out << "v" << " " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
        }

        //Mesh Details
        out << "o Mesh_" << i << std::endl;
        out << "g Mesh_" << i << std::endl;
        out << "usemtl " << mesh.material << std::endl;

        //Mesh Triangles
        for (int face = 0; face < mesh.triangles.size(); face += 3)
        {
            unsigned int v0 = mesh.triangles[face + 0] + IndexOffset;
            unsigned int v1 = mesh.triangles[face + 1] + IndexOffset;
            unsigned int v2 = mesh.triangles[face + 2] + IndexOffset;
            out << "f" << " " << v0 << " " << v1 << " " << v2 << std::endl;
        }

        IndexOffset += mesh.vertices.size();
    }
}