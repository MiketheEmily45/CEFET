#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double M[7][4];
    double menor;
    int posicaox, posicaoy;
    for(int i = 0; i <= 6; i++){
        for(int j = 0; j <= 3; j++){
            printf("insira a variável M da coluna %d linha %d:\n", i + 1, j + 1);
            scanf("%lf", &M[i][j]);
        }
    }
    menor = M[0][0];
    posicaox = 0;
    posicaoy = 0;
    for(int i = 0; i <= 6; i++){
        for(int j = 0; j <= 3; j++){
            if(M[i][j] < menor){
                menor = M[i][j];
                posicaox = i;
                posicaoy = j;
            }
        }
    }
    printf("O menor valor é %lf, sua posição é coluna %d linha %d\n", menor, posicaox, posicaoy);
    return 0;
}