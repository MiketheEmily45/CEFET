#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Insira um intervalo de números com o primeiro sendo o menor e o segundo o maior:\n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    while (b < a) {
     printf("Erro, o intervalo maior é menor que o intervalo menor, insira novamente:\n");
     scanf("%d", &b);
    }

    printf("Os números pares do intervalo são:\n");
    int x = a;
    while (x <= b) {
        if ((x % 2) == 0)
        {
            printf("%d\n", x);
        }
        x ++;
    }
    return 0;
}
