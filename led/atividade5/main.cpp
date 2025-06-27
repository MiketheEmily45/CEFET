#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int TAM = 20;

void gerarVetor(int v[]){
    for(int i = 0; i < TAM; i++) {
        v[i] = rand() % 100 + 1;
    }
}

void copiarVetor(int v[], int vc[]){
    for(int i = 0; i < TAM; i++) {
        vc[i] = v[i];
    }
}

void imprimirVetor(int v[]){
    for(int i = 0; i < TAM; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void BolhaMelhorado( int vet[], int* compare, int* change) {
    int i = 1, j, aux;
    (*compare) = 0;
    (*change) = 0;
    bool troca = true;
    while ((i <= TAM) && (troca)){
        troca = false ;
        for(j = 0; j < TAM -1; j++) {
            (*compare)++;
            if(vet[j] > vet[j + 1]) {
                troca = true;
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                (*change)++;
            }
        }
        i++;
    }
}

void Insertion( int vet[], int* compare, int* change) {
    int i, j, eleito;
    (*compare) = 0;
    (*change) = 0;
    for( i = 1; i < TAM; i++) {
        eleito = vet [i];
        j = i - 1;
        (*compare)++;
        while ((j >= 0) && (vet[j] > eleito)) {
            vet[j + 1] = vet[j];
            j--;
            (*change)++;
        }
        vet[j + 1] = eleito;

    }
}

void Selection( int vet[], int* compare, int* change) {
    int i, j, eleito, menor, pos;
    (*compare) = 0;
    (*change) = 0;
    for(i = 0;i < TAM -1;i ++) {
        eleito = vet[i];
        menor = vet[i + 1];
        pos = i + 1;
        for(j = i +2; j < TAM ; j++) {
            if(vet[j] < menor) {
                menor = vet[j];
                pos = j;
            }
            (*compare)++;
        }
        if(menor < eleito){
            vet[i] = vet[pos];
            vet[pos] = eleito;
            (*change)++;
        }
    }
}

int main()
{
    srand(time(NULL));
    int vetOri[TAM], vetCop[TAM], comp, trocas, mtb = 0, mcb = 0, mti = 0, mci = 0, mts = 0, mcs = 0;

    for(int i = 1; i <= 10; i++){
        gerarVetor(vetOri);
        copiarVetor(vetOri, vetCop);
        cout << "vetor original:" << endl;
        imprimirVetor(vetOri);
        comp = 0;
        trocas = 0;
        BolhaMelhorado(vetCop, &comp, &trocas);
        mcb += comp;
        mtb += trocas;
        cout << "vetor pós método bolha melhorado:" << endl;
        imprimirVetor(vetCop);
        cout << "quantidade de comparações: " << comp << endl;
        cout << "quantidade de trocas: " << trocas << endl;
        copiarVetor(vetOri, vetCop);
        comp = 0;
        trocas = 0;
        Insertion(vetCop, &comp, &trocas);
        mci += comp;
        mti += trocas;
        cout << "vetor pós método de inserção:" << endl;
        imprimirVetor(vetCop);
        cout << "quantidade de comparações: " << comp << endl;
        cout << "quantidade de trocas: " << trocas << endl;
        copiarVetor(vetOri, vetCop);
        comp = 0;
        trocas = 0;
        Selection(vetCop, &comp, &trocas);
        mcs += comp;
        mts += trocas;
        cout << "vetor pós método de Seleção:" << endl;
        imprimirVetor(vetCop);
        cout << "quantidade de comparações: " << comp << endl;
        cout << "quantidade de trocas: " << trocas << endl;
    }
    mcs /= 10;
    mts /= 10;
    mci /= 10;
    mti /= 10;
    mcb /= 10;
    mtb /= 10;

    cout << "média de comparações do método de seleção: " << mcs << endl;
    cout << "média de trocas do método de seleção: " << mts << endl;
    cout << "média de comparações do método de inserção: " << mci << endl;
    cout << "média de trocas do método de inserção: " << mti << endl;
    cout << "média de comparações do método bolha: " << mcb << endl;
    cout << "média de trocas do método bolha: " << mtb << endl;

    return 0;
}
