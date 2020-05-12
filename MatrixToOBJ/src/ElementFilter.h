#pragma once

#include <vector>
#include <string>
#include "Vector3.h"
#include "Properties.h"

struct ElementProperties
{
    int         id;
    bool        visible;
    float       size;
    std::string name;
    Vector3     color;
};

class ElementFilter
{
private:
    std::vector<ElementProperties*> elements;

public:
    void clear();
    void debug();
    void addElement(int id, bool visible, float size, const std::string& name, Vector3 color);
    void configure(Properties& properties);
    void save(const std::string& filename);
    ElementProperties* get_element_properties(int id);
};
