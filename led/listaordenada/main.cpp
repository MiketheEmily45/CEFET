#include "Lista.h"

using namespace std;

void Menu(){
    system("clear");
    cout << "1 - Inserir\n";
    cout << "2 - Excluir\n";
    cout << "3 - Listar\n";
    cout << "4 - Fim\n";
    cout << "Escolha: ";
}

int main()
{
    Lista O, **L, *resp;
    L = new Lista*[2];
    L[0] = L[1] = NULL;
    int op, acesso;
    string url;
    do{
        Menu();
        cin >> op;
        switch(op){
            case 1:
                cout << "Informe a URL: ";
                cin >> url;
                resp = O.Procurar(L[0], url);
                if(resp == NULL){
                    L = O.Inserir(L, url, 1);
                    cout << "Nova URL cadastrada!\n";
                }else{
                    acesso = resp->Acessos + 1;
                    L = O.Excluir(L, url);
                    L = O.Inserir(L, url, acesso);
                    cout << "Acessos atualizado!\n";
                }
                break;
            case 2:
                if(L[0] == NULL){
                    cout << "Ninguem cadastrado!\n";
                }else{
                    cout << "Informe a URL: ";
                    cin >> url;
                    resp = O.Procurar(L[0], url);
                    if(resp != NULL){
                        L = O.Excluir(L, url);
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
                cout << "tchau!!\n";
                break;
            default:
                cout << "inválido\n";
        }
        cin.ignore().get();
    }while(op != 4);







    return 0;
}
