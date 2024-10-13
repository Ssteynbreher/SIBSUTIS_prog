#include <stdio.h>
int bin(unsigned int n){
    int k=0;
    while (n){
        k += n & 1;
        n >>= 1;
    }
    return k;
    }
    // 5 0000000000010
    //   0000000000001
    //   0000000000001
int main(){
    unsigned int n;
    printf("Введите неотрицательное число: \n");
    scanf("%d", &n);
    int k = bin(n);
    printf("Количество битов в %d: %d\n", n, k);
  return 0;
}