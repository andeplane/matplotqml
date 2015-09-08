#include "layer.h"

Layer::Layer(int id_){
    id=id_;
    Children.clear();
}

void Layer::add_child(int i){
    Children.push_back(i);
}
