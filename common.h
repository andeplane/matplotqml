#ifndef COMMON_H
#define COMMON_H
#include <vector>
#include <valarray>
#include <iostream>
using std::cout; using std::endl;

using namespace std;

#define PI 3.14159265358979323846264

typedef vector<double> dvec;
typedef vector< vector<double> > dmat;
typedef vector< vector<float> > tcvec;
typedef vector< vector< vector<float> > > tcmat;

inline vector<double> linspace(double min,double max,int n){
    vector<double> a;
    if(n<1){n=1;}
    a.resize(n);
    for(int i=0;i<n;++i){a[i]=min+(max-min)*i/(n-1);}
    return a;
}

inline valarray<double> valinspace(double min,double max,int n){
    valarray<double> a;
    a.resize(n);
    for(int i=0;i<n;++i){a[i]=min+(max-min)*i/(n-1);}
    return a;
}

const int tFigure=1;
const int tAxes=2;
const int tLine=3;
const int tSurface=4;
const int tText=5;
const int tLayer=6;
const int tPatch=7;

/// contour
struct ContourPoint{
    double x,y;
    int xj,yi;
    int xy;
    int done;
};
dmat contourc(dvec x, dvec y, dmat Z, dvec v);

#endif // COMMON_H

