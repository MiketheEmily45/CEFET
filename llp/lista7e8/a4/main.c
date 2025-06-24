#include <stdio.h>
#include <stdbool.h>

int diasdevida(int anos, int meses, int dias){
    int ddv = (anos * 365) + (meses * 31) + dias;
    return ddv;
}

int main()
{
    int anos, dias, meses;
    printf("Insira os anos, meses e dias de vida que você tem até hoje, em ordem separados por vírgula e espaço:");
    scanf("%d, %d, %d", &anos, &meses, &dias);
    int ddv = diasdevida(anos, meses, dias);
    printf("você tem %d dias de vida", ddv);
    return 0;
}