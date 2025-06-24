#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Insira o salário do funcionrio\n");
    float s;
    scanf("%f", &s);

    if (s <= 1500.0) {
        s = s * 1.15;
    } else if (s <= 3000) {
        s = s *1.10;
    } else if (s > 3000) {
        s = s * 1.05;
    }
    printf("O novo salário será %f", s);
    return 0;
}
