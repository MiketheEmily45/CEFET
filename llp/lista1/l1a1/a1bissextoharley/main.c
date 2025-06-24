#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ache os anos bissextos que tem em um intervalo de anos, e de quantos em quantos anos passa um cometa na terra em ano que é bissexto
    int anoi, anof, ic, anoic;
    printf("insira o ano inicial:\n");
    scanf("%d", &anoi);
    printf("insira o ano final:\n");
    scanf("%d", &anof);
    printf("insira de quantos em quantos anos o cometa passa:\n");
    scanf("%d", &ic);
    printf("insira o primeiro ano de aparecimento do cometa:\n");
    scanf("%d", &anoic);

    printf("Os anos que são bissextos e que o cometa passa são:\n");

    int ano = anoi;
    int bis, icr;
    do {
        bis = ano % 4;
        icr = (ano - anoic) % ic;
        if ((bis == 0) && (icr == 0)) {
            printf ("%d\n", ano);
        }
        ano ++;
    } while (ano <= anof);

    return 0;
}
