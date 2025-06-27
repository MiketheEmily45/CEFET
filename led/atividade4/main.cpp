#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int matriz[12][12], soma1 = 0, soma2 = 0, soma3 = 0;
    double media;

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            matriz[i][j] = 1 + (rand() % 9);
        }
    }
    for(int i = 0; i < 12; i++) {
        for(int j = i + 1; j < 12; j++) {
            soma1 += matriz[i][j];
        }

    }
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < i; j++) {
            soma2 += matriz[i][j];
            soma3++;
        }
    }

    media = soma2 / soma3;

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "A soma acima da diagonal principal é: " << soma1 << "\nA média aritmética de abaixo da diagonal principal é: " << media << endl;

    return 0;
}
