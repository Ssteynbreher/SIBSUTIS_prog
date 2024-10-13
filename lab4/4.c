#include <stdio.h>

int main() {
    int n;
    printf("Введите размер: ");
    scanf("%d", &n);

    int a = 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a);
            a++; 
        }
        printf("\n");
    }

}

