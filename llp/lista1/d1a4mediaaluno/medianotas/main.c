#include <stdio.h>

int main()
{
    char nome[50];
    printf("Informe o nome do aluno:\n");
    scanf("%s", nome);

    printf("Informe a primeira nota do aluno:\n");
    float a;
    scanf("%f", &a);

    printf("Informe a segunda nota do aluno:\n");
    float b;
    scanf("%f", &b);

    printf("Informe a terceira nota do aluno:\n");
    float c;
    scanf("%f", &c);

    float d = (a + b + c) / 3.0;
    printf("A média do aluno %s é %f", nome, d
    );
    return 0;

}
