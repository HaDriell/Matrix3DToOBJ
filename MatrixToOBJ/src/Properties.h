#pragma once

#include <map>
#include <string>
#include "Vector3.h"

class Properties
{
private:
    using StringMap = std::map<std::string, std::string>;

    StringMap properties;

public:
    void set(const std::string& key, const std::string& value);
    bool get_string(const std::string& key, std::string& value);
    bool get_int(const std::string& key, int& value);
    bool get_float(const std::string& key, float& value);
    bool get_Vector3(const std::string& key, Vector3& value);

    void debug() const;
    void clear();
    void load(const std::string& filename);
};