#include <stdio.h>
#include <stdbool.h>

int contagem(int n)
{
    if (n >= 0){
        printf("%d ", n);
    }
     return contagem(n - 1);
}

int main()
{
    int n;
    printf("insira um número:\n");
    scanf("%d", &n);
    contagem(n);
    return 0;
}