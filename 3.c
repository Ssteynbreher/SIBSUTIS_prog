#include <stdio.h>
#include <math.h>
int main(){
float x,y;
printf("Введите координаты точек: \n");
scanf("%f%f", &x, &y );
if (y<=1&&x<=1&&y>=-x)
printf("YES\n");
else
printf("NO\n");
}
	
