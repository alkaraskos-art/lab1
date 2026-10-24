#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // vvod s proverkoi
    printf("Введите количество строк (n): ");
    if (scanf("%d", &n) != 1 ||  n <= 2) {
        printf("Ошибка: неверное число строк.\n");
        return 1;
    }

    printf("Введите количество столбцов (m): ");
    if (scanf("%d", &m) != 1 || m <= 2) {
        printf("Ошибка: неверное число столбцов.\n");
        return 1;
    }
    if (m <= 2 || n <= 2) {
	printf("error\n");
	return 1;
    }



    // videlpamyat
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти под строку %d.\n", i);
            // freeeeee
            for (int k = 0; k < i; k++) free(matrix[k]);
            free(matrix);
            return 1;
        }
    }

    //  vvod
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (1) {
                printf("matrix[%d][%d] = ", i, j);
                if (scanf("%d", &matrix[i][j]) == 1) {
                    break;
                } else {
                    printf("Ошибка: введите целое число.\n");
                    //trash
                    while (getchar() != '\n');
                }
            }
        }
    }

    int sumot = 0;
    int maxi = -100000;

    // sumout
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < 0 && j > i) {
                sumot += matrix[i][j];
            }
        }
    }
    printf("Сумма отрицательных элементов над главной диагональю: %d\n", sumot);

    // poisk
    maxi = matrix[2][0];
    for (int j = 1; j < m; j++) {
        if (matrix[2][j] > maxi) {
            maxi = matrix[2][j];
        }
    }

    // zamena
    for (int j = 0; j < m; j++) {
        if (matrix[2][j] == maxi) {
            matrix[2][j] = sumot;
            break;
        }
    }

    // vivodi
    printf("\nИзменённая матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }

    // free#2
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
