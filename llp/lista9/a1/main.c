#include <stdio.h>

int main() {
    int valor[15];
    int i;

    for (i = 0; i < 15; i++) {
        printf("Entre o %dº número: ", i + 1);
        scanf("%d", &valor[i]);
    }

    int soma = 0;
    int maior = valor[0];
    int menor = valor[0];

    for (i = 0; i < 15; i++) {
        soma += valor[i];

        if (valor[i] > maior) {
            maior = valor[i];
        }

        if (valor[i] < menor) {
            menor = valor[i];
        }
    }

    int media = soma / 15.0;

    printf("Valores inseridos:\n");
    for (i = 0; i < 15; i++) {
        printf("%d ", valor[i]);
    }
    printf("\n");

    printf("Média: %d\n", media);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}