#include <stdio.h>
int main() {
  int N;
  printf("Введите размер матрицы (от 1 до 3): ");
  scanf("%d", &N);
  int mat[3][3];
  printf("Введите элементы матрицы:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &mat[i][j]);
    }
  }
  printf("Матрица:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  int opr = 0;
  if (N == 2) {
    opr = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
  } else if (N == 3) {
    opr = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1] -
          mat[0][2] * mat[1][1] * mat[2][0] - mat[0][1] * mat[1][0] * mat[2][2] - mat[0][0] * mat[1][2] * mat[2][1];
  } else {
    opr = mat[0][0];
  }
  printf("Определитель матрицы: %d\n", opr);
}