//Вариант13
#include <stdio.h>
#include <stdlib.h>
//Простое число
int p(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
//Обратный порядок
int rev(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}
//Удалние максимального элемента
void rem(int* arr, int* size) {
    int max_index = 0;
    for (int i = 1; i < *size; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    for (int i = max_index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
int main() {
    int F[] = {456,12,1234,234,7,23,30}; 
    int n = sizeof(F) / sizeof(F[0]);
    int count_before = 0;
    for (int i = 0; i < n; i++) {
        if (p(F[i])) count_before++;
    }
    for (int i = 0; i < n; i++) {
        F[i] = rev(F[i]);
    }
    int count_after = 0;
    for (int i = 0; i < n; i++) {
        if (p(F[i])) count_after++;
    }
    rem(F, &n);
    printf("Количество простых чисел до преобразования: %d\n", count_before);
    printf("Количество простых чисел после преобразования: %d\n", count_after);
    printf("Массив после удаления максимального элемента:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", F[i]);
    }
    printf("\n");
}