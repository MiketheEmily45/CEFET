#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int existe(int num[], int tamanho, int valor) {
    int i;
    for(i=0;i<tamanho;i++) {
        if (num[i] == valor) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int num[6];
    int i, valor;
    for (i = 0; i < 6; i++){
        do {
            valor = 1 + rand() % 60;
        } while (existe(num, i, valor));

        num[i] = valor;
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}