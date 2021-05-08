#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
  vector[0] = 0;
  vector[1] = 0;
  vector[2] = 1;

}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  double product = 0;
  product = (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
  //printf("%lf %lf %lf\n",a[0],a[1],b[1])
  return product;
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {
  double norm[3];
  double x,y,z;
  double ax,ay,az,bx,by,bz;

  ax = polygons->m[0][i+1] - polygons->m[0][i];
  ay = polygons->m[1][i+1] - polygons->m[1][i];
  az = polygons->m[2][i+1] - polygons->m[2][i];
  bx = polygons->m[0][i+2] - polygons->m[0][i];
  by = polygons->m[1][i+2] - polygons->m[1][i];
  bz = polygons->m[2][i+2] - polygons->m[2][i];

  
  x = (ay*bz - (az * by));
  y = ((az*bx - (ax*bz)));
  z = ((ax*by - (ay*bx)));

  norm[0]=x;
  norm[1]=y;
  norm[2]=z;

  double *arr;
  arr = norm;
  
  return arr;

}
