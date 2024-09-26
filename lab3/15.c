#include <stdio.h>

int main() {
    int a;
    int s = 0; 
    int n;

    printf("Введите число a: ");
    scanf("%d", &a);

    for (n = 2; n < a; n++) {
        if (a % n == 0) {
            s++; 
        }
    }

    if (s == 0) {
        puts("Good");
    } else {
        puts("Not Good");
    }

}
