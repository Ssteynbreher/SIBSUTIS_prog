#include <stdio.h>
int main() {
    int a, n;
    printf("Введите число a: ");
    scanf("%d", &a);

    for (n = 2; n < a; n++) {
        if (a % n == 0) {
            break; 
        }
    }

    if (n == a) {
        puts("Good");
    } else {
        puts(" ");
    }

}


