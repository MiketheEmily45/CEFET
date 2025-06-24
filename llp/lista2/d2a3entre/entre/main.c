#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Insira um número:\n");
    int n;
    scanf("%d", &n);

    if ((n >= 0) && (n <= 25)) {
        printf("O valor está entre 0 e 25\n");
    } else {
        printf("O valor não está entre 0 e 25\n");
    }

    if ((n >= 10) && (n <= 50)){
        printf("O valor está entre 10 e 50\n");
    } else {
        printf("O valor não está entre 10 e 50\n");
    }

    if ((n >= 20) && (n <= 100)){
        printf("O valor está entre 20 e 100\n");
    } else {
        printf("O valor não está entre 20 e 100\n");
    }
    return 0;
}
