#ifndef AXES_H
#define AXES_H
#include "common.h"
#include <string>

class Axes{///
 private:

 protected:

 public:
    int id;

    float cta,phi;  // controled by mouse
    float cta0,phi0;// default value or specified by command line
    // Mouse
    double XMouse,YMouse;
    int Mouse;

    double xmin,xmax,ymin,ymax,zmin,zmax;
    int num_child;

    void reset();
    void config();
    int ID();
    int selected();
    void selected(int i);
    void add_child(int i);
    dvec make_tick(double min,double max);

    int View;// 0:2D, 1:3D

    vector<vector<float> > ColorMap;// for colorbar

    // Matlab variables //
    // styles
    int Box;//0:Off, 1:On
    std::string GridLineStyle;
    float LineWidth;
    std::string TickDir;// {in} | out
    //std::string TickDirMode;
    //TickLength
    int Visible;//0:Off, 1:On
    int XGrid,YGrid,ZGrid;// {0:Off}, 1:On

    // General Information
    int Parent;
    vector<int> Children;
    int Selected;
    float Position[4];//left bottom width height
    float Viewport3d[4];//left bottom width height

    //Scale
    std::string XAxisLocation;
    std::string YAxisLocation;

    //std::string XDir,YDir,ZDir;

    double XLim[2],YLim[2],ZLim[2];//plot range
    int XLimMode,YLimMode,ZLimMode;//0:Auto 1:Manual

    int XScale,YScale,ZScale;// linear | log

    dvec XTick,YTick,ZTick;
    std::string XTickMode,YTickMode,ZTickMode;
    int TickLabel;// 0:Off, {1:On}
    //View
    float CameraPosition[3];
    float CameraTarget[3];
    float CameraUpVector[3];

    // Label
    std::string Title;
    std::string XLabel,YLabel,ZLabel;

    double CLim[2];

    Axes(int id_){
    id=id_;
    Selected=0;
    Position[0]=0.13;
    Position[1]=0.11;
    Position[2]=0.775;
    Position[3]=0.815;

    Viewport3d[0]=0.0;
    Viewport3d[1]=0.0;
    Viewport3d[2]=1.0;
    Viewport3d[3]=1.0;

    Mouse=1;
    View=0;
    Visible=1;
    Box=1;
    Children.clear();

    cta0=30;
    phi0=30;
    cta=cta0;
    phi=cta0;

    CameraPosition[0]=1; CameraPosition[1]=1; CameraPosition[2]=1;
    CameraTarget[0]=0.;  CameraTarget[1]=0; CameraTarget[2]=0;
    CameraUpVector[0]=0; CameraUpVector[1]=0; CameraUpVector[2]=1;

    LineWidth=1;

    GridLineStyle=":";
    XGrid=0;
    YGrid=0;
    ZGrid=0;

    XLim[0]=0;    XLim[1]=10;
    YLim[0]=0;    YLim[1]=10;
    ZLim[0]=0;    ZLim[1]=10;

    XLimMode=0; YLimMode=0; ZLimMode=0;
    XAxisLocation="bottom";//top | bottom
    YAxisLocation="left";// left | right
    XScale=0;// {0:linear} | 1:log
    YScale=0;
    ZScale=0;

    TickLabel=1;
    TickDir="in";

    xmin= 1e99;    xmax=-1e99;
    ymin= 1e99;    ymax=-1e99;
    zmin= 1e99;    zmax=-1e99;

    CLim[0]=0;CLim[1]=0;

    num_child=0;
    //MakeTick();
    //Parent=i_figure;
    };
};

#endif // AXES_H
