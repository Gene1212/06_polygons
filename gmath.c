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
  product = (a[0] * b[0]) + (a[1] * b[1]) + (a[1] * b[1]);
  return product;
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {
  double norm[3];
  double x,y,z;
  
  x = (polygons->m[1][i] * polygons->m[2][i+1]) - (polygons->m[2][i] * polygons->m[1][i+1]);
  y = (polygons->m[2][i] * polygons->m[0][i+1]) - (polygons->m[0][i] * polygons->m[2][i+1]);
  z = (polygons->m[0][i] * polygons->m[1][i+1]) - (polygons->m[1][i] * polygons->m[0][i+1]);

  norm[0]=x;
  norm[1]=y;
  norm[2]=z;
  
  return norm;

}
