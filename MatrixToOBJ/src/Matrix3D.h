#pragma once

#include <string>

class Matrix3D
{
private:
    int* data;
    int width; // x
    int height;// y
    int depth; // z

    int IndexOf(int x, int y, int z) const;

public:
    Matrix3D(int width = 1, int height = 1, int depth = 1);
    ~Matrix3D();

    void resize(int width, int height, int depth);

    int get_width() const;
    int get_height() const;
    int get_depth() const;

    void set(int x, int y, int z, const int& value);
    void get(int x, int y, int z, int& value) const;
    void load(const std::string& filename);
};