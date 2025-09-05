#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    cout << "Lista Duplamente Encadeada - Pets\n";
    lista O, **L, *resp;
    L = new lista*[2];
    L[0] = L[1] = NULL;
    int op, tipo, idade;
    string nome, raca;
    do{
        cout << "1 - Inserir\n";
        cout << "2 - Excluir\n";
        cout << "3 - Listar\n";
        cout << "4 - Listar Cachorros\n";
        cout << "5 - Listar Gatos\n";
        cout << "6 - Procurar\n";
        cout << "7 - Fim\n";
        cout << "Escolha: ";
        cin >> op;
        switch(op){
            case 1:
                cout << "Informe o nome do pet: ";
                cin >> nome;
                cout << "Informe a raça: ";
                cin >> raca;
                cout << "Informe a idade: ";
                cin >> idade;
                cout << "Informe o tipo (1-Cachorro / 2-Gato): ";
                cin >> tipo;
                resp = O.Procurar(L[0], nome, tipo);
                if(resp == NULL){
                    L = O.Inserir(L, nome, idade, tipo, raca);
                    cout << "Novo pet cadastrado!\n";
                }else{
                    cout << "Pet já cadastrado!\n";
                }
                break;
            case 2:
                if(L[0] == NULL){
                    cout << "Ninguem cadastrado!\n";
                }else{
                    cout << "Informe o nome do pet: ";
                    cin >> nome;
                    cout << "Informe o tipo (1-Cachorro / 2-Gato): ";
                    cin >> tipo;
                    resp = O.Procurar(L[0], nome, tipo);
                    if(resp != NULL){
                        L = O.Excluir(L, nome, tipo);
                        cout << "Excluido!\n";
                    }else{
                        cout << "Não existe!\n";
                    }
                }
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
                if(L[0] == NULL){
                    cout << "Ninguem cadastrado!\n";
                }else{
                    cout << "Listagem de Cachorros\n";
                    O.Listar_cachorros(L[0]);
                }
                break;
            case 5:
                if(L[0] == NULL){
                    cout << "Ninguem cadastrado!\n";
                }else{
                    cout << "Listagem de Gatos\n";
                    O.Listar_gatos(L[0]);
                }
                break;
            case 6:
                if(L[0] == NULL){
                    cout << "Ninguem cadastrado!\n";
                }else{
                    cout << "Informe o nome do pet: ";
                    cin >> nome;
                    cout << "Informe o tipo (1-Cachorro / 2-Gato): ";
                    cin >> tipo;
                    resp = O.Procurar(L[0], nome, tipo);
                    if(resp != NULL){
                        cout << "Pet encontrado: " << resp->nome_do_pet << " - " << resp->raca << " - " << resp->idade << " - ";
                        if(resp->tipo == 1) cout << "Cachorro\n";
                        else if(resp->tipo == 2) cout << "Gato\n";
                    }else{
                        cout << "Não existe!\n";
                    }
                }
                break;
            case 7:
                cout << "tchau!!\n";
                break;
            default:
                cout << "inválido\n";
        }
        cin.ignore().get();
    } while (op != 7);
    
    return 0;
}