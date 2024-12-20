#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    // Sprawdzenie poprawności rozmiarów macierzy
    if (mat->r != mat->c || mat->r != b->r || b->c != 1 || x->r != b->r || x->c != 1) {
        return 2; 
    }
    // rozmiar macierzy
    int n = mat->r;
    for (int i = 0; i < n; i++) {
        x->data[i][0] = 0.0; 
    }
    // Algorytm wstecznego podstawienia
    for (int i = n - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0.0) {
            return 1; // Błąd: dzielenie przez 0
        }
	// Obliczamy wartość x[i]
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += mat->data[i][j] * x->data[j][0];
        }

        x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
    }
    return 0; // Sukces
}

