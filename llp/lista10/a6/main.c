#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double M[6][6];
    double N[6][6];
    double PROD[6][6];
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            printf("insira a variável M da coluna %d linha %d:\n", i + 1, j + 1);
            scanf("%lf", &M[i][j]);
        }
    }
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            printf("insira a variável N da coluna %d linha %d:\n", i + 1, j + 1);
            scanf("%lf", &N[i][j]);
        }
    }
   for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            PROD[i][j] = M[i][j] * N[i][j];
            printf("%lf ", PROD[i][j]);
        }
        printf("\n");
    }
    return 0;
}