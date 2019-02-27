#include <math.h>

#include "geometry.h"

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

int inside(point p, point poly[], int n) {
  return 0;
}
