#include <stdio.h>

int main()
{
    printf("Informe a base do triângulo:\n");
    float b;
    scanf("%f", &b);

    printf("Informe a altura do triângulo:\n");
    float h;
    scanf("%f", &h);

    float a;
    a = (b * h) / 2.0;
    printf("%f", a);

    return 0;
}
