#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int matriz[5][6];
    int soma_pares = 0;
    int quantidade_pares = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            matriz[i][j] = rand() % 16;
            if (matriz[i][j] % 2 == 0) {
                soma_pares += matriz[i][j];
                quantidade_pares++;
            }
        }
    }
    double media_pares = 0.0;
    if (quantidade_pares > 0) {
        media_pares = (double)soma_pares / quantidade_pares;
    }
    printf("\nA média dos valores pares na matriz é: %.2f\n", media_pares);
    return 0;
}