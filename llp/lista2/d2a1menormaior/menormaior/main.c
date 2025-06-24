#include <stdio.h>

int main()
{
    printf("insira 3 números:\n");
    float a, b, c, menor, maior;
    scanf("%f %f %f", &a, &b, &c);

    if((a >= b) && (a >= c))
    {
        maior = a;
    }
    if((b >= a) && (b >= c))
    {
        maior = b;
    }
    if ((c >= a) && (c >=b))
    {
        maior = c;
    }

    if ((a <= b) && (a <= c))
    {
        menor = a;
    }
    if ((b <= a) && (b <= c))
    {
        menor = b;
    }
    if ((c <= a) && (c <= b))
    {
        menor = c;
    }

    printf("o maior é %.2f e o menor é %.2f\n", maior, menor);
    return 0;
}
