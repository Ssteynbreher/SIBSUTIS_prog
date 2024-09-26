#include <stdio.h>

int main() {
    int b, n = 2, flag = 0;

    printf("Введите число b: ");
    scanf("%d", &b);

    if (b < 2) {
        printf("Число должно быть больше или равно 2.\n");
        return 0;
    }

    while (b % n != 0) {
        n++;
        if (n == b) {
            flag = 1; 
            break;
        }
    }

    if (flag == 1) {
        printf("%d является простым числом\n", b);
    } else {
        printf("%d не является простым числом\n", b);
    }
}
