#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include "common.h"

class Figure{///
 public:
    int id;
    //int Status;// 0:minimized, 1:default position, 2:maximized
    int Position[4];//left top width height
    int Visible;
    std::vector<int> Children;

    void add_child(int i);
    Figure(int id_){
    id=id_;
    //Status=1;
    //Position[0]=100;
    //Position[1]=100;
    //Position[2]=800;
    //Position[3]=800;
    Visible=1;
    };
};

#endif // FIGURE_H
