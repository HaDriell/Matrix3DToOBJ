#include "Vector3.h"
#include <math.h>

Vector3::Vector3(float x, float y, float z) :
x(x),
y(y),
z(z)
{}

float Vector3::length()
{
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalized()
{
    return *this / length();
}

Vector3 operator+(const Vector3& a, const Vector3& b)
{
    float x = a.x + b.x;
    float y = a.y + b.y;
    float z = a.z + b.z;
    return Vector3(x, y, z);
}

Vector3 operator-(const Vector3& a, const Vector3& b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;
    return Vector3(x, y, z);
}

Vector3 operator/(const Vector3& a, const Vector3& b)
{
    float x = a.x / b.x;
    float y = a.y / b.y;
    float z = a.z / b.z;
    return Vector3(x, y, z);
}

Vector3 operator*(const Vector3& a, const Vector3& b)
{
    float x = a.x * b.x;
    float y = a.y * b.y;
    float z = a.z * b.z;
    return Vector3(x, y, z);
}

Vector3 operator/(const Vector3& a, float b)
{
    float x = a.x / b;
    float y = a.y / b;
    float z = a.z / b;
    return Vector3(x, y, z);
}

Vector3 operator*(const Vector3& a, float b)
{
    float x = a.x * b;
    float y = a.y * b;
    float z = a.z * b;
    return Vector3(x, y, z);
}

Vector3 operator*(float a, const Vector3& b)
{
    return b * a;
}