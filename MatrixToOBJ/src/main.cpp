#include <iostream>
#include <string>

#include "Matrix3D.h"
#include "Properties.h"
#include "Scene.h"
#include "ElementFilter.h"



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                          Function Prototypes                              */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void InitializeDefaultProperties(Properties& properties);
void ConfigureMatrix(Properties& properties, Matrix3D& matrix);
void DebugMatrixElement(const Matrix3D& matrix, float elementType);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                             Main Program                                  */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(int argc, char** argv)
{
    //Load the application configuration
    Properties properties;
    InitializeDefaultProperties(properties);
    properties.load("application.properties");
    //properties.debug();

    //Modify Properties BEFORE THAT LINE

    //Load the matrix
    Matrix3D matrix;
    ConfigureMatrix(properties, matrix);

    //Load the ElementFilter parameters
    ElementFilter filter;
    filter.configure(properties);
    filter.debug();

    //Create a Scene & populate it
    Scene scene;
    properties.get_string("matrix.mtl.output", scene.materialLibrary);

    std::cout << "Populating Scene" << std::endl;
    for (int x = 0; x < matrix.get_width(); x++)
    {
        for (int y = 0; y < matrix.get_height(); y++)
        {
            for (int z = 0; z < matrix.get_depth(); z++)
            {
                int elementID = 0;
                matrix.get(x, y, z, elementID);
                if (elementID != 0)
                {
                    ElementProperties* elementProperties = filter.get_element_properties(elementID);
                    if (!elementProperties) continue;
                    if (!elementProperties->visible) continue;

                    scene.cube(x, y, z, elementProperties->size, elementProperties->name);
                }
            }
        }
    }
    std::cout << "Scene Populated (" << scene.meshes.size() << " meshes)" << std::endl;

    std::string objFile;
    std::string mtlFile;
    properties.get_string("matrix.obj.output", objFile);
    properties.get_string("matrix.mtl.output", mtlFile);

    std::cout << "Saving Scene to " << objFile << std::endl;
    scene.save(objFile);

    std::cout << "Saving Materials to " << mtlFile << std::endl;
    filter.save(mtlFile);
    std::cout << "Press any key to Exit" <<std::endl;
    std::cin.get();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                      Function Implementations                             */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void InitializeDefaultProperties(Properties& properties)
{
    properties.clear();
    properties.set("matrix.input.filename", "matrix.txt");
    properties.set("matrix.obj.filename", "matrix.obj");
    properties.set("matrix.mtl.filename", "matrix.mtl");
}

void ConfigureMatrix(Properties& properties, Matrix3D& matrix)
{
    int width = matrix.get_width();
    int height = matrix.get_height();
    int depth = matrix.get_depth();
    bool resizeX = properties.get_int("matrix.width", width);
    bool resizeY = properties.get_int("matrix.height", height);
    bool resizeZ = properties.get_int("matrix.depth", depth);

    if (resizeX || resizeY || resizeZ)
    {
        std::cout << "Resizing Matrix to (" << width << "x" << height << "x" << depth << ")" << std::endl;
        matrix.resize(width, height, depth);
    }

    std::string filename;
    if (properties.get_string("matrix.input.filename", filename))
    {
        std::cout << "Loading Matrix from " << filename << std::endl;
        matrix.load(filename);
    }
}

void DebugMatrixElement(const Matrix3D& matrix, float elementType)
{
    int count = 0;
    for (int x = 0; x < matrix.get_width(); x++)
    {
        for (int y = 0; y < matrix.get_height(); y++)
        {
            for (int z = 0; z < matrix.get_depth(); z++)
            {
                int value = -1;
                matrix.get(x, y, z, value);
                if (value == elementType)
                {
                    count++;
                }
            }
        }
    }

    std::cout << "DEBUG -> " << count << " Elements of type " << int(elementType) << std::endl;
}