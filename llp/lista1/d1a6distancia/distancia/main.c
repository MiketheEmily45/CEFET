#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Informe o primeiro número:\n");
    int a;
    scanf("%d", &a);

    printf("Informe o segundo número:\n");
    int b;
    scanf("%d", &b);

    int c;
    c = a - b;
    if (c<0)
    c = c * -1;
    printf("a distância entre eles é %d", c);

    return 0;
}
