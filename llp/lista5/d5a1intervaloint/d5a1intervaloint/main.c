#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Insira os valores a e b:\n");
    int a, b;
    scanf("%d %d", &a, &b);

    while (b < a) {
        printf("por favor insira o valor b sendo maior que a:\n");
        scanf("%d", &b);
    }

    printf("insira o valor de z:");
    int x, y, z;
    scanf("%d", &z);

    while (z <= b) {
        printf("por favor insira o valor de z sendo maior que b:");
        scanf("%d", &z);
    }

    if ((z % 2) == 0){
        x = z / 2;
        y = x - 1;
        x = x + 1;
    }
    else {
        x = z / 2;
        y = x + 1;
    }
    printf("%d é x e %d é y", x, y);
    return 0;
}
