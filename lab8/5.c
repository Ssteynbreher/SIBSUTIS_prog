#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double opr(double **matrix, int n) {
  if (n == 1) {
    return matrix[0][0];
  } else if (n == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    double det = 0;
    int sign = 1;
    for (int i = 0; i < n; i++) {
      double **minor = malloc((n - 1) * sizeof(double *));
      for (int j = 0; j < n - 1; j++) {
        minor[j] = malloc((n - 1) * sizeof(double));
      }
      int row = 0, col = 0;
      for (int k = 1; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if (l != i) {
            minor[row][col++] = matrix[k][l];
          }
        }
        row++;
        col = 0;
      }
      det += sign * matrix[0][i] * opr(minor, n - 1);
      sign *= -1;
      for (int j = 0; j < n - 1; j++) {
        free(minor[j]);
      }
      free(minor);
    }
    return det;
  }
}
void solve_system(double **A, double *b, int n) {
  double detA = opr(A, n);
  double *detAi = malloc(n * sizeof(double));
  for (int i = 0; i < n; i++) {
    double **Ai = malloc(n * sizeof(double *));
    for (int j = 0; j < n; j++) {
      Ai[j] = malloc(n * sizeof(double));
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        Ai[j][k] = A[j][k];
      }
    }
    for (int j = 0; j < n; j++) {
      Ai[j][i] = b[j];
    }
    detAi[i] = opr(Ai, n);
    for (int j = 0; j < n; j++) {
      free(Ai[j]);
    }
    free(Ai);
  }
  double *x = malloc(n * sizeof(double));
  for (int i = 0; i < n; i++) {
    x[i] = detAi[i] / detA;
  }
  printf("Решение системы:\n");
  for (int i = 0; i < n; i++) {
    printf("x%d = %.2f\n", i + 1, x[i]);
  }
  free(detAi);
  free(x);
}
int main() {
  int n;
  printf("Введите размерность системы уравнений: ");
  scanf("%d", &n);
  double **A = malloc(n * sizeof(double *));
  for (int i = 0; i < n; i++) {
    A[i] = malloc(n * sizeof(double));
  }
  printf("Введите коэффициенты матрицы A:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("A[%d][%d] = ", i, j);
      scanf("%lf", &A[i][j]);
    }
  }
  double *b = malloc(n * sizeof(double));

  printf("Введите свободные члены b:\n");
  for (int i = 0; i < n; i++) {
    printf("b[%d] = ", i);
    scanf("%lf", &b[i]);
  }
  solve_system(A, b, n);
  for (int i = 0; i < n; i++) {
    free(A[i]);
  }
  free(A);
  free(b);
}