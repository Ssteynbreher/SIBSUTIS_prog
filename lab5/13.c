#include <stdio.h>
int two(int n){
    if (n==0){
        return 0;
    }
    return (n&(n-1))==0;
}
int main(){
    int n;
    printf("Введите число: \n");
    scanf("%d", &n);
    if (two(n)){
        printf("Является степенью двойки\n");
    } else{
        printf("Не является степенью двойки\n");
    }

}
//10000
//01111
//00000