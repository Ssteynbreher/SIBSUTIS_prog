#include <stdio.h>

int main() {
    int n;
    int s=1;
    printf("Степень двойки: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        s = s * 2;
    }
    printf("Итог: %d\n", s);
}
