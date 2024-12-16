#include <stdio.h>

#define SQR(x) ((x) * (x)) // Используем скобки для правильного порядка операций
int main() {
    int y = 5;
    int z = SQR(y + 1);
    printf("z = %d\n", z);
    return 0;
}

// при x * x будет выраженеи у + 1 * у + 1
// при ((x) * (x)) будет выражение (y + 1) * (y + 1)