#ifndef MATPLOT_H
#define MATPLOT_H
#include <vector>
#include <string>
#include "common.h"
#include "figure.h"
#include "layer.h"
#include "axes.h"
#include "line.h"
#include "surface.h"
#include "patch.h"
#include "text.h"

class MatPlot {///
private:
    int is_debug1;
    int is_debug2;

    vector<vector<float> > cmap;//TODO move to class Figure

    int mode; //0:initialization 1:configuration
    int init_level; // initialization level of objects
    int hObj; // handle number of current object

    // pointer to current objects //
    Figure *cf;
    Layer *cfr;
    Axes *ca;
    Line *cl;
    Surface *cs;
    Patch *cp;
    Text *ct;

    // objects containers //
    std::vector< Figure > vFigure;
    std::vector< Layer > vLayer;
    std::vector< Axes > vAxes;
    std::vector< Line > vLine;
    std::vector< Surface > vSurface;
    std::vector< Patch > vPatch;
    std::vector< Text > vText;

    // objects counter //
    int iFigure;
    int iLayer;
    int iAxes;
    int iLine;
    int iSurface;
    int iPatch;
    int iText;

    // Selected object //
    int iAxesSelected;

    // coordinate transform  //
    // figure coordination
    float ctx2(double x);
    float cty2(double y);
    // axes coordination
    float ctx(double x);
    float cty(double y);
    float ct3x(double x);
    float ct3y(double y);
    float ct3z(double z);

    int figure();

    // display //
    void display_figure();
    void display_layer();
    void display_layer2();

    void display_axes();
    void display_axes_2d();
    void display_axes_3d();
    void display_axes_colorbar();

    void display_line();

    void display_surface();
    void display_surface_2d();
    void display_surface_3d();
    void display_pcolor();
    void display_contour();

    void display_patch();
    void display_patch_2d();
    void display_patch_3d();


    void display_bar();

    void display_text();

    // mouse //
    void Layer_mouse(int button, int state, int x, int y );
    void Axes_mouse(int button, int state, int x, int y );
    void Axes_motion(int x, int y );


    void surface_config();
    void line_config();
    void patch_config();
    tcvec Index2TrueColor(dvec IC);

public:

    MatPlot();
    ~MatPlot();

    void inline debug1(){is_debug1=1;}
    void inline debug2(){is_debug2=1;}

    // GLUT Callback Functions ///
    void display();
    void reshape(int w, int h);

    // Layer ///
    int layer();
    int layer(std::string s,int Visible);
    int frame(std::string s,int Visible);// do not use

    // Axes ///

    int axes();
    int gca();
    int subplot(int m,int n,int p);

    int colorbar();

    void axis(double xMin,double xMax,double yMin,double yMax);
    void axis(double xMin,double xMax,double yMin,double yMax,double zMin,double zMax);

    void axis(std::string s);
    void axis(int s);

    void grid(std::string s);
    void grid(int s);

    void ticklabel(std::string s);
    void ticklabel(int s);

    void title(std::string s);
    void xlabel(std::string s);
    void ylabel(std::string s);
    void zlabel(std::string s);

    // set, General Object Handling ///
    void set(std::string v);
    void set(float v);
    void set(std::string p,float v);
    void set(std::string p,std::string v);
    void set(int h,std::string p,std::string v);
    void set(int h,std::string p,float v);
    int gco();

    // Line ///
    int begin();//do not use
    void end();//do not use
    void vertex(double x,double y);
    void vertex(double x,double y,double z);

    int line();
    int line(dvec x,dvec y);
    int line(dvec x,dvec y,dvec z);

    int plot(dvec y);
    int plot(dvec x,dvec y);
    int plot(valarray<double> x,valarray<double> y);

    int plot3(dvec x,dvec y,dvec z);

    int semilogx(dvec x,dvec y);
    int semilogy(dvec x,dvec y);
    int loglog(dvec x,dvec y);

    void vertex(double x,double y,double ep,double em);
    int errorbar(dvec x,dvec y,dvec e);
    int errorbar(dvec x,dvec y,dvec ep,dvec em);

    // Surface, Contour ///
    dmat peaks(int n);

    int surface();
    int surface(dmat Z);
    int surface(dmat Z,dmat C);
    int surface(dmat Z,tcmat C); //!!
    int surface(dvec x,dvec y,dmat Z);
    int surface(dvec x,dvec y,dmat Z,dmat C);
    int surface(dvec x,dvec y,dmat Z,tcmat C);//!!
    int surface(dmat X,dmat Y,dmat Z);
    int surface(dmat X,dmat Y,dmat Z,dmat C);
    int surface(dmat X,dmat Y,dmat Z,tcmat C);//!!

    int pcolor(dmat C);
    int pcolor(tcmat C);
    int pcolor(dvec x,dvec y,dmat C);
    int pcolor(dvec x,dvec y,tcmat C);
    int pcolor(dmat X,dmat Y,dmat C);
    int pcolor(dmat X,dmat Y,tcmat C);

    int contour(dmat Z);
    int contour(dmat Z,int n);
    int contour(dmat Z,dvec v);
    int contour(dvec x, dvec y, dmat Z);
    int contour(dvec x, dvec y, dmat Z,int n);
    int contour(dvec x, dvec y, dmat Z,dvec v);

    int mesh(dvec x, dvec y, dmat Z);
    int surf(dvec x, dvec y, dmat Z);

    // Patch ///

    int patch();
    int patch(dmat X,dmat Y);
    int patch(dmat X,dmat Y,dvec C);
    int patch(dmat X,dmat Y,tcvec C);
    int patch(dmat X,dmat Y,dmat Z);//!!
    int patch(dmat X,dmat Y,dmat Z,dvec C);//!!
    int patch(dmat X,dmat Y,dmat Z,tcvec C);//!!

    int bar(dvec y);
    int bar(dvec y,float width);
    int bar(dvec x,dvec y);
    int bar(dvec x,dvec y,float width);

    int text();
    int text(double x,double y,std::string s);
    void set_font(char font_[],int size);
    void ptext(float x,float y,std::string s);
    void ptext3(float x,float y,float z,std::string s);
    void ptext3c(float x,float y,float z,std::string s);

    // Colors ///
    void color(float r,float g,float b);
    vector<float> colormap(std::string c,float t);
    void colormap(std::string c);
    void colormap(vector<vector<float> > c);

    void gray();
    void jet();
    void hsv();
    void hot();
    void cool();
    void spring();
    void summer();
    void autumn();
    void winter();

    vector<float> map2color(double x,double xmin,double xmax);

    void Shading(std::string c);
    void shading(std::string c);
    vector<float> ColorSpec2RGB(std::string c);
    std::string rgb2colorspec(vector<float> rgb);

};

#endif // MATPLOT_H
