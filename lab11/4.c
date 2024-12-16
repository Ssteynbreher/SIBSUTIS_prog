#include <stdio.h> 

void swap(int* a, int* b) { // Функция для обмена значениями двух целых чисел, переданных по указателю
    int tmp = *a;       // Сохраняем значение, на которое указывает a, во временную переменную tmp
    *a = *b;           // Присваиваем значение, на которое указывает b, переменной a
    *b = tmp;           // Присваиваем значение из tmp переменной b
}

void bubble_sort(int* array, int size) { 
    for (int i = 0; i < size - 1; ++i) { 
        for (int j = 0; j < size - 1 - i; ++j) { // Поменяли i на на 1, теперь цикл заканчивается правильно, не пытаясь обратиться на элементу за пределами массива
            if (array[j] > array[j + 1]) { 
                swap(&array[j], &array[j + 1]); // Если элементы расположены не по порядку, вызываем swap для обмена.
            }
        }
    }
}

int main() { 
    int array[] = {5, 2, 8, 1, 9, 4}; 
    int size = sizeof(array) / sizeof(array[0]); 
    bubble_sort(array, size); 
    for (int i = 0; i < size; ++i) { 
        printf("%d ", array[i]);  
    }
    printf("\n"); 
    return 0;      
}


