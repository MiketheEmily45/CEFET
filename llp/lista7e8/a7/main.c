#include <stdio.h>

int soma(int n)
{
    if (n > 0){
        n = n + soma(n - 1);
    }
    return n;
}

int main()
{
    int n;
    printf("Insira um número:\n");
    scanf("%d", &n);
    printf("%d", soma(n));
    return 0;
}