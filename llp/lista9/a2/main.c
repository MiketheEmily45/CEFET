#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    srand(time(NULL));
    int tam, guess;
    bool gtf;
    printf("Insira um tamanho de vetor de 1 a 50:\n");
    scanf("%d", &tam);
    int nums[tam];
    if ((tam >= 1) && (tam <= 50)){
        printf("Insira um possível valor:\n");
        scanf("%d", &guess);
        for (tam; tam >= 0; tam--){
            nums[tam] = rand();
            printf("%d\n", nums[tam]);
            if (nums[tam] == guess){
                gtf = true;
            }
        }
        gtf ? printf("Valor encontrado") : printf("Valor não encontrado");
    } else {
        printf("Erro, valor não é entre 1 a 50.");
    }
    return 0;
}