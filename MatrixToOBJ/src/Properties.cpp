#include "Properties.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

static inline void ltrim(std::string& s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
static inline void rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string& s)
{
    ltrim(s);
    rtrim(s);
}

void Properties::set(const std::string& key, const std::string& value)
{
    properties[key] = value;
}

bool Properties::get_string(const std::string& key, std::string& value)
{
    StringMap::iterator it = properties.find(key);
    if (it == properties.end()) return false;
    value = it->second;
    return true;
}

bool Properties::get_int(const std::string& key, int& value)
{
    StringMap::iterator it = properties.find(key);
    if (it == properties.end()) return false;
    value = std::stoi(it->second);
    return true;
}


bool Properties::get_float(const std::string& key, float& value)
{
    StringMap::iterator it = properties.find(key);
    if (it == properties.end()) return false;
    value = std::stof(it->second);
    return true;
}

bool Properties::get_Vector3(const std::string& key, Vector3& value)
{
    StringMap::iterator it = properties.find(key);
    if (it == properties.end()) return false;

    std::stringstream stream(it->second);
    std::string x = "0", y = "0", z = "0";
    std::getline(stream, x, ' ');
    std::getline(stream, y, ' ');
    std::getline(stream, z, ' ');    
    value.x = std::stof(x);
    value.y = std::stof(y);
    value.z = std::stof(z);
    return true;

    return false;
}

void Properties::clear()
{
    properties.clear();
}

void Properties::load(const std::string& filename)
{
    std::ifstream in;
    in.open(filename);
    if (in.is_open())
    {
        std::string line;
        while (std::getline(in, line))
        {
            trim(line);
            if (line.empty() || *line.begin() == '#') continue;
            std::stringstream stream(line);
            std::string key;
            std::string value;
            if (std::getline(stream, key, '=') && std::getline(stream, value))
            {
                trim(key);
                trim(value);
                properties[key] = value;
            }
        }
    }
}

void Properties::debug() const
{
    std::cout << "DEBUG Properties" << std::endl;
    for (auto& pair : properties)
    {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }
}