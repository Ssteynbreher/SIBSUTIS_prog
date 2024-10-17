#include <stdio.h>
int main(){
    //создаем массивы с комплексными числами, с четным идексом-реальная часть, с нечетными-мнимая, заполним а и в любым способом любыми числами 
    int i;
    int a[6]={1,2,3,4,5,6};
    int b[6]={1,-9,3,-8,5,6};
    int c[6];
    //сложим а и б
    for (i = 0; i < 6; i++){
        c[i] = a[i]+b[i];
        }
    //найдем и выведем максимальную реальную часть комплексных чисел массива а, а также выведем количество мнимых частей в массиве б
    int max_real = a[0];
    for(i = 0; i < 6; i +=2){
        if (a[i] > max_real){
            max_real = a[i];
        }
    }
    printf("%d\n", max_real);
    int mnim = 0;
    for (i = 1; i < 6; i+=2){
        if (b[i] < 0){
            mnim ++;
        }
    }
    printf("%d\n", mnim);
    double sum_real = 0, sum_mnim = 0;
    double sr = 0;
    for (int i = 0; i < 6; i += 2) {
         sum_real += c[i];
         sum_mnim += c[i + 1];
    }
    sr = (sum_real + sum_mnim) / 6;
    printf("%lf\n", sr);
}
