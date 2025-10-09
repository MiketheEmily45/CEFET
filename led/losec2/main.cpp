#include <time.h>
#include <stdlib.h>
#include "losec.h"
#include <iostream>

using namespace std;

int main()
{
    int opcao, num;
    losec **R, L, *Resp;
    R = new losec*[2];
    R[0] = R[1] = NULL;
    //Tem que fazer com que um número aleatório seja cadastrado de 0-100, e caso se repita, acrescentar no qtd;
    cout << "Bem-vindo!" << endl;
    do {
        cout << "Menu:\n1-Pesquisar\n2-Exibir Números\n3-Excluir Números\n4-Sair" << endl;
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Insira o número:" << endl;
                cin >> num;
                Resp = L.Pesquisar(R, num);
            case 2:
                L.Exibir(R);
                break;
            case 3:
                cout << "Insira o número:" << endl;
                cin >> num;
                R = L.Excluir(R, num);
            case 4:
                break;
            default:
                cout << "Erro: Opção inválida!" << endl;
        }
    }while (opcao != 4);
    cout << "tchau!" << endl;
    return 0;
}
