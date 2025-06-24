#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("informe os valores de a, b e x com x sendo o maior lado:\n");
    float a, b, x;
    scanf("%f %f %f", &a, &b, &x);
    bool tf;

    if (a + b >= x) {
        tf = true;
    } else {
        tf = false;
    }

    printf("O triangulo e valido? %s", tf ? "Verdadeiro" : "Falso");

    return 0;
}
