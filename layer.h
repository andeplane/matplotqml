#ifndef LAYER_H
#define LAYER_H
#include <vector>
#include <string>
#include "common.h"

class Layer{///
public:
    int id;
    int Visible;
    std::string layername;
    std::vector<int> Children;
    Layer(int id_);
    void add_child(int i);
};

#endif // LAYER_H
