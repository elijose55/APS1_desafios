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
/////////////////////

double delta_x = a.x - b.x;
double delta_y = a.y - b.y;

  if(fabs(delta_y) < 0.000001){ //retas horizontais
    if(fabs(p.y-a.y) < 0.000001){
      if(p.x > a.x && p.x > b.x){
        return 0;
      }
      else if(p.x < a.x && p.x < b.x){
        printf("a");
        return 0;
      }
      //
      else{
        return 2;
      }//

    }
    else{
      return 0;
    }
  }

  if(fabs(delta_x) < 0.000001){ //retas verticais
    if(p.x > a.x){
      return 0;
    }//
    if(p.x < a.x){
      if(p.y > a.y && fabs(p.y - b.y) < 0.000001 || p.y > b.y && fabs(p.y - a.y) < 0.000001){
        printf("n");
        return 1;
      }
      if((p.y > a.y && p.y < b.y) || (p.y < a.y && p.y > b.y)){
        printf("s");
        return 1;
      }
      else{
        return 0;
      }

    }
    else {
      if(p.y > a.y && p.y > b.y){
        return 0;
      }
      else if(p.y < a.y && p.y < b.y){
        return 0;
      }
      else if(fabs(p.y - a.y) < 0.000001 || fabs(p.y - b.y) < 0.000001){
        return 2;
      }
      else{
        printf("j");
        return 1;
      }
    }
  }

  double angular_coeficient = (delta_y)/(delta_x);
  double x_interseccion = (p.y + angular_coeficient*a.x - a.y)/angular_coeficient;


  if(x_interseccion > a.x && x_interseccion > b.x){
    if(fabs(x_interseccion - b.x) < 0.000001 && a.y < p.y){
      printf("f");
      return 1;
    }
    else if(fabs(x_interseccion - a.x) < 0.000001 && b.y < p.y){
      printf("w");
      return 1;
    }
    return 0;
  }
  else if(x_interseccion < a.x && x_interseccion < b.x){
    printf("2");
    return 0;
  }
  else if(x_interseccion < p.x){
    printf("3");
    return 0;
  }
  else if(fabs(x_interseccion - p.x) < 0.000001){
    return 2;
  }

  else if(fabs(x_interseccion - a.x) < 0.000001 && b.y > a.y){
    printf("4");
    return 0;
  }
  else if(fabs(x_interseccion - b.x) < 0.000001 && a.y > b.y){
    printf("5");
    return 0;
  }
  else if(fabs(x_interseccion - a.x) < 0.000001 || fabs(x_interseccion - b.x) < 0.000001){
    printf("t");
    return 1;
  }

  else {
    printf("o");
    return 1;
  }
  printf("6");
  return 0;
}
//////////////////
/*
  point p2; //ponto usado para tracar o raio horizontal
  p2.y = p.y;
  if(a.x > b.x){
    p2.x = a.x;
  }
  else{
    p2.x = b.x;
  }
  p2.x = 1000000;

  

  return 0;
}/*












/*

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
    if(fabs(p.y - a.y && p.x <= a.x) < 0.000001){
      return 
    }
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
