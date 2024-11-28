#define FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> 
typedef struct {
    double a;
    double b;
    double c;
} Parabola;
double findVertexX(Parabola p);
double findVertexY(Parabola p);