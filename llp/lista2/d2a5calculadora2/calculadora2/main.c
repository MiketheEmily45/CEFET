#include <stdio.h>
#include <stdlib.h>

int main()
{
    float v1, v2, r;
    char c;
    printf("Insira o primeiro valor:\n");
    scanf("%f",&v1);
    printf("A conta que deseja fazer (- subtração, + adição, * multiplicação e / divisão):\n");
    scanf("%s", &c);
    printf("O segundo valor:\n");
    scanf("%f", &v2);


    if (c == '+') {
        r = v1 + v2;
    } else if (c == '-') {
        r = v1 - v2;
    } else if (c == '*') {
        r = v1 * v2;
    } else if (c == '/') {
        r = v1 / v2;
    }
    printf("o resultado é: %d\n", r);
    return 0;
}
