#include <stdio.h>

int main()
{
    printf("Informe o coeficiente angular:\n");
    int a;
    scanf("%d", &a);

    printf("Informe o coeficiente linear:\n");
    int b;
    scanf("%d", &b);

    printf("Informe o valor de x:\n");
    int x;
    scanf("%d", &x);

    float f;
    f = a * x + b;
    printf("%f", f);

    return 0;
}
