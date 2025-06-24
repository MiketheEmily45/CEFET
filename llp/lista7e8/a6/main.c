#include <stdio.h>

int contagem(int n, int s)
{
    if (s <= n){
        printf("%d ", s);
    }
    return contagem(n, s + 1);
}

int main()
{
    int n;
    printf("insira um número:\n");
    scanf("%d", &n);
    contagem(n, 0);
    return 0;
}