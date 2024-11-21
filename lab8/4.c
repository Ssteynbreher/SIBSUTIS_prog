#include <stdio.h>
// Функция для вычисления определителя матрицы 2x2
int determinant2x2(int a11, int a12, int a21, int a22) {
  return a11 * a22 - a12 * a21;
}
// Функция для вычисления определителя матрицы 3x3
int determinant3x3(int a11, int a12, int a13,
                   int a21, int a22, int a23,
                   int a31, int a32, int a33) {
  return a11 * determinant2x2(a22, a23, a32, a33) -
         a12 * determinant2x2(a21, a23, a31, a33) +
         a13 * determinant2x2(a21, a22, a31, a32);
}
int main() {
  int N;
  printf("Введите размер системы уравнений (от 2 до 3): ");
  scanf("%d", &N);
   int A[3][3], b[3];
  // Ввод коэффициентов системы уравнений
  printf("Введите коэффициенты матрицы A:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  printf("Введите свободные члены b:\n");
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }
  // Вычисление определителя основной матрицы
  int detA;
  if (N == 2) {
    detA = determinant2x2(A[0][0], A[0][1], A[1][0], A[1][1]);
  } else {
    detA = determinant3x3(A[0][0], A[0][1], A[0][2],
                           A[1][0], A[1][1], A[1][2],
                           A[2][0], A[2][1], A[2][2]);
  }
  // Решение системы уравнений по методу Крамера
  int detX[3];
  for (int i = 0; i < N; i++) {
    // Создание временной матрицы для вычисления определителя
    int tempA[3][3];
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        tempA[j][k] = A[j][k];
      }
    }
    // Замена i-го столбца матрицы на вектор свободных членов
    for (int j = 0; j < N; j++) {
      tempA[j][i] = b[j];
    }
    // Вычисление определителя временной матрицы
    if (N == 2) {
      detX[i] = determinant2x2(tempA[0][0], tempA[0][1], tempA[1][0], tempA[1][1]);
    } else {
      detX[i] = determinant3x3(tempA[0][0], tempA[0][1], tempA[0][2],
                               tempA[1][0], tempA[1][1], tempA[1][2],
                               tempA[2][0], tempA[2][1], tempA[2][2]);
    }
  }
  // Вывод решения
  printf("Решение системы уравнений:\n");
  for (int i = 0; i < N; i++) {
    printf("x%d = %d\n", i + 1, detX[i] / detA);
  }

  return 0;
}