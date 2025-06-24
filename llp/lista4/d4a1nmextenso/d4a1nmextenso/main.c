#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Insira um número de 0-99999:\n");
    int nm, d1, d2, d3, d4, d5;
    scanf("%d", &nm);

    char *unidades[] = {"zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez", "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};

    char *dezenas[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};

    char *centenas[] = {"", "centos", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seissentos", "setecentos", "oitocentos", "novecentos"};

    d1 = nm / 10;
    d1 = d1 * 10;
    d1 = nm - d1;

    d2 = nm / 100;
    d2 = d2 * 100;
    d2 = nm - d2 - d1;

    d3 = nm / 1000;
    d3 = d3 * 1000;
    d3 = nm - d3 - d2 - d1;

    d4 = nm / 10000;
    d4 = d4 * 10000;
    d4 = nm - d4 - d3 - d2 - d1;

    d5 = nm / 100000;
    d5 = d5 * 100000;
    d5 = nm - d5 - d4 - d3 - d2 - d1;

    if (nm > 99999) {
        printf("ERRO: Número maior que 5 digitos");
    }
    else if (nm < 20) {
        printf("%s\n", unidades[nm]);
    } else {
        int unidadem = d4 / 1000;
        int dezenam = d5 / 10000;
        if ((nm >= 1000) && (nm <= 19999)) {
            if (unidadem != 0) {
                printf("%s mil ", unidades[unidadem]);
            }
        } else if (nm >= 20000) {
                printf("%s ", dezenas[dezenam]);
                if (d4 != 0) {
                    if (unidadem != 0){
                        printf("e %s mil ", unidades[unidadem]);
                } else {
                    printf(" mil ");
                        }
                }
            }
        }
        int centena = d3 / 100;
        int dezena = d2 / 10;
        int unidade = d1;
        if ((centena != 0) && (nm < 100000)){
            printf("%s", centenas[centena]);
            if (dezena != 0) {
                printf(" e %s", dezenas[dezena]);
                if (unidade != 0) {
                    printf(" e %s", unidades[unidade]);
                }
            }
        }

    return 0;
}
