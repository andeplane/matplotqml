#ifndef SURFACE_H
#define SURFACE_H
#include "common.h"
#include <string>

class Surface{///
 public:
    int type;
    int id;
    std::string ColorMap;

    //dvec XData,YData;
    dmat XData,YData,ZData,CDataIndex;
    dvec V,UserData;
    tcmat CData;

    std::string FaceColor;//ColorSpec    | none | {flat}
    std::string EdgeColor;//ColorSpec{k} | none | flat

    std::string LineStyle;// {-} | - - | : | -. | none
    float  LineWidth;
    std::string Marker;// {none}
    float  MarkerSize;
    std::string MarkerEdgeColor;
    std::string MarkerFaceColor;

    int Parent;

    int NContour;

    Surface(int id_){
    id=id_;

    ColorMap="Gray";
    //Shading="faceted";
    FaceColor="flat";
    EdgeColor="b";
    LineStyle="-";
    LineWidth=0.5;
    NContour=10;
    V.clear();

    }
    void get(){
    cout <<"FaceColor: "<< FaceColor <<endl;
    cout <<"EdgeColor: "<< EdgeColor <<endl;
    cout <<"LineStyle: "<< LineStyle <<endl;
    cout <<"LineWidth: "<< LineWidth <<endl;
    }
};

#endif // SURFACE_H
