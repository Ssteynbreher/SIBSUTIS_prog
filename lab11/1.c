#include <stdio.h> 
#include <stdlib.h> 

void init(int** arr, int n) //инициализация массива Принимает указатель на указатель на int (для изменения указателя в вызывающей функции) и размер массива.
{
    *arr = malloc(n * sizeof(int)); // Выделение памяти для массива из n элементов типа int. Результат присваивается по адресу, на который указывает arr (изменение исходного указателя в вызывающей функции).
    if (*arr == NULL) { // Проверка на успешность выделения памяти. malloc возвращает NULL при ошибке.
        fprintf(stderr, "Ошибка выделения памяти!\n"); 
        exit(1); 
    }
    for (int i = 0; i < n; ++i) { // 
        (*arr)[i] = i; // Присваивание значений элементам массива
    }
}
int main() { 
    int* arr = NULL; // Объявление указателя на int
    int n = 10; 
    init(&arr, n); // Вызов функции init для инициализации массива. Передаем адрес указателя
    for (int i = 0; i < n; ++i) { 
        printf("%d\n", arr[i]); 
    }
    free(arr); 
    return 0; 
}
