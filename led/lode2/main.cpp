#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    cout << "Seja bem vindo!" << endl;
    bool sair = false;
    char tipo;
    string nome;
    int idade, opcao;
    lista O, **L;
    L = new lista*[2];
    L[0] = L[1] = NULL;
    do {
        cout << "1- Inserir alguém na lista\n2-Excluir alguém na lista por tipo\n3-Listar\n4-Finalizar programa" << endl;
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "Insira o nome:" << endl;
                cin >> nome;
                cout << "Insra a idade:" << endl;
                cin >> idade;
                O.Inserir(L, nome, idade);
                break;
            case 2:
                cout << "P - preferencial\nC - comum\nInsira o tipo:" << endl;
                cin >> tipo;
                break;
            case 3:
                if(L[0] == NULL){
                    cout << "Ninguem cadastrado!\n";
                }else{
                    cout << "Listagem\n";
                    O.Listar(L[0]);
                }
                break;
            case 4:
                sair = true;
                cout << "tchau!" << endl;
                break;
            default:
                cout << "Inválido" << endl;
        }
    } while(!sair);
    return 0;
}
