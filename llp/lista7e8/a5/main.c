#include <stdio.h>
#include <stdbool.h>

bool perfeito(int n, int j)
{
    int resultado;
    int divisores[25];
    for (int i = n - 1; i > 0; i--){
        if ((n % i) == 0) {
            divisores[j] = i;
            resultado += divisores[j];
            j++;
        }
    }
    if (resultado == n) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int num;
    printf("Insira um númeiro inteiro:\n");
    scanf("%d", &num);
    perfeito(num, 0) ? printf("o número é perfeito.\n") : printf("O número não é perfeito.\n");
    return 0;
}