#include <stdio.h>

int main()
{
    printf("Informe o diametro do cilindro:\n");
    float r;
    scanf("%f", &r);
    r = r / 2.0;

    printf("Informe a altura do cilindro:\n");
    float h;
    scanf("%f", &h);

    float v = r * r * 3.14 * h;
    printf("%f", v);

    return 0;
}
