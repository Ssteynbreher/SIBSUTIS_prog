#include <stdio.h>

int main() {
    int a;
    int i;

    printf("Введите число a: ");
    scanf("%d", &a);

    for (i = 2; i < a; i++) {
        if (a % i == 0) {
            break;
        }
    }

    if (i == a) {
        puts("Good");
    } else {
        puts("Not Good");
    }

}
