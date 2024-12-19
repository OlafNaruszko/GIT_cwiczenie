#include "gauss.h"
#include <stdio.h>
#include <math.h>

int eliminate(Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r) {
        fprintf(stderr, "Błąd: Nieprawidłowe rozmiary macierzy.\n");
        return 1;
    }

    int n = mat->r;
    for (int k = 0; k < n - 1; k++) {
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[maxRow][k])) {
                maxRow = i;
            }
        }

        if (maxRow != k) {
            for (int j = 0; j < n; j++) {
                double temp = mat->data[k][j];
                mat->data[k][j] = mat->data[maxRow][j];
                mat->data[maxRow][j] = temp;
            }
            double tempB = b->data[k][0];
            b->data[k][0] = b->data[maxRow][0];
            b->data[maxRow][0] = tempB;
        }

        if (fabs(mat->data[k][k]) < 1e-12) {
            fprintf(stderr, "Błąd: Dzielenie przez zero przy elemencie [%d][%d].\n", k, k);
            return 1;
        }

        for (int i = k + 1; i < n; i++) {
            double multipler = mat->data[i][k] / mat->data[k][k];
            for (int j = k; j < n; j++) {
                mat->data[i][j] -= multipler * mat->data[k][j];
            }
            b->data[i][0] -= multipler * b->data[k][0];
        }
    }

    return 0;
}
