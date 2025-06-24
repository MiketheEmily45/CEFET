#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double M[5][5];
    double N[5][5];
    double Soma[5][5];
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 4; j++){
            printf("insira a variável M da coluna %d linha %d:\n", i + 1, j + 1);
            scanf("%lf", &M[i][j]);
        }
    }
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 4; j++){
            printf("insira a variável N da coluna %d linha %d:\n", i + 1, j + 1);
            scanf("%lf", &N[i][j]);
        }
    }
   for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 4; j++){
            Soma[i][j] = M[i][j] + N[i][j];
            printf("%lf ", Soma[i][j]);
        }
        printf("\n");
    }
    return 0;
}