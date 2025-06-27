#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Divisores.h"

//código possui problema na implementação da classe, no caso é na inserção na Pilha e na Fila, o elo não está recebendo o "caminho" para a próxima Pilha ou Fila.

using namespace std;

int main()
{
    srand(time(NULL));

    Divisores *NP = new Divisores();
    Divisores *NF = new Divisores();
    Divisores *MP = new Divisores();
    Divisores *MF = new Divisores();
    int numN, numM;
    char next;
    do{
        numN = (rand() % 90) + 10;
        numM = (rand() % 90) + 10;
        for(int i = 1; i < numN; i++) {
            if(numN % i == 0) {
                NP->InserirPilha(NP, i);
                NF->InserirFila(NF, i);
            }
        }
        for(int i = 1; i < numM; i++) {
            if(numM % i == 0) {
                MP->InserirPilha(MP, i);
                MF->InserirFila(MF, i);
            }
        }
        cout << "Primeiro Número gerado: " << numN << "\n" << endl;
        cout << "Divisores(Ordem crescente): ";
        NF->PercorrerFila(NF);
        cout << "Divisores(Ordem decrescente): ";
        NP->PercorrerPilha(NP);
        cout << endl;

        NF->RemoverFilaCompleto(NF);
        NP->RemoverPilhaCompleto(NP);

        cout << "Segundo Número gerado: " << numM << "\n" << endl;
        cout << "Divisores(Ordem crescente): ";
        MF->PercorrerFila(MF);
        cout << "Divisores(Ordem decrescente): ";
        MP->PercorrerPilha(MP);
        cout << endl;

        MF->RemoverFilaCompleto(MF);
        MP->RemoverPilhaCompleto(MP);


        cout << "Deseja executar novamente?" << endl;
        cin >> next;
    }while(next == 'S' || next == 's');
    return 0;
}
