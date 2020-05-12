#pragma once



struct Vector3
{
    float x;
    float y;
    float z;

    Vector3(float x = 0, float y = 0, float z = 0);

    float length();

    Vector3 normalized();
};

Vector3 operator+(const Vector3& a, const Vector3& b);
Vector3 operator-(const Vector3& a, const Vector3& b);
Vector3 operator/(const Vector3& a, const Vector3& b);
Vector3 operator*(const Vector3& a, const Vector3& b);

Vector3 operator/(const Vector3& a, float b);
Vector3 operator*(const Vector3& a, float b);
Vector3 operator*(float a, const Vector3& b);