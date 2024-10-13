#include <stdio.h>
int main() {
    int v;
    int h;
    printf("Введите высоту: ");
    scanf("%d", &v);
    printf("Введите ширину: ");
    scanf("%d", &h);

    for (int i = 0; i < v; i++) {
        printf("* ");
    }
    printf("\n");

    for (int i = 0; i < h; i++) {
        printf("*");
        for (int j = 0; j < v - 2; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    for (int i = 0; i < v; i++) {
        printf("* ");
    }
    printf("\n");

}


