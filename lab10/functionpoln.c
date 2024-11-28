#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> 

double findVertexX(Parabola p) {
    if (p.a == 0) {
        return NAN; 
    }
    return -p.b / (2 * p.a);
}
double findVertexY(Parabola p) {
    double x = findVertexX(p);
    if (isnan(x)) return NAN; 
    return p.a * x * x + p.b * x + p.c;
}