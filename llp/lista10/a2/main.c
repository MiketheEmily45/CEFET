#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double M[6][6];
    double N[6][6];
    double A;
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            printf("insira a variável da coluna %d linha %d:\n", i + 1, j + 1);
            scanf("%lf", &M[i][j]);
        }
    }
    printf("insira o valor que vai multiplicar todos:\n");
    scanf("%lf", &A);
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            N[i][j] = M[i][j] * A;
            printf("%lf ", N[i][j]);
        }
        printf("\n");
    }
    return 0;
}