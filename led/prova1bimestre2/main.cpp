#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Divisores.h"

//código possui problema na implementação da classe, no caso é na inserção na Pilha e na Fila, o elo não está recebendo o "caminho" para a próxima Pilha ou Fila.

using namespace std;

int main()
{
    srand(time(NULL));

    Divisores P;
    Divisores F;
    Divisores *NP = NULL;
    Divisores *INF = NULL;
    Divisores *IMF = NULL;
    Divisores *NF = NULL;
    Divisores *MP = NULL;
    Divisores *MF = NULL;
    int numN, numM;
    char next;
    do{
        numN = (rand() % 90) + 10;
        numM = (rand() % 90) + 10;
        for(int i = 1; i < numN; i++) {
            if(numN % i == 0) {
                NP = P.InserirPilha(NP, i);
                NF = F.InserirFila(NF, i);
                if(INF == NULL) INF = NF;
            }
        }
        for(int i = 1; i < numM; i++) {
            if(numM % i == 0) {
                MP = P.InserirPilha(MP, i);
                MF = MF->InserirFila(MF, i);
                if(IMF == NULL) IMF = MF;
            }
        }
        cout << "Primeiro Número gerado: " << numN << "\n" << endl;
        cout << "Divisores(Ordem crescente): ";
        F.PercorrerFila(INF);
        cout << "Divisores(Ordem decrescente): ";
        P.PercorrerPilha(NP);
        cout << endl;

        NF = NF->RemoverFilaCompleto(NF);
        NP = P.RemoverPilhaCompleto(NP);
        INF = NULL;

        cout << "Segundo Número gerado: " << numM << "\n" << endl;
        cout << "Divisores(Ordem crescente): ";
        F.PercorrerFila(IMF);
        cout << "Divisores(Ordem decrescente): ";
        P.PercorrerPilha(MP);
        cout << endl;

        MF = MF->RemoverFilaCompleto(MF);
        MP = P.RemoverPilhaCompleto(MP);
        IMF = NULL;

        cout << "Deseja executar novamente?" << endl;
        cin >> next;
    }while(next == 'S' || next == 's');
    return 0;
}
