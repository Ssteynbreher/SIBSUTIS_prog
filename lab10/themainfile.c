#include "function.h" 
int main() {
    int M;
    printf("Введите количество парабол (M): ");
    if (scanf("%d", &M) != 1 || M <= 0) {
        fprintf(stderr, "Ошибка ввода!\n");
        return 1;
    }
    Parabola* parabolas = (Parabola*)malloc(M * sizeof(Parabola));
    if (parabolas == NULL) {
        fprintf(stderr, "Ошибка выделения памяти!\n");
        return 1;
    }
    for (int i = 0; i < M; i++) {
        printf("Введите коэффициенты a, b, c для параболы %d: ", i + 1);
        if (scanf("%lf %lf %lf", &parabolas[i].a, &parabolas[i].b, &parabolas[i].c) != 3) {
            fprintf(stderr, "Ошибка ввода!\n");
            free(parabolas);
            return 1;
        }
    }
    int k = 0;
    double max_min_y = DBL_MIN; 
    int max_min_index = -1;
    for (int i = 0; i < M; i++) {
        if (parabolas[i].a > 0) { 
            k++;
            double vertex_y = findVertexY(parabolas[i]);
            if (vertex_y > max_min_y) {
                max_min_y = vertex_y;
                max_min_index = i;
            }
        }
    }
    printf("Количество парабол с минимумом: %d\n", k);
    if (k > 0) {
        printf("Парабола с наибольшим минимумом (индекс %d): a=%.2lf, b=%.2lf, c=%.2lf, минимум = %.2lf\n", max_min_index, parabolas[max_min_index].a, parabolas[max_min_index].b, parabolas[max_min_index].c, max_min_y);
    }
    free(parabolas);
    return 0;
}