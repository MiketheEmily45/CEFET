#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int vet[50];

    for(int i; i < 50; i++){
        do {
            vet[i] = (rand() % 100) + 1;
        } while ((vet[i] % 2) != 0);
    }
    cout << "Números gerados: " << endl;
    for(int i; i < 50; i++){
        if (vet[i] != NULL) {
            cout << vet[i] << " ";
        } else {
            cerr << "Primeiro você deve gerar o vetor" << endl;
        }
    }
    cout << endl;
    cout << "Números maiores que 50 gerados: " << endl;
    for(int i; i < 50; i++){
        if (vet[i] != NULL) {
            if (vet[i] > 50) {
                cout << vet[i] << " ";
            }
        } else {
            cerr << "Primeiro você deve gerar o vetor" << endl;
        }
    }
    cout << endl;
    cout << "Números múltiplos de 6 gerados: " << endl;
    for(int i; i < 50; i++){
        if (vet[i] != NULL) {
            if ((vet[i] % 6) == 0) {
                cout << vet[i] << " ";
            }
        } else {
            cerr << "Primeiro você deve gerar o vetor" << endl;
        }
    }


    cout << endl;

    return 0;
}
