#include "gauss.h"
#include <stdio.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	if (mat->r != mat->c || mat->r != b->r) {
        printf("[!] Nieprawidłowe rozmiary macierzy.\n");
        return 1;
    }

    int n = mat->r;
    for (int k = 0; k < n - 1; k++) {
        if (fabs(mat->data[k][k]) < 1e-12) {
            printf("[!] Dzielenie przez zero przy elemencie [%d][%d].\n", k, k);
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

