#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double M[6][5], S[6][5];
    double maior;

    // Leitura da matriz M
    printf("Insira os elementos das matriz M[6][5]:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("M[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &M[i][j]);
        }
    }

    // Processando cada linha
    for (int i = 0; i < 6; i++) {
        // Encontrando o maior elemento da linha i
        maior = M[i][0];
        for (int j = 1; j < 5; j++) {
            if (M[i][j] > maior) {
                maior = M[i][j];
            }
        }

        // Dividindo os elementos da linha pelo maior elemento
        for (int j = 0; j < 5; j++) {
            S[i][j] = M[i][j] / maior;
        }
    }

    // Exibindo a matriz S
    printf("\nMatriz S[6][5] (elementos de M divididos pelo maior de cada linha):\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%.2lf\t", S[i][j]);
        }
        printf("\n");
    }

    return 0;
}