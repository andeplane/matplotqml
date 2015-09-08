#ifndef TEXT_H
#define TEXT_H
#include "common.h"
#include <string>

class Text{///
 public:
    int id;
    std::string String;
    float Position[3];
    int Parent;
    int type;//0:axis 1:figure
    Text(int id_);
};

#endif // TEXT_H
