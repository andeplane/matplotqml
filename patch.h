#ifndef PATCH_H
#define PATCH_H
#include "common.h"
#include <string>

class Patch{///
 public:
    int id;
    int type;
    vector< vector<int> > Faces;
    dmat Vertices;
    dmat FaceVertexCData;
    dmat XData,YData,ZData;

    //dvec ICVec;
    //dmat ICMat;
    //tcmat CData;
    tcvec CData;

    std::string EdgeColor,FaceColor;//{ColorSpec}|none|flat|interp

    std::string LineStyle; // {-} | - - | : | -. | none
    float  LineWidth;

    Patch(int id_){
    id=id_;
    type=0;
    LineWidth=1;
    FaceColor="r";
    EdgeColor="k";
    LineStyle="-";
    }
};

#endif // PATCH_H
