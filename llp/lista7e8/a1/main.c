#include <stdio.h>
#include <stdbool.h>

bool parimpar(int x)
{
    int y = x % 2;
    if (y == 0){
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int x;
    printf("Insira um número inteiro:");
    scanf("%d", &x);
    bool ip = parimpar(x); 
    (ip == 1) ? printf("O número %d é par\n", x) : printf("o número %d é ímpar\n", x);
    return 0;
}