#include <iostream>
#include "Fibo.h"

using namespace std;

int main()
{
    Fibo I, T, *Pilha = nullptr, *Fila = nullptr, *FilaI = nullptr;
    char resposta;
    int num;
    int num1, num2, num3;
    cout << "Seja bem-vindo!" << endl;
    do {
        cout << "Insira um número maior que 3:" << endl;
        cin >> num;
        while(num <= 3) {
            cout << "insira um número maior que 3:" << endl;
            cin >> num;
        }
        num1 = 1;
        num2 = 1;
        for(int i = 2; i < num; i++){
            if (i == 2) {
                Pilha = T.InserirPilha(Pilha, 1);
                Pilha = T.InserirPilha(Pilha, 1);
                Fila = I.InserirFila(Fila, 1);
                FilaI = Fila;
                Fila = I.InserirFila(Fila, 1);
            }
            num3 = num1 + num2;
            Pilha = T.InserirPilha(Pilha, num3);
            Fila = I.InserirFila(Fila, num3);
            num1 = num2;
            num2 = num3;
        }
        cout << "Fila: ";
        Fila->PercorrerFila(FilaI);
        cout << "Pilha: ";
        Pilha->PercorrerPilha(Pilha);

        Fila = I.EsvaziarFila(FilaI);
        FilaI = Fila;
        Pilha = T.EsvaziarPilha(Pilha);

        cout << "\nDeseja rodar de novo? (S/N)" << endl;
        cin >> resposta;
    } while(resposta == 'S' || resposta == 's');
    return 0;
}
