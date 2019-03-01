#include <math.h>

#include "geometry.h"



int verify(point p, point a, point b) {

  //verificar se o ponto esta sobre o segmento - adptado de https://stackoverflow.com/questions/328107/how-can-you-determine-a-point-is-between-two-other-points-on-a-line-segment
  double crossproduct = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);

  if(fabs(crossproduct) < 0.000001){
    double dotproduct = (p.x - a.x) * (b.x - a.x) + (p.y - a.y)*(b.y - a.y);
    double squaredlength = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    if(dotproduct > 0 && dotproduct < squaredlength){
      return 2;
    }
  }

  //verificar se o raio disparado cruza o segmento

  double delta_x = a.x - b.x;
  double delta_y = a.y - b.y;

  if(fabs(delta_y) < 0.000001){ //para segmentos horizontais
    if(fabs(p.y-a.y) < 0.000001){
      if(p.x > a.x && p.x > b.x){
        return 0;
      }
      else if(p.x < a.x && p.x < b.x){
        return 0;
      }
      else{
        return 2;
      }
    }
    else{
      return 0;
    }
  }
  if(fabs(delta_x) < 0.000001){ //para segmentos verticais
    if(p.x > a.x){
      return 0;
    }
    if(p.x < a.x){
      if(p.y > a.y && fabs(p.y - b.y) < 0.000001 || p.y > b.y && fabs(p.y - a.y) < 0.000001){
        return 1;
      }
      if((p.y > a.y && p.y < b.y) || (p.y < a.y && p.y > b.y)){
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
        return 1;
      }
    }
  }

  //para segmentos em geral
  double angular_coeficient = (delta_y)/(delta_x);
  double x_interseccion = (p.y + angular_coeficient*a.x - a.y)/angular_coeficient;

  if(x_interseccion > a.x && x_interseccion > b.x){
    if(fabs(x_interseccion - b.x) < 0.000001 && a.y < p.y ){
      return 1;
    }
    else if(fabs(x_interseccion - a.x) < 0.000001 && b.y < p.y){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if(x_interseccion < a.x && x_interseccion < b.x){
    return 0;
  }
  else if(x_interseccion < p.x){
    return 0;
  }
  else if(fabs(x_interseccion - p.x) < 0.000001){
    return 2;
  }
  else if(fabs(x_interseccion - a.x) < 0.000001 && b.y > a.y){
    return 0;
  }
  else if(fabs(x_interseccion - b.x) < 0.000001 && a.y > b.y){
    return 0;
  }
  else if(fabs(x_interseccion - a.x) < 0.000001 || fabs(x_interseccion - b.x) < 0.000001){
    return 1;
  }
  else {
    return 1;
  }
  return 0;
}

int inside(point p, point poly[], int n) {
  return 0;
}
