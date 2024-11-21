/*Умножить  в матрице квадрат, в левом нижнем углу которого расположен максимальный элемент, на число,  
равное количеству нулевых элементов в побочной диагонали. Заменить все отрицательные элементы матрицы на их модули.*/
#include <stdio.h>
#include <stdlib.h>

int** new_matrix(int n)  {
     int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        printf("Ошибка!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Ошибка!\n");
            exit(1);
        }
    }
    return matrix;
}

int count(int **matrix, int n){
    int zero_count = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[i][n - i - 1] == 0) {
            zero_count++;
        }
    }
    return zero_count;
}
int main() {
    int n;
    printf("Введите размер матрицы (n x n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка!\n");
        return 1; 
    }

    // Выделяем память для матрицы
    int **matrix = new_matrix(n);

    // Вводим элементы матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Находим максимальный элемент и его координаты
    int max_row = 0, max_col = 0, max_val = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    // Подсчитываем количество нулевых элементов в побочной диагонали
    
    int zero_count = count(matrix, n);

    // Умножаем квадрат в левом нижнем углу на число
    for (int i = max_row; i < n; i++) {
        for (int j = 0; j <= max_col; j++) {
            matrix[i][j] *= zero_count;
        }
    }
    // Заменяем отрицательные элементы на модули
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] = -matrix[i][j];
            }
        }
    }
    // Выводим полученную матрицу
    printf("Измененная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // Освобождаем память
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}