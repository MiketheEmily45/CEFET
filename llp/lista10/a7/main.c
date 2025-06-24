#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int M[6][6];

    // Leitura da matriz
    printf("Insira os elementos da matriz 6x6:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("M[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &M[i][j]);
        }
    }

    // Realizando as trocas de colunas
    for (int i = 0; i < 6; i++) {
        // Trocando primeira com segunda coluna
        int temp = M[i][0];
        M[i][0] = M[i][1];
        M[i][1] = temp;

        // Trocando terceira com quarta coluna
        temp = M[i][2];
        M[i][2] = M[i][3];
        M[i][3] = temp;

        // Trocando quinta com sexta coluna
        temp = M[i][4];
        M[i][4] = M[i][5];
        M[i][5] = temp;
    }

    // Exibindo a matriz após as trocas
    printf("\nMatriz após as trocas:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}