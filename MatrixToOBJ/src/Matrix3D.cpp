#include "Matrix3D.h"

#include <fstream>
#include <iostream>

Matrix3D::Matrix3D(int width, int height, int depth) :
width(width),
height(height),
depth(depth),
data(nullptr)
{
    data = new int[width * height * depth];
    for (int i = 0; i < width * height * depth; i++)
    {
        data[i] = 0;
    }
}

Matrix3D::~Matrix3D()
{
    delete[] data;
}

void Matrix3D::resize(int width, int height, int depth)
{
    //Reallocate data
    delete[] data;
    data = new int[width * height * depth];

    //Edit size
    this->width = width;
    this->height = height;
    this->depth = depth;
}

int Matrix3D::get_width() const
{
    return width;
}

int Matrix3D::get_height() const
{
    return height;
}

int Matrix3D::get_depth() const
{
    return depth;
}

int Matrix3D::IndexOf(int x, int y, int z) const
{
    return x + width * y + width * height * z;
}

void Matrix3D::set(int x, int y, int z, const int& value)
{
    data[IndexOf(x, y, z)] = value;
}

void Matrix3D::get(int x, int y, int z, int& value) const
{
    value = data[IndexOf(x, y, z)];
}

void Matrix3D::load(const std::string& filename)
{
    std::ifstream in;
    in.open(filename);
    if (in.is_open())
    {
        for (int i = 0; i < width * height * depth; i++)
        {
            std::string word;
            if (std::getline(in, word, ','))
            {
                data[i] = std::stoi(word);
            }
        }

        if (in.bad())
        {
            std::cout << "A problem occured" << std::endl;
        }
    }
}
