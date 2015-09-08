#ifndef LINE_H
#define LINE_H
#include "common.h"
#include <string>

class Line{///
 public:
    int id;
    int Errorbar;

    void reset();
    void color(float r,float g,float b);

    // Matlab oriented variables //

    dvec XData,YData,ZData;
    dvec YPData,YMData;
    //dmat XData,YData,ZData;
    //dmat EData,UData,LData;
    //dmat VData,WData;

    std::string Color;
    std::string LineStyle;// {-} | - - | : | -. | none
    float  LineWidth;
    std::string Marker;// {none}
    float  MarkerSize;
    std::string MarkerEdgeColor;
    std::string MarkerFaceColor;

    int Clipping;
    //std::string EraseMode;
    int SelectionHighlight;
    int Visible;

    // General Information
    int Parent;
    int Selected;

    Line(int id_){
    id=id_;

    Color="b";
    LineStyle="-";
    LineWidth=0.5;

    Marker="none";
    MarkerSize=6;
    MarkerEdgeColor="k";
    MarkerFaceColor="w";

    Errorbar=0;
    //PlotStyle=0;
    }
};

#endif // LINE_H
