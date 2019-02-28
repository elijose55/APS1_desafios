#include <math.h>

#include "geometry.h"

int verify(point p, point a, point b) {
//------------------------------

  //sobre a aresta (2)
  double crossproduct = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);

  if(fabs(crossproduct) < 0.000001){
    double dotproduct = (p.x - a.x) * (b.x - a.x) + (p.y - a.y)*(b.y - a.y);
    double squaredlength = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    if(dotproduct > 0 && dotproduct < squaredlength){
      return 2;
    }
  }

  //raio cruza a aresta (1)
  point p2; //ponto usado para tracar o raio horizontal
  p2.y = p.y;
  if(a.x > b.x){
    p2.x = a.x;
  }
  else{
    p2.x = b.x;
  }
  p2.x = 1000000;
  double h1 = ((p2.x-p.x)*(-b.y+a.y))+((p2.y-p.y)*(b.x-a.x));
  double h2 = ((a.x - p.x)*(-b.y+a.y))+((a.y-p.y)*(b.x-a.x));
  if(h1 < 0.000001){
    return 0;
  }
  double h = h2/h1;
  if(h>0 && h<1){
    return 1;
  }
  else{
    return 0;
  }
}
/*
int verify(point p, point a, point b) {
  double angular_coeficient;
  
  if(fabs(a.x - b.x - 0) < 0.000001){
    if(p.x > a.x){ return 0;}
    else if(p.x < a.x){ return 1;}
    else{ return 2;}
  }
  angular_coeficient = (a.y - b.y)/(a.x - b.x);
  double interseccion = (p.y - a.y) - (angular_coeficient*(p.x - a.x));
  double x0 = (p.y + angular_coeficient*a.x - a.y)/angular_coeficient;
  
  if(fabs(interseccion) < 0.000001){
    return 2;
  }
  else if(fabs(angular_coeficient - 0) < 0.000001){
    return 0;
  } 
  else if(fabs(x0 - p.x) < 0.000001){
    return 1;
  }
  else{
    return 0;
  }
}
*/
int inside(point p, point poly[], int n) {
  return 0;
}
