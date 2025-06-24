#include <stdio.h>

double media(double a, double b, double c, char p)
{
    double d, e;
    switch(p)
    {
        case 'A':
            d = (a + b + c) / 3;
            return d;
            break;
        case 'P':
            e = ((5 * a) + (3 * b) + (2 * c)) / 10;
            return e;
            break;
        default:
            printf("Opção inválida.\n");
            return 0;
            break;
    }
}

int main()
{
    double a, b, c;
    char pa;
    printf("Se você quer calcular a média aritmética, digite 'A', se quer a média ponderada com pesos 5, 3 e 2 respectivamente, digite 'P':\n");
    scanf(" %c", &pa);
    printf("Insira a primeira nota:\n");
    scanf("%lf", &a);
    printf("Insira a segunda nota:\n");
    scanf("%lf", &b);
    printf("Insira a terceira nota:\n");
    scanf("%lf", &c);
    printf("O resultado é %lf\n", media(a, b, c, pa));
    return 0;
}